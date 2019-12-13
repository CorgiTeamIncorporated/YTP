package main

import (
	"net/http"
)

// LogoutHandler serves logout page requests.
func LogoutHandler(w http.ResponseWriter, r *http.Request) {
	session, err := RediStore.Get(r, "ydc")

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	uri, err := URLParse("/")

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	if _, ok := session.Values["user_id"]; ok {
		session.Options.MaxAge = -1

		if err := session.Save(r, w); err != nil {
			LogPrint(err)

			HTTPErrorHandler(w, http.StatusInternalServerError)

			return
		}
	}

	http.Redirect(w, r, ParsedDomain.ResolveReference(uri).String(), http.StatusSeeOther)
}
