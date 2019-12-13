package main

import (
	"context"
	"log"
	"os"
	"os/signal"
	"path/filepath"
	"syscall"
	"time"
)

// InterruptChannel is the OS interrupt signal channel.
var InterruptChannel = make(chan os.Signal, 1)

// CleanUp cleans up the system after the OS interruption.
func CleanUp() error {
	if LogFile == nil {
		return nil
	}

	return LogFile.Close()
}

// DoOnInterrupt runs when InterruptChannel is notified.
func DoOnInterrupt() {
	<-InterruptChannel

	LogPrint("Shutting down the server...")

	ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)

	defer cancel()

	if ConfigInstance.TLSEnabled {
		NonTLSServer.SetKeepAlivesEnabled(false)

		if err := HTTPServerShutdown(NonTLSServer, ctx); err != nil {
			LogFatal(err)
		}
	}

	Server.SetKeepAlivesEnabled(false)

	if err := HTTPServerShutdown(Server, ctx); err != nil {
		LogFatal(err)
	}

	if err := RediStore.Close(); err != nil {
		LogFatal(err)
	}

	log.SetOutput(os.Stdout)

	if err := CleanUp(); err != nil {
		LogFatal(err)
	}

	OSExit(0)
}

// InitSystem initializes the system tasks.
func InitSystem() error {
	ex, err := OSExecutable()

	if err != nil {
		return err
	}

	if err := OSChdir(filepath.Dir(ex)); err != nil {
		return err
	}

	signal.Notify(InterruptChannel, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)

	go DoOnInterrupt()

	return nil
}
