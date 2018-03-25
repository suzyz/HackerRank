package main

import "fmt"

func main() {
	var n int
	var f [22]int

	fmt.Scanf("%d", &n)
	fmt.Scanf("\n")
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &f[i])
	}

	for i := 1; i <= n; i++ {
		fmt.Println(f[f[i]])
	}
}
