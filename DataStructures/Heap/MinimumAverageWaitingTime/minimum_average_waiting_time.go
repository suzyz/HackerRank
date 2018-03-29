package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type singleOrder struct {
	arrival, cookTime int
}

var data []singleOrder

type ordersIdx []int

func (this ordersIdx) Len() int {
	return len(this)
}

func (this ordersIdx) Less(i, j int) bool {
	return data[this[i]].cookTime < data[this[j]].cookTime
}

func (this ordersIdx) Swap(i, j int) {
	this[i], this[j] = this[j], this[i]
}

func (this *ordersIdx) Push(x interface{}) {
	*this = append(*this, x.(int))
}

func (this *ordersIdx) Pop() interface{} {
	n := len(*this)
	x := (*this)[n-1]
	*this = (*this)[:n-1]
	return x
}

func main() {
	var n, a, b int
	fmt.Scanf("%d", &n)
	data = make([]singleOrder, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d", &a, &b)
		data[i] = singleOrder{a, b}
	}

	sort.Slice(data, func(i, j int) bool {
		return data[i].arrival < data[j].arrival
	})

	totalTime := 0
	lastFinishTime := -1
	h := &ordersIdx{0}
	j := 1
	for i := 0; i < n; i++ {
		cur := heap.Pop(h).(int)
		if data[cur].arrival >= lastFinishTime {
			totalTime += data[cur].cookTime
			lastFinishTime = data[cur].arrival + data[cur].cookTime
		} else {
			totalTime += data[cur].cookTime + lastFinishTime - data[cur].arrival
			lastFinishTime += data[cur].cookTime
		}

		for j < n && data[j].arrival <= lastFinishTime {
			heap.Push(h, j)
			j++
		}

		if h.Len() == 0 && j < n {
			heap.Push(h, j)
			j++
		}
	}

	fmt.Println(totalTime / n)
}
