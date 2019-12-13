package main

import (
	"context"
	"html/template"
	"io"
	"net/http"
	"net/url"
	"os"
)

// CapturedConfigInstance is the captured version of ConfigInstance.
var CapturedConfigInstance Config

// CapturedConfigPathFlag is the captured version of ConfigPathFlag.
var CapturedConfigPathFlag string

// CapturedHTTPServerShutdown is the captured version of HTTPServerShutdown.
var CapturedHTTPServerShutdown func(*http.Server, context.Context) error

// CapturedIOUtilReadFile is the captured version of IOUtilReadFile.
var CapturedIOUtilReadFile func(string) ([]byte, error)

// CapturedJSONMarshal is the captured version of JSONMarshal.
var CapturedJSONMarshal func(interface{}) ([]byte, error)

// CapturedJSONUnmarshal is the captured version of JSONUnmarshal.
var CapturedJSONUnmarshal func([]byte, interface{}) error

// CapturedLogPrint is the captured version of LogPrint.
var CapturedLogPrint func(...interface{})

// CapturedLogPrintf is the captured version of LogPrintf.
var CapturedLogPrintf func(string, ...interface{})

// CapturedLogFatal is the captured version of LogFatal.
var CapturedLogFatal func(...interface{})

// CapturedLogFatalf is the captured version of LogFatalf.
var CapturedLogFatalf func(string, ...interface{})

// CapturedLogFile is the captured version of LogFile.
var CapturedLogFile *os.File

// CapturedOSChdir is the captured version of OSChdir.
var CapturedOSChdir func(string) error

// CapturedOSExecutable is the captured version of OSExecutable.
var CapturedOSExecutable func() (string, error)

// CapturedOSExit is the captured version of OSExit.
var CapturedOSExit func(int)

// CapturedOSStat is the captured version of OSStat.
var CapturedOSStat func(string) (os.FileInfo, error)

// CapturedTemplateExecute is the captured version of TemplateExecute.
var CapturedTemplateExecute func(*template.Template, io.Writer, interface{}) error

// CapturedTemplateParseFiles is the captured version of TemplateParseFiles.
var CapturedTemplateParseFiles func(...string) (*template.Template, error)

// CapturedURLParse is the captured version of URLParse.
var CapturedURLParse func(string) (*url.URL, error)

// HelpTestCapture captures the current version of the set functions and variables.
func HelpTestCapture() {
	CapturedConfigInstance = ConfigInstance

	CapturedConfigPathFlag = ConfigPathFlag

	CapturedHTTPServerShutdown = HTTPServerShutdown

	CapturedIOUtilReadFile = IOUtilReadFile

	CapturedJSONMarshal = JSONMarshal

	CapturedJSONUnmarshal = JSONUnmarshal

	CapturedLogPrint = LogPrint

	CapturedLogPrintf = LogPrintf

	CapturedLogFatal = LogFatal

	CapturedLogFatalf = LogFatalf

	CapturedLogFile = LogFile

	CapturedOSChdir = OSChdir

	CapturedOSExecutable = OSExecutable

	CapturedOSExit = OSExit

	CapturedOSStat = OSStat

	CapturedTemplateExecute = TemplateExecute

	CapturedTemplateParseFiles = TemplateParseFiles

	CapturedURLParse = URLParse
}

// HelpTestReset resets the set functions and variables to the captured version.
func HelpTestReset() {
	ConfigInstance = CapturedConfigInstance

	ConfigPathFlag = CapturedConfigPathFlag

	HTTPServerShutdown = CapturedHTTPServerShutdown

	IOUtilReadFile = CapturedIOUtilReadFile

	JSONMarshal = CapturedJSONMarshal

	JSONUnmarshal = CapturedJSONUnmarshal

	LogPrint = CapturedLogPrint

	LogPrintf = CapturedLogPrintf

	LogFatal = CapturedLogFatal

	LogFatalf = CapturedLogFatalf

	LogFile = CapturedLogFile

	OSChdir = CapturedOSChdir

	OSExecutable = CapturedOSExecutable

	OSExit = CapturedOSExit

	OSStat = CapturedOSStat

	TemplateExecute = CapturedTemplateExecute

	TemplateParseFiles = CapturedTemplateParseFiles

	URLParse = CapturedURLParse
}
