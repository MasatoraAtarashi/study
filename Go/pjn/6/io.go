package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	data := []byte("Hello World!\n")
	err := ioutil.WriteFile("data1", data, 0644)
	if err != nil {
		panic(err)
	}
	read1, _ := ioutil.ReadFile("data1")
	fmt.Print(string(read1))

	ﬁle1, _ := os.Create("data2")
	defer ﬁle1.Close()

	bytes, _ := ﬁle1.Write(data)
	fmt.Printf("Wrote %d bytes to ﬁle\n", bytes)

	ﬁle2, _ := os.Open("data2")
	defer ﬁle2.Close()

	read2 := make([]byte, len(data))
	bytes, _ = ﬁle2.Read(read2)
	fmt.Printf("Read %d bytes from ﬁle\n", bytes)
	fmt.Println(string(read2))
}
