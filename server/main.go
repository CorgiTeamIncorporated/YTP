//+build !test

package main

import (
	"net/http"
)

// main starts the execution.
func main() {
	if err := InitFlags(); err != nil {
		LogFatal(err)
	}

	if err := InitSystem(); err != nil {
		LogFatal(err)
	}

	if err := InitConfig(); err != nil {
		LogFatal(err)
	}

	if err := InitLog(); err != nil {
		LogFatal(err)
	}

	if err := InitServer(); err != nil {
		LogFatal(err)
	}

	LogPrint("Starting the server...")

	StartServer()
}

// StartServer starts the server.
func StartServer() {
	if ConfigInstance.TLSEnabled {
		go StartServerNonTLS()

		StartServerTLS()

		return
	}

	if err := Server.ListenAndServe(); err != nil && err != http.ErrServerClosed {
		LogFatal(err)
	}
}

// StartServerNonTLS starts the Non-TLS server when TLS is enabled.
func StartServerNonTLS() {
	if err := NonTLSServer.ListenAndServe(); err != nil && err != http.ErrServerClosed {
		LogFatal(err)
	}
}

// StartServerTLS starts the TLS server when TLS is enabled.
func StartServerTLS() {
	if err := Server.ListenAndServeTLS(ConfigInstance.TLSCertificate, ConfigInstance.TLSKey); err != nil && err != http.ErrServerClosed {
		LogFatal(err)
	}
}
