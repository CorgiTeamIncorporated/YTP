package main

import (
	"bytes"
	"html/template"
	"net/http"
	"net/http/httptest"
	"path"
	"testing"
)

// TestHTTPErrorHandler tests the HTTPErrorHandler serving process.
func TestHTTPErrorHandler(t *testing.T) {
	for _, code := range []int{http.StatusForbidden, http.StatusInternalServerError, http.StatusNotFound} {
		var resp bytes.Buffer

		rec := httptest.NewRecorder()

		HTTPErrorHandler(rec, code)

		tpl, err := template.ParseFiles(path.Join("templates", "layout.html"), path.Join("templates", "error.html"))

		if err != nil {
			t.Fatal(err)
		}

		if err := tpl.Execute(&resp, map[string]interface{}{"code": code}); err != nil {
			t.Fatal(err)
		}

		if rec.Code != code {
			t.Errorf("ErrorHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, code)
		}

		if exp := resp.String(); rec.Body.String() != exp {
			t.Errorf("ErrorHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Body.String() %v, want %v.", rec.Body.String(), exp)
		}
	}
}

// TestHTTPErrorHandlerTemplateExecuteError tests the ErrorHandler serving process when the TemplateExecute error occurs.
func TestHTTPErrorHTTPHandlerTemplateExecuteError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	TemplateExecute = TemplateExecuteError

	for _, code := range []int{http.StatusForbidden, http.StatusInternalServerError, http.StatusNotFound} {
		rec := httptest.NewRecorder()

		HTTPErrorHandler(rec, code)

		if rec.Code != code {
			t.Errorf("ErrorHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, code)
		}

		if rec.Body.String() != "" {
			t.Errorf("ErrorHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Body.String() %v, want %v.", rec.Body.String(), "")
		}
	}
}

// TestHTTPErrorHandlerTemplateParseFilesError tests the ErrorHandler serving process when the TemplateParseFiles error occurs.
func TestHTTPErrorHTTPHandlerTemplateParseFilesError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	TemplateParseFiles = TemplateParseFilesError

	for _, code := range []int{http.StatusForbidden, http.StatusInternalServerError, http.StatusNotFound} {
		rec := httptest.NewRecorder()

		HTTPErrorHandler(rec, code)

		if rec.Code != http.StatusInternalServerError {
			t.Errorf("ErrorHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Code %v, want %v.", rec.Code, http.StatusInternalServerError)
		}

		if rec.Body.String() != "" {
			t.Errorf("ErrorHandler(http.ResponseWriter, *http.Request): got http.ResponseWriter.Body.String() %v, want %v.", rec.Body.String(), "")
		}
	}
}
