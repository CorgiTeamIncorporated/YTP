package main

import (
	"flag"
)

// ConfigPathFlag is the configuration path flag.
var ConfigPathFlag = ""

// InitFlags initializes the flags.
func InitFlags() error {
	flag.StringVar(&ConfigPathFlag, "c", "", "The path to the configuration file.")

	flag.Parse()

	return nil
}
