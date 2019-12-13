package main

import (
	"net/http"
)

// NonTLSHandler is the non-TLS request error server handler.
type NonTLSHandler struct {
	// http.Handler inherits the handler type.
	http.Handler
}

// NonTLSHandler.ServeHTTP serves the non-TLS request error.
func (h NonTLSHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	uri, err := URLParse(r.RequestURI)

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	http.Redirect(w, r, ParsedDomain.ResolveReference(uri).String(), http.StatusSeeOther)
}
