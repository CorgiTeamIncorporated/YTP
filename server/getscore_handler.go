package main

import (
	"database/sql"
	"net/http"
	"strconv"
)

// GetScoreHandler serves API score page requests.
func GetScoreHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "text/plain;charset=utf-8")

	w.Header().Set("X-Content-Type-Options", "nosniff")

	var id uint64

	formKey := r.FormValue("k")

	if formKey == "" {
		_, err := w.Write([]byte("err nil"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	err := DataBase.QueryRow("SELECT id FROM users WHERE game_key = ? LIMIT 1", formKey).Scan(&id)

	if err == sql.ErrNoRows {
		_, err := w.Write([]byte("err nil"))

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

	var gotID uint64

	err = DataBase.QueryRow("SELECT score FROM users WHERE id = ?", id).Scan(&gotID)

	if err != nil {
		LogPrint(err)

		_, err = w.Write([]byte("err 500"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	_, err = w.Write([]byte(strconv.FormatUint(gotID, 10)))

	if err != nil {
		LogPrint(err)
	}
}
