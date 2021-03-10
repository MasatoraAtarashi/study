package main

import (
	"net/http"
	"html/template"
)

func process(w http.ResponseWriter, r *http.Request) {
	//t, _ := template.ParseFiles("templ.html")
	t := template.Must(template.ParseFiles("templ.html"))
	t.Execute(w, "Hello World!")
}

func xss(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("X-XSS-Protection", "0")
	t, _ := template.ParseFiles("templ.html")
	t.Execute(w, template.HTML(r.FormValue("comment")))
}

func form(w http.ResponseWriter, r *http.Request) {
	t, _ := template.ParseFiles("form.html")
	t.Execute(w, nil)
}

func main() {
	server := http.Server{
		Addr: "127.0.0.1:8080",
	}
	http.HandleFunc("/process", process)
	http.HandleFunc("/xss", xss)
	http.HandleFunc("/form", form)
	server.ListenAndServe()
}
