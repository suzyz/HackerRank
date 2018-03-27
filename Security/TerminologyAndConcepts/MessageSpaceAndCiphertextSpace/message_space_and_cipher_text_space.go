package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	str := []byte(s)
	for i, c := range str {
		if c == '9' {
			str[i] = '0'
		} else {
			str[i] = c + 1
		}
	}
	fmt.Printf("%s\n", str)
}
