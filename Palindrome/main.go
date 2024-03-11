package main

import (
	"fmt"
)

func checker(s string, starts []int, ends []int, subs []int) string {
	const N = 26
	n := len(s)
	q := len(subs)
	pre := make([][]int, n)
	for i := 0; i < n; i++ {
		pre[i] = make([]int, N)
		if i > 0 {
			copy(pre[i], pre[i-1])
		}
		pre[i][int(s[i]-'a')]++
	}
	ans := ""
	for i := 0; i < q; i++ {
		l := starts[i]
		r := ends[i]
		odds := 0
		for j := 0; j < N; j++ {
			cnt := pre[r][j]
			if l > 0 {
				cnt -= pre[l-1][j]
			}
			if cnt%2 == 1 {
				odds++
			}
		}
		need := odds / 2
		if need > subs[i] {
			ans += "0"
		} else {
			ans += "1"
		}
	}
	return ans
}

func solve() {
	var n, q int
	fmt.Scan(&n, &q)
	var s string
	fmt.Scan(&s)
	starts := make([]int, q)
	ends := make([]int, q)
	subs := make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&starts[i])
	}
	for i := 0; i < q; i++ {
		fmt.Scan(&ends[i])
	}
	for i := 0; i < q; i++ {
		fmt.Scan(&subs[i])
	}
	fmt.Println(checker(s, starts, ends, subs))
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		solve()
		t--
	}
}
