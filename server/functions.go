package main

import (
	"context"
	"encoding/json"
	"html/template"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"net/url"
	"os"
)

// HTTPServerShutdown is the replacement for http.Server.Shutdown.
var HTTPServerShutdown = func(srv *http.Server, ctx context.Context) error {
	return srv.Shutdown(ctx)
}

// IOUtilReadFile is the replacement for ioutil.ReadFile.
var IOUtilReadFile = ioutil.ReadFile

// JSONMarshal is the replacement for json.Marshal.
var JSONMarshal = json.Marshal

// JSONUnmarshal is the replacement for json.Unmarshal.
var JSONUnmarshal = json.Unmarshal

// LogPrint is the replacement for log.Print.
var LogPrint = log.Print

// LogPrintf is the replacement for log.Printf.
var LogPrintf = log.Printf

// LogFatal is the replacement for log.Fatal.
var LogFatal = log.Fatal

// LogFatalf is the replacement for log.Fatalf.
var LogFatalf = log.Fatalf

// OSChdir is the replacement for os.Chdir.
var OSChdir = os.Chdir

// OSExecutable is the replacement for os.Executable.
var OSExecutable = os.Executable

// OSExit is the replacement for os.Exit.
var OSExit = os.Exit

// OSStat is the replacement for os.Stat.
var OSStat = os.Stat

// TemplateParseFiles is the replacement for template.ParseFiles.
var TemplateParseFiles = template.ParseFiles

// TemplateExecute is the replacement for template.Template.Execute.
var TemplateExecute = func(tpl *template.Template, w io.Writer, data interface{}) error {
	return tpl.Execute(w, data)
}

// URLParse is the replacement for url.Parse.
var URLParse = url.Parse
