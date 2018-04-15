package main

import (
	"fmt"
)

func main() {
	var n int = 10

	bad := 0.12
	good := 1 - bad

	var f [12]float64
	f[0] = 1
	for i := 1; i <= n; i++ {
		f[i] = f[i-1] * good
	}
	res1 := f[10] + 10*f[9]*bad + 45*f[8]*bad*bad
	res2 := 1 - f[10] - 10*f[9]*bad

	fmt.Printf("%.3f\n%.3f\n", res1, res2)
}
