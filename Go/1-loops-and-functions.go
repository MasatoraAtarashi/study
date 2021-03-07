package main

import (
	"fmt"
	"math"
)

func Sqrt(x float64) (float64, int) {
	z := 1.0
	prev_z := z
	i := 0
	for ; i < 30; i++ {
		z -= (z*z - x) / (2 * z)
		if math.Abs(z-prev_z) < 0.00000001 {
			break
		}
		prev_z = z
	}
	return z, i
}

func main() {
	z, cnt := Sqrt(2)
	fmt.Println("original: ", z, "loop_count: ", cnt)
	fmt.Println("Math.Sqrt: ", math.Sqrt(2))
}
