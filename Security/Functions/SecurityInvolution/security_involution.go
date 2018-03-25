package main

import "fmt"

func main() {
	var n int
	var f [22]int

	fmt.Scanf("%d", &n)
	fmt.Scanf("\n")
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &f[i])
		if f[i] < 1 || f[i] > n {
			fmt.Println("NO")
			return
		}
	}

	for i := 1; i <= n; i++ {
		if f[f[i]] != i {
			fmt.Println("NO")
			return
		}
	}

	fmt.Println("YES")
}
