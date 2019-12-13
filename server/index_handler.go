package main

import (
	"net/http"
	"path"
)

// IndexHandler serves index page requests.
func IndexHandler(w http.ResponseWriter, r *http.Request) {
	tpl, err := TemplateParseFiles(path.Join("templates", "layout.html"), path.Join("templates", "index.html"))

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	err = TemplateExecute(tpl, w, nil)

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}
}
