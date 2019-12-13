package main

import (
	"net/http"
	"path"
)

// IndexHandler serves index page requests.
func IndexHandler(w http.ResponseWriter, r *http.Request) {
	session, err := RediStore.Get(r, "ydc")

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	_, authenticated := session.Values["user_id"]

	if v, ok := session.Values["game_key"]; ok && authenticated && v != "" && len(v.(string)) < 129 {
		_, err = DataBase.Query("UPDATE users SET game_key = ? WHERE id = ?", v, session.Values["user_id"])

		if err != nil {
			LogPrint(err)

			HTTPErrorHandler(w, http.StatusInternalServerError)

			return
		}

		delete(session.Values, "game_key")

		if err := session.Save(r, w); err != nil {
			LogPrint(err)

			HTTPErrorHandler(w, http.StatusInternalServerError)

			return
		}
	}

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
