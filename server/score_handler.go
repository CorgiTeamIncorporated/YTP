package main

import (
	"net/http"
	"strconv"
)

// ScoreHandler serves API score page requests.
func ScoreHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "text/plain;charset=utf-8")

	w.Header().Set("X-Content-Type-Options", "nosniff")

	session, err := RediStore.Get(r, "ydc")

	if err != nil {
		LogPrint(err)

		_, err = w.Write([]byte("err 500"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	if _, ok := session.Values["user_id"]; !ok {
		_, err := w.Write([]byte("err inv"))

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

	_, err = DataBase.Query("UPDATE users SET score = ? WHERE id = ?", inInt, session.Values["user_id"])

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
