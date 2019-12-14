# YDC Server

## Backend

### Setup
1. Install [Golang](https://golang.org) (version 1.13).
2. Check if everything is installed properly by running `go version`.
3. Change to this directory.
4. Ensure that Golang Modules are enabled:
	1. Run `go env`.
	2. Check if `GO111MODULE` has an empty value or is absent.
	3. Check if you are outside of `GOPATH/src`.
5. Run `go get` to install the dependencies.

### Compile
1. Run `go build`. The executable will be in this directory.

### Run the tests
1. Run `go test -tags test`.
