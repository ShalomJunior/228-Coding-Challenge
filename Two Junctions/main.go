package main

import (
	"container/heap"
	"fmt"
)

/*
Not really sure about this implementation of priorityqueue in Go
Need to ensure it work properly
*/

type pair struct {
	first  int
	second int
}

type priorityQueue []pair

func (pq priorityQueue) Len() int {
	return len(pq)
}

func (pq priorityQueue) Less(i, j int) bool {
	return pq[i].first < pq[j].first
}

func (pq priorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *priorityQueue) Push(x interface{}) {
	item := x.(pair)
	*pq = append(*pq, item)
}

func (pq *priorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func checker(n int, from, to, w []int, x, y int) int {
	const INF = 2e9
	m := len(from)
	adj := make([][]pair, n)
	for i := 0; i < m; i++ {
		adj[from[i]-1] = append(adj[from[i]-1], pair{to[i] - 1, w[i]})
		adj[to[i]-1] = append(adj[to[i]-1], pair{from[i] - 1, w[i]})
	}
	x--
	y--
	bfs := func(root int, dis []int) {
		vis := make([]bool, n)
		pq := priorityQueue{{0, root}}
		dis[root] = 0
		for len(pq) > 0 {
			item := heap.Pop(&pq).(pair)
			_, u := item.first, item.second
			if vis[u] {
				continue
			}
			vis[u] = true
			for _, p := range adj[u] {
				v, cost := p.first, p.second
				if dis[u]+cost < dis[v] {
					dis[v] = dis[u] + cost
					heap.Push(&pq, pair{dis[v], v})
				}
			}
		}
	}
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = INF
		b[i] = INF
		c[i] = INF
	}
	bfs(0, a)
	bfs(x, b)
	bfs(y, c)
	return a[x] + b[y] + c[n-1]
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)
	from := make([]int, m)
	to := make([]int, m)
	w := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&from[i], &to[i], &w[i])
	}
	var x, y int
	fmt.Scan(&x, &y)
	fmt.Println(checker(n, from, to, w, x, y))
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		solve()
		t--
	}
}
