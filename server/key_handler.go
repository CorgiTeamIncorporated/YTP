package main

import (
	"crypto/rand"
	"encoding/hex"
	"net/http"
)

// KeyHandler serves API key generation page requests.
func KeyHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "text/plain;charset=utf-8")

	w.Header().Set("X-Content-Type-Options", "nosniff")

	bytes := make([]byte, 64)

	if _, err := rand.Read(bytes); err != nil {
		LogPrint(err)

		_, err = w.Write([]byte("err 500"))

		if err != nil {
			LogPrint(err)
		}

		return
	}

	if _, err := w.Write([]byte(hex.EncodeToString(bytes))); err != nil {
		LogPrint(err)
	}
}
