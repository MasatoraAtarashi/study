package main

import (
	"fmt"
	"math"
)

func Sqrt(x float64) float64 {
	z, d := x/2, 1.0
	for math.Abs(d) > 0.0000000001 {
		d = z*z - x
		z -= d / (2 * z)
		fmt.Println(d)
	}
	return z
}

func main() {
	fmt.Println(Sqrt(2))
}
