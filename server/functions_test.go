package main

import (
	"context"
	"errors"
	"html/template"
	"io"
	"net/http"
	"net/url"
	"os"
)

// HTTPServerShutdownError is the HTTPServerShutdown function that return the error.
var HTTPServerShutdownError = func(*http.Server, context.Context) error {
	return errors.New("<HTTPServerShutdown TEST ERROR>")
}

// IOUtilReadFileError is the IOUtilReadFile function that return the error.
var IOUtilReadFileError = func(string) ([]byte, error) {
	return nil, errors.New("<IOUtilReadFile TEST ERROR>")
}

// IOUtilReadFileNull is the IOUtilReadFile function that does nothing.
var IOUtilReadFileNull = func(string) ([]byte, error) {
	return []byte{}, nil
}

// JSONMarshalError is the JSONMarshal function that return the error.
var JSONMarshalError = func(interface{}) ([]byte, error) {
	return nil, errors.New("<JSONMarshalError TEST ERROR>")
}

// JSONUnmarshalError is the JSONUnmarshal function that return the error.
var JSONUnmarshalError = func([]byte, interface{}) error {
	return errors.New("<JSONUnmarshalError TEST ERROR>")
}

// LogFatalNull is the LogFatal function that does nothing.
var LogFatalNull = func(...interface{}) {
	return
}

// LogFatalfNull is the LogFatalf function that does nothing.
var LogFatalfNull = func(string, ...interface{}) {
	return
}

// LogPrintNull is the LogPrint function that does nothing.
var LogPrintNull = func(...interface{}) {
	return
}

// LogPrintfNull is the LogPrintf function that does nothing.
var LogPrintfNull = func(string, ...interface{}) {
	return
}

// OSChdirError is the OSChdir function that return the error.
var OSChdirError = func(string) error {
	return errors.New("<OSChdir TEST ERROR>")
}

// OSExecutableError is the OSExecutable function that return the error.
var OSExecutableError = func() (string, error) {
	return "", errors.New("<OSExecutable TEST ERROR>")
}

// OSExitNull is the OSExit function that does nothing.
var OSExitNull = func(int) {
	return
}

// OSStatError is the OSStat function that return the error.
var OSStatError = func(name string) (os.FileInfo, error) {
	return nil, errors.New("<OSStat TEST ERROR>")
}

// TemplateExecuteError is the TemplateExecute function that return the error.
var TemplateExecuteError = func(*template.Template, io.Writer, interface{}) error {
	return errors.New("<TemplateExecute TEST ERROR>")
}

// TemplateParseFilesError is the TemplateParseFiles function that return the error.
var TemplateParseFilesError = func(...string) (*template.Template, error) {
	return nil, errors.New("<TemplateParseFiles TEST ERROR>")
}

// URLParseError is the URLParse function that return the error.
var URLParseError = func(string) (*url.URL, error) {
	return nil, errors.New("<URLParse TEST ERROR>")
}
