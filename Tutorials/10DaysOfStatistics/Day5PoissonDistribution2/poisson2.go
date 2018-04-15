package main

import "fmt"

func main() {
	lambda1 := 0.88
	lambda2 := 1.55
	e1 := (lambda1*lambda1+lambda1)*40 + 160
	e2 := (lambda2*lambda2+lambda2)*40 + 128
	fmt.Printf("%.3f\n%.3f\n", e1, e2)
}
