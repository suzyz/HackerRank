package main

import (
	"fmt"
)

type heap struct {
	nums []int
}

func (h *heap) push(v int) {
	h.nums = append(h.nums, v)

	j := len(h.nums) - 1
	i := j >> 1
	for i > 0 {
		if h.nums[i] > h.nums[j] {
			h.swap(i, j)
			j = i
			i = j >> 1
		} else {
			break
		}
	}
}

func (h *heap) delete(v int) {
	i := 1
	n := len(h.nums)
	for i = 1; i < n; i++ {
		if h.nums[i] == v {
			break
		}
	}

	if i >= n {
		return
	}
	if i == n-1 {
		h.nums = h.nums[:n-1]
	} else {
		h.swap(i, n-1)
		h.nums = h.nums[:n-1]

		n--
		j := i << 1
		for j < n {
			best := i
			if h.nums[j] < h.nums[i] {
				best = j
			}

			if j < n-1 && h.nums[j+1] < h.nums[best] {
				best = j + 1
			}

			if best == i {
				break
			}

			h.swap(i, best)

			i = best
			j = i << 1
		}
	}
}

func (h *heap) swap(i, j int) {
	h.nums[i], h.nums[j] = h.nums[j], h.nums[i]
}

func (h *heap) peek() int {
	if len(h.nums) < 2 {
		return -1
	}
	return h.nums[1]
}

func main() {
	var q, op, v int
	h := &heap{[]int{0}}

	fmt.Scanf("%d", &q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &op)
		switch op {
		case 1:
			fmt.Scanf("%d", &v)
			h.push(v)
		case 2:
			fmt.Scanf("%d", &v)
			h.delete(v)
		case 3:
			fmt.Println(h.peek())
		}
	}
}
