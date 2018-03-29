package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type pq []int

func (h pq) Len() int {
	return len(h)
}
func (h pq) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h pq) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *pq) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *pq) Pop() interface{} {
	n := len(*h)
	x := (*h)[n-1]
	*h = (*h)[:n-1]
	return x
}

func (h pq) Peek() int {
	return h[0]
}

/*
 * Complete the cookies function below.
 */
func cookies(k int, A []int) int {
	n := len(A)
	cookies := &pq{}

	for i := 0; i < n; i++ {
		heap.Push(cookies, A[i])
	}

	if cookies.Peek() >= k {
		return 0
	}

	for i := 1; i < n; i++ {
		a := heap.Pop(cookies).(int) + (heap.Pop(cookies).(int) << 1)
		heap.Push(cookies, a)

		if cookies.Peek() >= k {
			return i
		}

	}
	return -1
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, _ := os.Create(os.Getenv("OUTPUT_PATH"))

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	nk := strings.Split(readLine(reader), " ")

	n, _ := strconv.ParseInt(nk[0], 10, 64)

	k, _ := strconv.ParseInt(nk[1], 10, 64)

	ATemp := strings.Split(readLine(reader), " ")

	var A []int

	for AItr := 0; AItr < int(n); AItr++ {
		AItem, _ := strconv.ParseInt(ATemp[AItr], 10, 64)
		A = append(A, int(AItem))
	}

	result := cookies(int(k), A)

	fmt.Fprintf(writer, "%d\n", result)

	writer.Flush()
}

func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()

	return strings.TrimRight(string(str), "\r\n")
}
