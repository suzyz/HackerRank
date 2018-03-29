package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type maxHeap []int
type minHeap []int

func (h maxHeap) Len() int {
	return len(h)
}

func (h maxHeap) Less(i, j int) bool {
	return h[i] > h[j]
}

func (h maxHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *maxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *maxHeap) Pop() interface{} {
	n := len(*h)
	x := (*h)[n-1]
	*h = (*h)[:n-1]
	return x
}

func (h *maxHeap) Peek() interface{} {
	return (*h)[0]
}

func (h minHeap) Len() int {
	return len(h)
}

func (h minHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h minHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *minHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *minHeap) Pop() interface{} {
	n := len(*h)
	x := (*h)[n-1]
	*h = (*h)[:n-1]
	return x
}

func (h *minHeap) Peek() interface{} {
	return (*h)[0]
}

func runningMedian(a []int) []float64 {
	n := len(a)
	res := make([]float64, n)
	smallerHalf := &maxHeap{}
	largerHalf := &minHeap{}

	for i := 0; i < n; i++ {
		if largerHalf.Len() == 0 || a[i] >= largerHalf.Peek().(int) {
			heap.Push(largerHalf, a[i])
			if largerHalf.Len() > smallerHalf.Len()+1 {
				heap.Push(smallerHalf, heap.Pop(largerHalf))
			}
		} else {
			heap.Push(smallerHalf, a[i])
			if smallerHalf.Len() > largerHalf.Len()+1 {
				heap.Push(largerHalf, heap.Pop(smallerHalf))
			}
		}

		if (i & 1) == 0 {
			if smallerHalf.Len() > largerHalf.Len() {
				res[i] = float64(smallerHalf.Peek().(int))
			} else {
				res[i] = float64(largerHalf.Peek().(int))
			}
		} else {
			res[i] = float64(largerHalf.Peek().(int)+smallerHalf.Peek().(int)) / 2
		}
	}

	return res
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	aCount, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)

	var a []int

	for aItr := 0; aItr < int(aCount); aItr++ {
		aItemTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		a = append(a, int(aItemTemp))
	}

	result := runningMedian(a)

	for resultItr, resultItem := range result {
		fmt.Fprintf(writer, "%f", resultItem)

		if resultItr != len(result)-1 {
			fmt.Fprintf(writer, "\n")
		}
	}

	fmt.Fprintf(writer, "\n")

	writer.Flush()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
