package main

import (
	"io/ioutil"
	"os"
	"testing"
)

// HelpTestGetTempDirName gets the unique name for the temporary directory (see ioutil.TempDir for the name choise).
func HelpTestGetTempDirName(dir, prefix string) (string, error) {
	tmp, err := ioutil.TempDir(dir, prefix)

	if err != nil {
		return "", err
	}

	if err := os.Remove(tmp); err != nil {
		return "", err
	}

	return tmp, nil
}

// HelpTestGetTempFileName gets the unique name for the temporary file (see ioutil.TempFile for the name choise).
func HelpTestGetTempFileName(dir, prefix string) (string, error) {
	tmp, err := ioutil.TempFile(dir, prefix)

	if err != nil {
		return "", err
	}

	if err := tmp.Close(); err != nil {
		return "", err
	}

	if err := os.Remove(tmp.Name()); err != nil {
		return "", err
	}

	return tmp.Name(), nil
}

// HelpTestMakeLogFile makes the logfile.
func HelpTestMakeLogFile(t *testing.T) string {
	var err error

	name, err := HelpTestGetTempFileName("", CommonName)

	if err != nil {
		t.Fatal(err)
	}

	if LogFile, err = os.OpenFile(name, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0666); err != nil {
		t.Fatal(err)
	}

	return name
}
