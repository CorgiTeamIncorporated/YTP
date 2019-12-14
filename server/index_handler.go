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

	login := ""

	var score uint64 = 0

	if authenticated {
		err = DataBase.QueryRow("SELECT login, score FROM users WHERE id = ? LIMIT 1", session.Values["user_id"]).Scan(&login, &score)

		if err != nil {
			LogPrint(err)

			HTTPErrorHandler(w, http.StatusInternalServerError)

			return
		}
	}

	topLogins := []string{}

	topScores := []uint64{}

	rs, err := DataBase.Query("SELECT login, score FROM users ORDER BY score DESC LIMIT 10")

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	for rs.Next() {
		lgn := ""

		var scr uint64 = 0

		if err := rs.Scan(&lgn, &scr); err != nil {
			LogPrint(err)

			HTTPErrorHandler(w, http.StatusInternalServerError)

			return
		}

		topLogins = append(topLogins, lgn)

		topScores = append(topScores, scr)
	}

	rs.Close()

	err = TemplateExecute(tpl, w, map[string]interface{}{
		"logged_in": authenticated,

		"login": login,

		"score": score,

		"top_logins": topLogins,

		"top_scores": topScores,
	})

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}
}
