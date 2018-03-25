package main

import (
	"fmt"
	"io"
	"os"
	"sort"
)

var success = false

const mappingSize = 256

func main() {
	dictFile, err := os.Open("dictionary.lst")
	if err != nil {
		panic(err)
	}
	defer dictFile.Close()

	// Read the dictionary
	dict := make([]string, 0)
	for {
		var tmp string
		_, err := fmt.Fscanf(dictFile, "%s", &tmp)
		if err == io.EOF {
			break
		}
		if err != nil {
			panic(err)
		}
		t := []byte(tmp)
		for i, c := range t {
			if c >= 'A' && c <= 'Z' {
				t[i] = c - 'A' + 'a'
			}
		}
		tmp = string(t)
		dict = append(dict, tmp)
	}

	// Read the encrypted words
	var words []string
	for {
		var tmp string
		num, err := fmt.Scanf("%s", &tmp)
		if err == io.EOF {
			break
		}
		if err != nil {
			panic(err)
		}

		if num == 0 {
			break
		}
		words = append(words, tmp)
	}

	// Find each word's isomorphisms in the dictionary
	n := len(words)
	candidates := make([][]int, n)
	for i, w := range words {
		tmp1 := string(transform(w))
		for j, d := range dict {
			if len(w) != len(d) {
				continue
			}
			tmp2 := string(transform(d))
			if tmp1 == tmp2 {
				candidates[i] = append(candidates[i], j)
			}
		}
	}

	// Sort the indices according to the number of candidates
	idx := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}

	sort.Slice(idx, func(i, j int) bool {
		return len(candidates[idx[i]]) < len(candidates[idx[j]])
	})

	// Get the mapping
	mapping := make([]byte, mappingSize)
	st := 0
	for st < n && len(candidates[idx[st]]) == 1 {
		d := candidates[idx[st]][0]
		for i, c := range words[idx[st]] {
			mapping[c] = dict[d][i]
		}
		st++
	}

	dfs(st, idx, words, dict, candidates, mapping)

	// Decipher/Decoding
	for _, w := range words {
		origin := []byte(w)
		for i, c := range origin {
			origin[i] = mapping[c]
		}
		fmt.Printf("%s ", origin)
	}
}

func transform(s string) (isomorphism []byte) {
	n := len(s)
	isomorphism = make([]byte, n)

	idx, same := 0, false
	for i := 0; i < n; i++ {
		same = false
		for j := 0; j < i; j++ {
			if s[j] == s[i] {
				same = true
				isomorphism[j] = isomorphism[i]
				break
			}
		}
		if !same {
			isomorphism[i] = byte(idx)
			idx++
		}
	}
	return
}

func dfs(cur int, idx []int, words, dict []string, candidates [][]int, mapping []byte) {
	if cur >= len(idx) {
		success = true
		return
	}

	backup := make([]byte, mappingSize)
	copy(backup, mapping)

	w := words[idx[cur]]
	for _, can := range candidates[idx[cur]] {

		flag := true
		for j, c := range w {
			if m := mapping[int(c)]; m != 0 {
				if m != dict[can][j] {
					flag = false
					break
				}
			} else {
				mapping[int(c)] = dict[can][j]
			}
		}

		if !flag {
			copy(mapping, backup)
			continue
		}

		dfs(cur+1, idx, words, dict, candidates, mapping)
		if success {
			return
		}
		copy(mapping, backup)
	}
}
