package main

import (
	"os"
	"syscall"
	"testing"
)

// TestCleanUp tests the system clean up.
func TestCleanUp(t *testing.T) {
	var err error

	HelpTestCapture()

	defer HelpTestReset()

	name := HelpTestMakeLogFile(t)

	defer func() {
		if err = os.Remove(name); err != nil {
			t.Fatal(err)
		}
	}()

	if err = CleanUp(); err != nil {
		t.Errorf("CleanUp()[0]: got the error: %v", err.Error())
	}

	if err = LogFile.Close(); err == os.ErrClosed || err.(*os.PathError).Op == "close" {
		return
	}

	if err != nil {
		t.Fatal(err)
	}

	t.Errorf("CleanUp(): got LogFile.Close() %v, want %v.", err, os.ErrClosed)
}

// TestCleanUpNoLogFile tests the system clean up with the log file disabled.
func TestCleanUpNoLogFile(t *testing.T) {
	var err error

	HelpTestCapture()

	defer HelpTestReset()

	LogFile = nil

	if err = CleanUp(); err != nil {
		t.Errorf("InitLogger()[0]: got the error: %v", err.Error())
	}
}

// TestDoOnInterrupt tests when InterruptChannel is notified.
func TestDoOnInterrupt(t *testing.T) {
	var err error

	HelpTestCapture()

	defer HelpTestReset()

	LogFatal = func(args ...interface{}) {
		if len(args) > 0 {
			err = args[0].(error)
		}
	}

	OSExit = OSExitNull

	name := HelpTestMakeLogFile(t)

	defer func() {
		if err = os.Remove(name); err != nil {
			t.Fatal(err)
		}
	}()

	InterruptChannel <- syscall.SIGINT

	DoOnInterrupt()

	if err != nil {
		t.Errorf("DoOnInterrupt(): got the error: %v", err.Error())
	}
}

// TestDoOnInterruptCleanUpError tests when InterruptChannel is notified, but CleanUp throws an error.
func TestDoOnInterruptCleanUpError(t *testing.T) {
	var err error

	HelpTestCapture()

	defer HelpTestReset()

	LogFatal = func(args ...interface{}) {
		if len(args) > 0 {
			err = args[0].(error)
		}
	}

	OSExit = OSExitNull

	name := HelpTestMakeLogFile(t)

	defer func() {
		if err = os.Remove(name); err != nil {
			t.Fatal(err)
		}
	}()

	if err = LogFile.Close(); err != nil {
		t.Fatal(err)
	}

	InterruptChannel <- syscall.SIGINT

	DoOnInterrupt()

	if err == nil {
		t.Errorf("DoOnInterrupt(): want the error.")
	}

	if err != os.ErrClosed && err.(*os.PathError).Op != "close" {
		t.Errorf("DoOnInterrupt(): got the error: %v", err.Error())
	}
}

// TestDoOnInterruptError tests when InterruptChannel is notified and the shutdown error has occured.
func TestDoOnInterruptError(t *testing.T) {
	var err error

	HelpTestCapture()

	defer HelpTestReset()

	HTTPServerShutdown = HTTPServerShutdownError

	LogFatal = func(args ...interface{}) {
		if len(args) > 0 {
			err = args[0].(error)
		}
	}

	OSExit = OSExitNull

	name := HelpTestMakeLogFile(t)

	defer func() {
		if err = os.Remove(name); err != nil {
			t.Fatal(err)
		}
	}()

	InterruptChannel <- syscall.SIGINT

	DoOnInterrupt()

	if err == nil {
		t.Errorf("DoOnInterrupt(): want the error.")
	}
}

// TestDoOnInterruptRedistoreCloseError tests when InterruptChannel is notified and the Redistore.Close error has occured.
func TestDoOnInterruptRedistoreCloseError(t *testing.T) {
	// TODO
}

// TestDoOnInterruptTLS tests when InterruptChannel is notified and the server is TLS.
func TestDoOnInterruptTLS(t *testing.T) {
	var err error

	HelpTestCapture()

	defer HelpTestReset()

	ConfigInstance.TLSEnabled = true

	LogFatal = func(args ...interface{}) {
		if len(args) > 0 {
			err = args[0].(error)
		}
	}

	OSExit = OSExitNull

	name := HelpTestMakeLogFile(t)

	defer func() {
		if err = os.Remove(name); err != nil {
			t.Fatal(err)
		}
	}()

	InterruptChannel <- syscall.SIGINT

	DoOnInterrupt()

	if err != nil {
		t.Errorf("DoOnInterrupt(): got the error: %v", err.Error())
	}
}

// TestDoOnInterruptTLSError tests when InterruptChannel is notified, the server is TLS and the shutdown error has occured.
func TestDoOnInterruptTLSError(t *testing.T) {
	var err error

	HelpTestCapture()

	defer HelpTestReset()

	ConfigInstance.TLSEnabled = true

	HTTPServerShutdown = HTTPServerShutdownError

	LogFatal = func(args ...interface{}) {
		if len(args) > 0 {
			err = args[0].(error)
		}
	}

	OSExit = OSExitNull

	name := HelpTestMakeLogFile(t)

	defer func() {
		if err = os.Remove(name); err != nil {
			t.Fatal(err)
		}
	}()

	InterruptChannel <- syscall.SIGINT

	DoOnInterrupt()

	if err == nil {
		t.Errorf("DoOnInterrupt(): want the error.")
	}
}

// TestInitSystem tests the system initialization.
func TestInitSystem(t *testing.T) {
	InitSystem()
}

// TestInitSystemOSChdirError tests the system initialization in the case of an os.Chdir error.
func TestInitSystemOSChdirError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	OSChdir = OSChdirError

	if err := InitSystem(); err == nil {
		t.Errorf("InitSystem(): want the error.")
	}
}

// TestInitSystemOSExecutableError tests the system initialization in the case of an os.Executable error.
func TestInitSystemOSExecutableError(t *testing.T) {
	HelpTestCapture()

	defer HelpTestReset()

	OSExecutable = OSExecutableError

	if err := InitSystem(); err == nil {
		t.Errorf("InitSystem(): want the error.")
	}
}
