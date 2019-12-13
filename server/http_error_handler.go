package main

import (
	"net/http"
	"path"
)

// HTTPForbiddenErrorHandler handles the HTTP Forbidden error.
func HTTPForbiddenErrorHandler(w http.ResponseWriter, _ *http.Request) {
	HTTPErrorHandler(w, http.StatusForbidden)
}

// HTTPNotFoundErrorHandler handles the HTTP Not Found error.
func HTTPNotFoundErrorHandler(w http.ResponseWriter, _ *http.Request) {
	HTTPErrorHandler(w, http.StatusNotFound)
}

// HTTPErrorHandler handles the HTTP errors (acts as the internal server error page).
func HTTPErrorHandler(w http.ResponseWriter, code int) {
	if code == http.StatusInternalServerError {
		w.WriteHeader(code)
	}

	tpl, err := TemplateParseFiles(path.Join("templates", "layout.html"), path.Join("templates", "error.html"))

	if err != nil {
		LogPrint(err)

		if code == http.StatusInternalServerError {
			return
		}

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	if code != http.StatusInternalServerError {
		w.WriteHeader(code)
	}

	err = TemplateExecute(tpl, w, map[string]interface{}{
		"code": code,
	})

	if err != nil {
		LogPrint(err)

		return
	}
}
