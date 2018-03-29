package main

import (
	"fmt"
)

var l, r map[int]int

func swap(cur, h, k int) {
	if cur == -1 {
		return
	}

	if h%k == 0 {
		l[cur], r[cur] = r[cur], l[cur]
	}

	swap(l[cur], h+1, k)
	swap(r[cur], h+1, k)
}

func inorder(cur int) {
	if cur == -1 {
		return
	}

	inorder(l[cur])
	fmt.Printf("%d ", cur)
	inorder(r[cur])
}

func main() {
	var n, T, a, b, k int
	l, r = make(map[int]int), make(map[int]int)

	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d %d", &a, &b)
		l[i] = a
		r[i] = b
	}
	fmt.Scanf("%d", &T)
	for i := 0; i < T; i++ {
		fmt.Scanf("%d", &k)
		swap(1, 1, k)
		inorder(1)
		fmt.Println()
	}
}
