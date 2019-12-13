package main

import (
	"io/ioutil"
	"os"
	"testing"
)

// TestInitConfig tests the configuration initialization.
func TestInitConfig(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	file, err := ioutil.TempFile("", CommonName)

	if err != nil {
		t.Fatal(err)
	}

	defer func() {
		if err := os.Remove(file.Name()); err != nil {
			t.Fatal(err)
		}
	}()

	ConfigPathFlag = file.Name()

	if _, err := file.Write([]byte(`{"port": 7}`)); err != nil {
		t.Fatal(err)
	}

	if err := file.Close(); err != nil {
		t.Fatal(err)
	}

	if err := InitConfig(); err != nil {
		t.Errorf("InitConfig()[0]: got the error: %v", err.Error())
	}

	if ConfigInstance.Port != 7 {
		t.Errorf("InitConfig(): got Config.Port %v, want %v.", ConfigInstance.Port, 7)
	}
}

// TestInitConfigIOUtilReadFileError tests the configuration initialization when the IOUtilReadFile error occurs.
func TestInitConfigIOUtilReadFileError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	ConfigPathFlag = "/"

	IOUtilReadFile = IOUtilReadFileError

	if err := InitConfig(); err == nil {
		t.Errorf("InitConfig()[0]: want the error.")
	}
}

// TestInitConfigJSONUnmarshalError tests the configuration initialization when the JSONUnmarshal error occurs.
func TestInitConfigJSONUnmarshalError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	ConfigPathFlag = "/"

	IOUtilReadFile = IOUtilReadFileNull

	JSONUnmarshal = JSONUnmarshalError

	if err := InitConfig(); err == nil {
		t.Errorf("InitConfig()[0]: want the JSON error.")
	}
}

// TestInitConfigConfigPathFlagEmpty tests the configuration initialization when the configuration path is empty.
func TestInitConfigConfigPathFlagEmpty(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	ConfigPathFlag = ""

	if err := InitConfig(); err != nil {
		t.Errorf("InitConfig()[0]: got the error: %v", err.Error())
	}
}
