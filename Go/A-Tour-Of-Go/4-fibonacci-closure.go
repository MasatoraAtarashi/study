package main

import "fmt"

// fibonacci is a function that returns
// a function that returns an int.
func fibonacci() func() int {
	a := []int{0, 1}
	cnt := 0
	return func() int {
		if cnt >= len(a) {
			a = append(a, (a[cnt-2] + a[cnt-1]))
		}
		value := a[cnt]
		cnt += 1
		return value
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
