package main

import (
	"fmt"
	"net/http"
)

type MyHandler struct{}

func (h *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello, World!")
}

type UnkoHandler struct{}

func (h *UnkoHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Unko\nUnko\nUnko")
}

func main() {
	handler := MyHandler{}
	unko := UnkoHandler{}
	server := http.Server{
		Addr: "127.0.0.1:8080",
	}
	http.Handle("/", &handler)
	http.Handle("/unko", &unko)

	server.ListenAndServe()
}
