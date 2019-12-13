package main

import (
	"net/http"
	"net/http/httptest"
	"testing"
)

// TestSignupHandler tests the SignupHandler serving process.
func TestSignupHandler(t *testing.T) {
	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	SignupHandler(rec, r)

	if rec.Code != http.StatusOK {
		t.Errorf("SignupHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusOK)
	}
}

// TestSignupHandlerTemplateExecuteError tests the SignupHandler serving process when the TemplateExecute error occurs.
func TestSignupHandlerTemplateExecuteError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	TemplateExecute = TemplateExecuteError

	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	SignupHandler(rec, r)

	if rec.Code != http.StatusInternalServerError {
		t.Errorf("SignupHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusInternalServerError)
	}
}

// TestSignupHandlerTemplateParseFilesError tests the SignupHandler serving process when the TemplateParseFiles error occurs.
func TestSignupHandlerTemplateParseFilesError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	TemplateParseFiles = TemplateParseFilesError

	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	SignupHandler(rec, r)

	if rec.Code != http.StatusInternalServerError {
		t.Errorf("SignupHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusInternalServerError)
	}
}
