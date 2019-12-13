package main

import (
	"os"
)

// Exists checks whether a file or directory with a given name exists.
func Exists(name string) (bool, error) {
	_, err := OSStat(name)

	if os.IsNotExist(err) {
		return false, nil
	}

	return err == nil, err
}
