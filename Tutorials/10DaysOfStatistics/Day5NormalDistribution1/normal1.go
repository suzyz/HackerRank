package main

import "fmt"
import "math"

func main() {
	mu := 20.0
	sigma := 2.0
	res1 := (1 + math.Erf((19.5-mu)/sigma/math.Sqrt2)) / 2
	res2 := math.Erf((22-mu)/sigma/math.Sqrt2) / 2
	fmt.Printf("%.3f\n%.3f\n", res1, res2)
}
