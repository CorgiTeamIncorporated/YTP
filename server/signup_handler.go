package main

import (
	"database/sql"
	"net/http"
	"path"

	"github.com/gorilla/csrf"
	"golang.org/x/crypto/bcrypt"
)

// SignupHandler serves signup page requests.
func SignupHandler(w http.ResponseWriter, r *http.Request) {
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
		} else if len(login) < MinLoginLength {
			errs = append(errs, "login_too_short")
		} else if len(login) > MaxLoginLength {
			errs = append(errs, "login_too_long")
		} else {
			var null interface{}

			err := DataBase.QueryRow("SELECT null FROM users WHERE login = ? LIMIT 1", login).Scan(&null)

			if err == nil {
				errs = append(errs, "login_exists")
			}

			if err != nil && err != sql.ErrNoRows {
				LogPrint(err)

				HTTPErrorHandler(w, http.StatusInternalServerError)

				return
			}
		}

		password := r.FormValue("password")

		if password == "" {
			errs = append(errs, "password_absent")
		} else if len(password) < MinPasswordLength {
			errs = append(errs, "password_too_short")
		} else if len(password) > MaxPasswordLength {
			errs = append(errs, "password_too_long")
		}

		if len(errs) == 0 {
			hash, err := HashPwd(password)

			if err != nil {
				LogPrint(err)

				HTTPErrorHandler(w, http.StatusInternalServerError)

				return
			}

			var id uint64

			_, err = DataBase.Query("INSERT INTO users (login, password, score) VALUES (?, ?, 0)", login, hash)

			if err != nil {
				LogPrint(err)

				HTTPErrorHandler(w, http.StatusInternalServerError)

				return
			}

			err = DataBase.QueryRow("SELECT id FROM users WHERE login = ? LIMIT 1", login).Scan(&id)

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

	tpl, err := TemplateParseFiles(path.Join("templates", "layout.html"), path.Join("templates", "signup.html"))

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}

	err = TemplateExecute(tpl, w, map[string]interface{}{
		csrf.TemplateTag: csrf.TemplateField(r),

		"errs": errs,

		"login": login,
	})

	if err != nil {
		LogPrint(err)

		HTTPErrorHandler(w, http.StatusInternalServerError)

		return
	}
}

// HashPwd hashes the password.
func HashPwd(pwd string) (string, error) {
	hash, err := bcrypt.GenerateFromPassword([]byte(pwd), bcrypt.DefaultCost)

	if err != nil {
		return "", err
	}

	return string(hash), nil
}
