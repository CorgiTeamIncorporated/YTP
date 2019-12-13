package main

import (
	"testing"
)

// TestInitFlags tests the flags initialization.
func TestInitFlags(t *testing.T) {
	if err := InitFlags(); err != nil {
		t.Errorf("InitFlags()[0]: got the error: %v", err.Error())
	}
}
