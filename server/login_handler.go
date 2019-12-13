package main

import (
	"database/sql"
	"net/http"
	"path"

	"golang.org/x/crypto/bcrypt"
)

// LoginHandler serves login page requests.
func LoginHandler(w http.ResponseWriter, r *http.Request) {
	errs := []string{}

	login := r.FormValue("login")

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
		http.Redirect(w, r, ParsedDomain.ResolveReference(uri).String(), http.StatusSeeOther)
	}

	if r.Method == http.MethodPost {
		if login == "" {
			errs = append(errs, "login_absent")
		}

		password := r.FormValue("password")

		if password == "" {
			errs = append(errs, "password_absent")
		} else {
			var hash string

			err = DataBase.QueryRow("SELECT password FROM users WHERE login = ? LIMIT 1", login).Scan(&hash)

			if err == sql.ErrNoRows {
				errs = append(errs, "login_failed")
			} else {
				if err != nil {
					LogPrint(err)

					HTTPErrorHandler(w, http.StatusInternalServerError)

					return
				}

				err = bcrypt.CompareHashAndPassword([]byte(hash), []byte(password))

				if err != nil {
					errs = append(errs, "login_failed")
				}
			}
		}

		if len(errs) == 0 {
			var id uint64

			err = DataBase.QueryRow("SELECT id FROM users WHERE login = ?", login).Scan(&id)

			if err != nil {
				LogPrint(err)

				HTTPErrorHandler(w, http.StatusInternalServerError)

				return
			}

			session.Values["user_id"] = id

			if err := session.Save(r, w); err != nil {
				LogPrint(err)

				HTTPErrorHandler(w, http.StatusInternalServerError)

				return
			}

			http.Redirect(w, r, ParsedDomain.ResolveReference(uri).String(), http.StatusSeeOther)

			return
		}
	}

	tpl, err := TemplateParseFiles(path.Join("templates", "layout.html"), path.Join("templates", "login.html"))

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	err = TemplateExecute(tpl, w, map[string]interface{}{
		"errs": errs,

		"login": login,
	})

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}
}
