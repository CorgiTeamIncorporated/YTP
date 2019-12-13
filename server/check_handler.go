package main

import (
	"database/sql"
	"net/http"
)

// CheckHandler serves API key checking page requests.
func CheckHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "text/plain;charset=utf-8")

	w.Header().Set("X-Content-Type-Options", "nosniff")

	formKey := r.FormValue("k")

	if formKey == "" {
		_, err := w.Write([]byte("no"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	var null interface{}

	err := DataBase.QueryRow("SELECT null FROM users WHERE game_key = ? LIMIT 1", formKey).Scan(&null)

	if err == sql.ErrNoRows {
		_, err := w.Write([]byte("no"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	if err != nil {
		LogPrint(err)

		_, err = w.Write([]byte("err 500"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	if _, err := w.Write([]byte("ok")); err != nil {
		LogPrint(err)
	}
}
