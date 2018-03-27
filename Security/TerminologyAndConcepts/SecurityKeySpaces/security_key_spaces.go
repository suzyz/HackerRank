package main

import (
	"fmt"
)

func main() {
	var key int
	var s string
	fmt.Scanf("%s", &s)
	fmt.Scanf("%d", &key)
	key %= 10
	str := []byte(s)

	for i, c := range str {
		c += byte(key)
		if c > '9' {
			c -= 10
		}
		str[i] = c
	}
	fmt.Printf("%s\n", str)
}
