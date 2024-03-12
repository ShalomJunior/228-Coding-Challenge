# Check c++ code for comments 

def checker(s, starts, ends, subs):
    N = 26
    n = len(s)
    q = len(subs)
    pre = [[0] * N for _ in range(n)]
    for i in range(n):
        if i:
            pre[i] = pre[i - 1][:]
        pre[i][ord(s[i]) - ord('a')] += 1
    ans = ""
    for i in range(q):
        l = starts[i]
        r = ends[i]
        odds = 0
        for j in range(N):
            cnt = pre[r][j] - (0 if l == 0 else pre[l - 1][j])
            if cnt & 1:
                odds += 1
        need = odds // 2
        ans += "0" if need > subs[i] else "1"
    return ans

def solve():
    n, q = map(int, input().split())
    s = input()
    starts = list(map(int, input().split()))
    ends = list(map(int, input().split()))
    subs = list(map(int, input().split()))
    print(checker(s, starts, ends, subs))

t = 1
t = int(input())
while t > 0:
    solve()
    t -= 1

