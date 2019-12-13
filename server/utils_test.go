package main

import (
	"io/ioutil"
	"os"
	"testing"
)

// TestExistsError tests Exists in the case of an error.
func TestExistsError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	OSStat = OSStatError

	_, err := Exists("")

	if err == nil {
		t.Errorf("Exists()[1]: want the error.")
	}
}

// TestExistsExistingDir tests Exists in the case of an existing directory.
func TestExistsExistingDir(t *testing.T) {
	dir, err := ioutil.TempDir("", CommonName)

	if err != nil {
		t.Fatal(err)
	}

	defer func() {
		if err = os.Remove(dir); err != nil {
			t.Fatal(err)
		}
	}()

	exists, err := Exists(dir)

	if err != nil {
		t.Errorf("Exists()[1]: got the error: %v", err.Error())
	}

	if !exists {
		t.Errorf("Exists()[0]: got %v, want %v.", exists, true)
	}
}

// TestExistsExistingFile tests Exists in the case of an existing file.
func TestExistsExistingFile(t *testing.T) {
	file, err := ioutil.TempFile("", CommonName)

	if err != nil {
		t.Fatal(err)
	}

	defer func() {
		if err = os.Remove(file.Name()); err != nil {
			t.Fatal(err)
		}
	}()

	exists, err := Exists(file.Name())

	if err != nil {
		t.Errorf("Exists()[1]: got the error: %v", err.Error())
	}

	if !exists {
		t.Errorf("Exists()[0]: got %v, want %v.", exists, true)
	}

	if err = file.Close(); err != nil {
		t.Fatal(err)
	}
}

// TestExistsNonExistingDir tests Exists in the case of a non-existing directory.
func TestExistsNonExistingDir(t *testing.T) {
	name, err := HelpTestGetTempDirName("", CommonName)

	if err != nil {
		t.Fatal(err)
	}

	exists, err := Exists(name)

	if err != nil {
		t.Errorf("Exists()[1]: got the error: %v", err.Error())
	}

	if exists {
		t.Errorf("Exists()[0]: got %v, want %v.", exists, false)
	}
}

// TestExistsNonExistingFile tests Exists in the case of a non-existing file.
func TestExistsNonExistingFile(t *testing.T) {
	name, err := HelpTestGetTempFileName("", CommonName)

	if err != nil {
		t.Fatal(err)
	}

	exists, err := Exists(name)

	if err != nil {
		t.Errorf("Exists()[1]: got the error: %v", err.Error())
	}

	if exists {
		t.Errorf("Exists()[0]: got %v, want %v.", exists, false)
	}
}
