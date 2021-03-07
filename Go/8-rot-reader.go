package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}

func (reader rot13Reader) Read(b []byte) (n int, err error) {
	n, err = reader.r.Read(b)
	for i, c := range b {
		if c >= 'a' && c <= 'z' {
			if c <= 'm' {
				b[i] = c + 13
			} else {
				b[i] = c - 13
			}
		} else if c >= 'A' && c <= 'Z' {
			if c <= 'M' {
				b[i] = c + 13
			} else {
				b[i] = c - 13
			}
		}
	}
	return
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}
