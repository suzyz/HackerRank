package main

import (
	"fmt"
)

func main() {
	var n, res int
	fmt.Scanf("%d", &n)
	res = 1
	for i := 2; i <= n; i++ {
		res *= i
	}
	fmt.Println(res)
}
