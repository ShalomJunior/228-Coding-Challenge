import sys

sys.setrecursionlimit(1000005)
def checker(x1, y1, x2, y2):
    N = 1005
    vis = [[False] * N for _ in range(N)]
    
    def go(x, y):
        nonlocal vis
        vis[x][y] = True
        print(x, y)
        if x + y >= N:
            return
        if (vis[x + y][y] == False) :
            go(x + y, y)
        if (vis[x][y + x] == False) :
            go(x, y + x)
    
    go(x1, y1)
    return "YES" if vis[x2][y2] else "NO"

def solve():
    x1 = int(input())
    y1 = int(input())
    x2 = int(input())
    y2 = int(input())
    print(x1, y1, x2, y2)

    # x1, y1, x2, y2 = map(int, input().split())
    # y1 = map(int, input().split())
    # x2 = map(int, input().split())
    # y2 = map(int, input().split())
    
    # print(checker(x1, y1, x2, y2))

t = 1
t = int(input())
while t > 0:
    solve()
    t -= 1

