package main

import "fmt"

func main() {
	var n, x int
	var f [22]int

	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &x)
		f[x] = i
	}

	for i := 1; i <= n; i++ {
		fmt.Println(f[i])
	}
}
