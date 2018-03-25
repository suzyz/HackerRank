package main

import (
	"fmt"
)

func main() {
	var n, x int
	fmt.Scanf("%d", &n)

	var f [22]int

	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &x)
		if x < 1 || x > n {
			fmt.Println("NO")
			return
		}
		f[i] = x
	}

	for i := 1; i < n; i++ {
		for j := i + 1; j <= n; j++ {
			if f[i] == f[j] {
				fmt.Println("NO")
				return
			}
		}
	}

	fmt.Println("YES")
}
