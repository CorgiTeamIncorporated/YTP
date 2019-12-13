package main

import (
	"io"
	"log"
	"os"
)

// LogFlags is the log flags which define the log format.
const LogFlags = log.Ldate | log.Ltime | log.Lmicroseconds | log.Lshortfile

// LogFile is the log file used to store log entries.
var LogFile *os.File

// InitLog initializes the logger.
func InitLog() error {
	var err error

	log.SetFlags(LogFlags)

	if ConfigInstance.LogPath == "" {
		return nil
	}

	LogFile, err = os.OpenFile(ConfigInstance.LogPath, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0666)

	if err != nil {
		return err
	}

	log.SetOutput(io.MultiWriter(os.Stdout, LogFile))

	return nil
}
