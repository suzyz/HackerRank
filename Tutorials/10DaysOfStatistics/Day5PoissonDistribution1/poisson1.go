package main

import "fmt"
import "math"

func main() {
	lambda := 2.5
	k := 5.0
	res := math.Pow(lambda, k) * math.Pow(math.E, -lambda) / 120
	fmt.Printf("%.3f\n", res)
}
