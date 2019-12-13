package main

import (
	"net/http"
	"net/http/httptest"
	"testing"
)

// TestNonTLSHandlerServeHTTP tests the NonTLSHandler.ServeHTTP serving process.
func TestNonTLSHandlerServeHTTP(t *testing.T) {
	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	if ParsedDomain == nil {
		InitServer()
	}

	NonTLSHandler{}.ServeHTTP(rec, r)

	if err != nil {
		t.Fatal(err)
	}

	if rec.Code != http.StatusSeeOther {
		t.Errorf("NonTLSHandler.ServeHTTP(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusOK)
	}
}

// TestNonTLSHandlerServeHTTPURLParseError tests the NonTLSHandler.ServeHTTP serving process when the URLParse error occurs.
func TestNonTLSHandlerServeHTTPURLParseError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	URLParse = URLParseError

	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	NonTLSHandler{}.ServeHTTP(rec, r)

	if rec.Code != http.StatusInternalServerError {
		t.Errorf("NonTLSHandler.ServeHTTP(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusInternalServerError)
	}
}
