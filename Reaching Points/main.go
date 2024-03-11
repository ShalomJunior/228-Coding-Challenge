package main

import (
	"fmt"
)

func checker(x1, y1, x2, y2 int) string {
	const N = 1005
	vis := make([][]bool, N)
	for i := 0; i < N; i++ {
		vis[i] = make([]bool, N)
	}
	var g func(int, int)
	g = func(x, y int) {
		vis[x][y] = true
		if x+y >= N {
			return
		}
		g(x+y, y)
		g(x, y+x)
	}
	g(x1, y1)
	if vis[x2][y2] {
		return "YES"
	} else {
		return "NO"
	}
}

func solve() {
	var x1, y1, x2, y2 int
	fmt.Scan(&x1, &y1, &x2, &y2)
	fmt.Println(checker(x1, y1, x2, y2))
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		solve()
		t--
	}
}
