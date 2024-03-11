import heapq

def checker(n, from_, to, w, x, y):
    INF = 2e9
    m = len(from_)
    adj = [[] for _ in range(n)]
    for i in range(m):
        adj[from_[i] - 1].append((to[i] - 1, w[i]))
        adj[to[i] - 1].append((from_[i] - 1, w[i]))
    x -= 1
    y -= 1
    def bfs(root, dis):
        vis = [False] * n
        pq = []
        heapq.heappush(pq, (0, root))
        dis[root] = 0
        while pq:
            d, u = heapq.heappop(pq)
            if vis[u]:
                continue
            vis[u] = True
            for v, cost in adj[u]:
                if dis[u] + cost < dis[v]:
                    dis[v] = dis[u] + cost
                    heapq.heappush(pq, (dis[v], v))
    a = [INF] * n
    b = [INF] * n
    c = [INF] * n
    bfs(0, a)
    bfs(x, b)
    bfs(y, c)
    return a[x] + b[y] + c[n - 1]

def solve():
    n, m = map(int, input().split())
    from_ = []
    to = []
    w = []
    for _ in range(m):
        f, t, weight = map(int, input().split())
        from_.append(f)
        to.append(t)
        w.append(weight)
    # x, y = map(int, input().split())
    x = int(input())
    y = int(input())

    print(checker(n, from_, to, w, x, y))

t = 1
t = int(input())
while t > 0:
    solve()
    t -= 1

