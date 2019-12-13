package main

import (
	"database/sql"
	"net/http"
	"strconv"
)

// ScoreHandler serves API score page requests.
func ScoreHandler(w http.ResponseWriter, r *http.Request) {
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

	inInt, err := strconv.Atoi(r.FormValue("i"))

	if err != nil {
		_, err = w.Write([]byte("err scr"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	_, err = DataBase.Query("UPDATE users SET score = ? WHERE id = ?", inInt, id)

	if err != nil {
		LogPrint(err)

		_, err = w.Write([]byte("err 500"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	_, err = w.Write([]byte("ok"))

	if err != nil {
		LogPrint(err)
	}
}
