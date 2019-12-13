package main

import (
	"strconv"
	"testing"
	"time"
)

// TestGetRouter tests whether GetRouter gets a proper router.
func TestGetRouter(t *testing.T) {
	GetRouter()
}

// TestGetServer tests whether GetServer gets a proper server.
func TestGetServer(t *testing.T) {
	srv := GetServer(GetRouter(), ConfigInstance.Port)

	if addr := ConfigInstance.Host + ":" + strconv.Itoa(ConfigInstance.Port); srv.Addr != addr {
		t.Errorf("GetServer()[0]: got [0].Addr %v, want %v.", srv.Addr, addr)
	}

	if tout := time.Duration(ConfigInstance.IdleTimeout) * time.Second; srv.IdleTimeout != tout {
		t.Errorf("GetServer()[0]: got [0].IdleTimeout %v, want %v.", srv.IdleTimeout, tout)
	}

	if srv.MaxHeaderBytes != ConfigInstance.MaxHeaderBytes {
		t.Errorf("GetServer()[0]: got [0].MaxHeaderBytes %v, want %v.", srv.MaxHeaderBytes, ConfigInstance.MaxHeaderBytes)
	}

	if tout := time.Duration(ConfigInstance.ReadTimeout) * time.Second; srv.ReadTimeout != tout {
		t.Errorf("GetServer()[0]: got [0].ReadTimeout %v, want %v.", srv.ReadTimeout, t)
	}

	if tout := time.Duration(ConfigInstance.ReadHeaderTimeout) * time.Second; srv.ReadHeaderTimeout != tout {
		t.Errorf("GetServer()[0]: got [0].ReadHeaderTimeout %v, want %v.", srv.ReadHeaderTimeout, tout)
	}

	if tout := time.Duration(ConfigInstance.WriteTimeout) * time.Second; srv.WriteTimeout != tout {
		t.Errorf("GetServer()[0]: got [0].WriteTimeout %v, want %v.", srv.WriteTimeout, tout)
	}
}

// TestInitServer tests the server initialization.
func TestInitServer(t *testing.T) {
	if err := InitServer(); err != nil {
		t.Errorf("InitServer()[0]: got the error: %v", err.Error())
	}
}

// TestInitServerTLS tests the server initialization when TLS is enabled.
func TestInitServerTLS(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	ConfigInstance.TLSEnabled = true

	if err := InitServer(); err != nil {
		t.Errorf("InitServer()[0]: got the error: %v", err.Error())
	}
}

// TestInitServerURLError tests the server initialization when the URL error has occured.
func TestInitServerURLError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	URLParse = URLParseError

	if err := InitServer(); err == nil {
		t.Errorf("InitServer()[0]: want the error.")
	}
}
