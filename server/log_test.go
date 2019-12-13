package main

import (
	"io/ioutil"
	"log"
	"os"
	"testing"
)

// TestInitLog tests the logger initialization.
func TestInitLog(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	ConfigInstance.LogPath = ""

	LogFile = nil

	if err := InitLog(); err != nil {
		t.Errorf("InitLog()[0]: got the error: %v", err.Error())
	}

	if log.Flags() != LogFlags {
		t.Errorf("InitLog(): got log.Flags() %#v, want %#v.", log.Flags(), LogFlags)
	}
}

// TestInitLogConfigInstanceLogPath tests the logger initialization when ConfigInstance.LogPath was specified.
func TestInitLogConfigInstanceLogPath(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	name, err := HelpTestGetTempFileName("", CommonName)

	if err != nil {
		t.Fatal(err)
	}

	defer func() {
		if err := os.Remove(name); err != nil {
			t.Fatal(err)
		}
	}()

	ConfigInstance.LogPath = name

	if err := InitLog(); err != nil {
		t.Errorf("InitLog()[0]: got the error: %v", err.Error())
	}

	log.Print("CANNOT_MUTE_THIS")

	if err := LogFile.Close(); err != nil {
		t.Fatal(err)
	}

	log.SetOutput(os.Stdout)

	content, err := ioutil.ReadFile(name)

	if err != nil {
		t.Fatal(err)
	}

	if len(content) == 0 {
		t.Errorf("InitLog(): got len(content) %v, want a greater value.", 0)
	}
}

// TestInitLogConfigInstanceLogPathError tests the logger initialization when ConfigInstance.LogPath was specified, but causes the error.
func TestInitLogConfigInstanceLogPathError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	ConfigInstance.LogPath = "/"

	if err := InitLog(); err == nil {
		t.Errorf("InitLog()[0]: want the error.")
	}
}

// TestInitLogNoConfigInstanceLogPath tests the logger initialization when no ConfigInstance.LogPath was specified.
func TestInitLogNoConfigInstanceLogPath(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	ConfigInstance.LogPath = ""

	LogFile = nil

	if err := InitLog(); err != nil {
		t.Errorf("InitLog()[0]: got the error: %v", err.Error())
	}

	if LogFile != nil {
		t.Errorf("InitLog(): got LogFile %#v, want %#v.", nil, LogFile)
	}
}
