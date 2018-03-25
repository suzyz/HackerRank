package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var keyword, txt string

	r := bufio.NewReader(os.Stdin)
	tmp, _ := r.ReadString('\n')
	if len(tmp) > 0 && tmp[len(tmp)-1] == '\n' {
		tmp = tmp[:len(tmp)-1]
	}
	n, _ = strconv.Atoi(tmp)

	for i := 0; i < n; i++ {
		keyword, _ = r.ReadString('\n')
		txt, _ = r.ReadString('\n')
		if len(keyword) > 0 && keyword[len(keyword)-1] == '\n' {
			keyword = keyword[:len(keyword)-1]
		}
		if len(txt) > 0 && txt[len(txt)-1] == '\n' {
			txt = txt[:len(txt)-1]
		}

		orginal := decipher(keyword, txt)
		fmt.Println(orginal)
	}
}

func decipher(keyword, txt string) string {
	width := len(keyword)

	alphabet := make([][]byte, 1)
	alphabet[0] = make([]byte, 0)

	m := make(map[byte]bool)

	for j := 0; j < width; j++ {
		if m[keyword[j]] {
			continue
		}

		m[keyword[j]] = true
		alphabet[0] = append(alphabet[0], keyword[j])
	}

	width = len(alphabet[0])
	line := 0
	for i := byte('A'); i <= byte('Z'); i++ {
		if m[i] {
			continue
		}

		m[i] = true
		if len(alphabet[line]) >= width {
			line++
			alphabet = append(alphabet, make([]byte, 0))
		}
		alphabet[line] = append(alphabet[line], i)
	}

	len_of_last_line := len(alphabet[line])

	new_alphabet := make([][]byte, width)

	for i := 0; i < width; i++ {
		if len_of_last_line > i {
			new_alphabet[i] = make([]byte, line+1)
		} else {
			new_alphabet[i] = make([]byte, line)
		}
	}

	for i := 0; i <= line; i++ {
		for j := 0; j < len(alphabet[i]); j++ {
			new_alphabet[j][i] = alphabet[i][j]
		}
	}

	for i := 0; i < width-1; i++ {
		for j := 0; j < width-1-i; j++ {
			if new_alphabet[j][0] > new_alphabet[j+1][0] {
				new_alphabet[j], new_alphabet[j+1] = new_alphabet[j+1], new_alphabet[j]
			}
		}
	}

	mapping := make(map[byte]byte)
	count := int('A')
	for i := 0; i < width; i++ {
		for j := 0; j < len(new_alphabet[i]); j++ {
			mapping[new_alphabet[i][j]] = byte(count)
			count++
		}
	}

	original := make([]byte, len(txt))
	mapping[' '] = ' '
	for i, c := range txt {
		original[i] = mapping[byte(c)]
	}

	return string(original)
}
