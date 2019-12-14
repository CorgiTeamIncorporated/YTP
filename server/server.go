package main

import (
	"database/sql"
	"net/http"
	"net/url"
	"path"
	"strconv"
	"strings"
	"time"

	_ "github.com/go-sql-driver/mysql"
	"github.com/gorilla/csrf"
	"github.com/gorilla/mux"
	"gopkg.in/boj/redistore.v1"
)

// DataBase is the MySQL database connection.
var DataBase *sql.DB

// NonTLSServer is the non-TLS requests server, if TLS is enabled.
var NonTLSServer *http.Server

// ParsedDomain is the parsed domain from the configuration.
var ParsedDomain *url.URL

// RediStore is the RediStore session storage.
var RediStore *redistore.RediStore

// Server is the main server instance.
var Server *http.Server

// FileHandler is the single static file handler type.
type FileHandler struct {
	Path string
}

// GetRouter gets a new main server router.
func GetRouter() *http.ServeMux {
	httpRT := http.NewServeMux()

	rt := mux.NewRouter()

	rt.StrictSlash(false)

	rt.Handle("/browserconfig.xml", FileHandler{"/browserconfig.xml"})
	rt.Handle("/crossdomain.xml", FileHandler{"/crossdomain.xml"})
	rt.Handle("/manifest.json", FileHandler{"/manifest.json"})
	rt.Handle("/sitemap.xml", FileHandler{"/sitemap.xml"})
	rt.Handle("/robots.txt", FileHandler{"/robots.txt"})

	rt.HandleFunc("/", IndexHandler).Methods(http.MethodGet)
	rt.HandleFunc("/api/getscore", GetScoreHandler).Methods(http.MethodGet, http.MethodPost)
	rt.HandleFunc("/api/score", ScoreHandler).Methods(http.MethodGet, http.MethodPost)
	rt.HandleFunc("/api/key", KeyHandler).Methods(http.MethodGet, http.MethodPost)
	rt.HandleFunc("/api/check", CheckHandler).Methods(http.MethodGet, http.MethodPost)
	rt.HandleFunc("/login", LoginHandler).Methods(http.MethodGet, http.MethodPost)
	rt.HandleFunc("/logout", LogoutHandler).Methods(http.MethodGet, http.MethodPost)
	rt.HandleFunc("/signup", SignupHandler).Methods(http.MethodGet, http.MethodPost)
	rt.PathPrefix("/assets/").Handler(http.StripPrefix("/assets/", FileServer(http.Dir("assets")))).Methods(http.MethodGet)

	rt.NotFoundHandler = http.HandlerFunc(HTTPNotFoundErrorHandler)

	httpRT.Handle("/", rt)

	return httpRT
}

// FileHandler.ServeHTTP serves the root static file.
func (f FileHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	http.ServeFile(w, r, path.Join("static", f.Path))
}

// FileServer serves the static files.
func FileServer(fs http.FileSystem) http.Handler {
	h := http.FileServer(fs)

	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		v, err := Exists(path.Join("assets", path.Clean(r.URL.Path)))

		if err != nil || !v {
			HTTPNotFoundErrorHandler(w, r)

			return
		}

		h.ServeHTTP(w, r)
	})
}

// TrimMiddleware trims trailing slashes from URIs.
func TrimMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		if r.URL.Path != "/" {
			r.URL.Path = strings.TrimSuffix(r.URL.Path, "/")
		}

		w.Header().Set("X-CSRF-Token", csrf.Token(r))

		next.ServeHTTP(w, r)
	})
}

// GetServer gets a new configured server instance.
func GetServer(handler http.Handler, port int) *http.Server {
	return &http.Server{
		Addr: ConfigInstance.Host + ":" + strconv.Itoa(port),

		Handler: handler,

		IdleTimeout: time.Duration(ConfigInstance.IdleTimeout) * time.Second,

		MaxHeaderBytes: ConfigInstance.MaxHeaderBytes,

		ReadTimeout: time.Duration(ConfigInstance.ReadTimeout) * time.Second,

		ReadHeaderTimeout: time.Duration(ConfigInstance.ReadHeaderTimeout) * time.Second,

		WriteTimeout: time.Duration(ConfigInstance.WriteTimeout) * time.Second,
	}
}

// InitServer initializes the server.
func InitServer() error {
	var err error

	if DataBase, err = sql.Open("mysql", ConfigInstance.MySQLConnStr); err != nil {
		return err
	}

	if RediStore, err = redistore.NewRediStore(10, "tcp", ConfigInstance.RedisAddress, ConfigInstance.RedisPassword, []byte(ConfigInstance.SessionKey)); err != nil {
		return err
	}

	scheme := HTTPScheme

	secure := true

	if !ConfigInstance.TLSEnabled && !ConfigInstance.TLSFake {
		secure = false
	}

	csrfMiddleware := csrf.Protect(
		[]byte(ConfigInstance.CSRFKey),
		csrf.SameSite(csrf.SameSiteStrictMode),
		csrf.CookieName("_csrf"),
		csrf.FieldName("csrf_token"),
		csrf.RequestHeader("CSRF-Token"),
		csrf.ErrorHandler(http.HandlerFunc(HTTPForbiddenErrorHandler)),
		csrf.Secure(secure),
	)

	Server = GetServer(csrfMiddleware(TrimMiddleware(GetRouter())), ConfigInstance.Port)

	if ConfigInstance.TLSFake {
		scheme = HTTPSScheme
	}

	if ConfigInstance.TLSEnabled {
		scheme = HTTPSScheme

		NonTLSServer = GetServer(NonTLSHandler{}, ConfigInstance.Port)

		Server = GetServer(csrfMiddleware(TrimMiddleware(GetRouter())), ConfigInstance.TLSPort)
	}

	if ParsedDomain, err = URLParse(scheme + "://" + ConfigInstance.Domain + ":" + strconv.Itoa(ConfigInstance.PortFake)); err != nil {
		return err
	}

	return nil
}
