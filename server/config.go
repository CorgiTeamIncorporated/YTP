package main

// CommonName is the common name (prefix, ...) for the server-related things.
const CommonName = "YDC_SERVER"

// HTTPScheme is the HTTP scheme.
const HTTPScheme = "http"

// HTTPSScheme is the HTTPS scheme.
const HTTPSScheme = "https"

// MaxLoginLength is the maximal login form value length.
const MaxLoginLength = 128

// MinLoginLength is the minimal login form value length.
const MinLoginLength = 5

// MaxPasswordLength is the maximal password form value length.
const MaxPasswordLength = 71

// MinPasswordLength is the minimal password form value length.
const MinPasswordLength = 8

// ConfigInstance is the configuration instance.
var ConfigInstance = Config{
	CSRFKey: "32-byte-long-auth-key",

	Domain: "localhost",

	Host: "localhost",

	IdleTimeout: 5,

	LogPath: "",

	MaxHeaderBytes: 1 << 8,

	MySQLConnStr: "mysql:@/ydc",

	Port: 3001,

	PortFake: 3001,

	ReadTimeout: 5,

	ReadHeaderTimeout: 5,

	RedisAddress: ":6379",

	RedisPassword: "",

	SessionKey: "secret",

	TLSCertificate: "",

	TLSEnabled: false,

	TLSFake: false,

	TLSKey: "",

	TLSPort: 443,

	WriteTimeout: 10,
}

// Config is the configuration type.
type Config struct {
	CSRFKey string `json:"csrf_key"`

	// Config.Domain is the domain name used by the server. IP address may be also used here.
	Domain string `json:"domain"`

	// Config.IdleTimeout is the timeout of waiting for a next request when Keep-Alive is enabled in seconds.
	IdleTimeout int64 `json:"idle_timeout"`

	// Config.Host is the host address to bind the server to.
	Host string `json:"host"`

	// Config.LogPath is the log file path. It is empty if no log file is being used.
	LogPath string `json:"log_path"`

	// Config.MaxHeaderBytes is the maximum amount of bytes the server will read from a request header.
	MaxHeaderBytes int `json:"max_header_bytes"`

	// Config.MySQLConnStr is the connection string used by MySQL driver to connect to the database.
	MySQLConnStr string `json:"mysql_conn_str"`

	// Config.Port is the port to bind the server to.
	Port int `json:"port"`

	PortFake int `json:"port_fake"`

	// Config.ReadTimeout is the timeout of reading a request in seconds.
	ReadTimeout int64 `json:"read_timeout"`

	// Config.ReadHeaderTimeout is the timeout of reading request headers in seconds.
	ReadHeaderTimeout int64 `json:"read_header_timeout"`

	// Config.RedisAddress is the address used to connect to Redis.
	RedisAddress string `json:"redis_address"`

	// Config.RedisPassword is the password used to connect to Redis.
	RedisPassword string `json:"redis_password"`

	// Config.SessionKey is the secret session key.
	SessionKey string `json:"session_key"`

	// Config.TLSCertificate is the path to the TLS certificate.
	TLSCertificate string `json:"tls_certificate"`

	// Config.TLSEnabled is whether TLS is enabled.
	TLSEnabled bool `json:"tls_enabled"`

	TLSFake bool `json:"tls_fake"`

	// Config.TLSKey is the path to the TLS key.
	TLSKey string `json:"tls_key"`

	// Config.TLSPort is the TLS port to bind the server to.
	TLSPort int `json:"tls_port"`

	// Config.WriteTimeout is the timeout of writing a response in seconds.
	WriteTimeout int64 `json:"write_timeout"`
}

// InitConfig initializes the configuration.
func InitConfig() error {
	if ConfigPathFlag == "" {
		return nil
	}

	cfg, err := IOUtilReadFile(ConfigPathFlag)

	if err != nil {
		return err
	}

	if err := JSONUnmarshal(cfg, &ConfigInstance); err != nil {
		return err
	}

	return nil
}
