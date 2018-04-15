package main

import (
	"fmt"
)

func main() {
	var a, b, res float64
	fmt.Scanf("%f %f", &a, &b)
	b = a / (a + b)
	g := 1 - b
	res = 1 - g*g*g*g*g*g - 6*b*g*g*g*g*g - 15*b*b*g*g*g*g
	fmt.Printf("%.3f\n", res)
}
