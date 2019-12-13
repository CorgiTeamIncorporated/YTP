package main

import (
	"net/http"
	"net/http/httptest"
	"testing"
)

// TestIndexHandler tests the IndexHandler serving process.
func TestIndexHandler(t *testing.T) {
	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	IndexHandler(rec, r)

	if rec.Code != http.StatusOK {
		t.Errorf("IndexHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusOK)
	}
}

// TestIndexHandlerNotFoundError tests the IndexHandler serving process when the 404 error should occur.
func TestIndexHandlerNotFoundError(t *testing.T) {
	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/$i_do_not_exist$", nil)

	if err != nil {
		t.Fatal(err)
	}

	IndexHandler(rec, r)

	if rec.Code != http.StatusNotFound {
		t.Errorf("IndexHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusNotFound)
	}
}

// TestIndexHandlerTemplateExecuteError tests the IndexHandler serving process when the TemplateExecute error occurs.
func TestIndexHandlerTemplateExecuteError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	TemplateExecute = TemplateExecuteError

	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	IndexHandler(rec, r)

	if rec.Code != http.StatusInternalServerError {
		t.Errorf("IndexHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusInternalServerError)
	}
}

// TestIndexHandlerTemplateParseFilesError tests the IndexHandler serving process when the TemplateParseFiles error occurs.
func TestIndexHandlerTemplateParseFilesError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	TemplateParseFiles = TemplateParseFilesError

	rec := httptest.NewRecorder()

	r, err := http.NewRequest("GET", "/", nil)

	if err != nil {
		t.Fatal(err)
	}

	IndexHandler(rec, r)

	if rec.Code != http.StatusInternalServerError {
		t.Errorf("IndexHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusInternalServerError)
	}
}
