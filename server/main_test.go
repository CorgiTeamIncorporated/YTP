package main

import (
	"os"
	"testing"
)

// TestMain wraps the test execution.
func TestMain(m *testing.M) {
	LogPrint = LogPrintNull

	LogPrintf = LogPrintfNull

	os.Exit(m.Run())
}
