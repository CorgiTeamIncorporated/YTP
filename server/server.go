package main

import (
	"database/sql"
	"net/http"
	"net/url"
	"strconv"
	"strings"
	"time"

	_ "github.com/go-sql-driver/mysql"
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

// GetRouter gets a new main server router.
func GetRouter() *http.ServeMux {
	httpRT := http.NewServeMux()

	rt := mux.NewRouter()

	rt.StrictSlash(false)

	rt.HandleFunc("/", IndexHandler).Methods(http.MethodGet)

	rt.HandleFunc("/api/score", ScoreHandler).Methods(http.MethodGet, http.MethodPost)

	rt.HandleFunc("/api/key", KeyHandler).Methods(http.MethodGet, http.MethodPost)

	rt.HandleFunc("/login", LoginHandler).Methods(http.MethodGet, http.MethodPost)

	rt.HandleFunc("/logout", LogoutHandler).Methods(http.MethodGet, http.MethodPost)

	rt.HandleFunc("/signup", SignupHandler).Methods(http.MethodGet, http.MethodPost)

	rt.PathPrefix("/assets/").Handler(http.StripPrefix("/assets/", http.FileServer(http.Dir("assets"))))

	rt.NotFoundHandler = http.HandlerFunc(HTTPNotFoundErrorHandler)

	httpRT.Handle("/", rt)

	return httpRT
}

// TrimMiddleware trims trailing slashes from URIs.
func TrimMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		if r.URL.Path != "/" {
			r.URL.Path = strings.TrimSuffix(r.URL.Path, "/")
		}

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

	Server = GetServer(TrimMiddleware(GetRouter()), ConfigInstance.Port)

	if ConfigInstance.TLSFake {
		scheme = HTTPSScheme
	}

	if ConfigInstance.TLSEnabled {
		scheme = HTTPSScheme

		NonTLSServer = GetServer(NonTLSHandler{}, ConfigInstance.Port)

		Server = GetServer(TrimMiddleware(GetRouter()), ConfigInstance.TLSPort)
	}

	if ParsedDomain, err = URLParse(scheme + "://" + ConfigInstance.Domain); err != nil {
		return err
	}

	return nil
}
