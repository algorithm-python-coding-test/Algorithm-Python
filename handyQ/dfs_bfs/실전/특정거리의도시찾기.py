# https://www.acmicpc.net/problem/18352

# 4 4 2 1
# 1 2
# 1 3
# 2 3
# 2 4


from collections import deque
import sys
input = sys.stdin.readline

N,M,K,X = list(map(int,input().split()))


# graph 만들기
graph = [[] for _ in range(N+1)]
for _ in range(M):
    start,end = map(int,input().split())
    graph[start].append(end)


visited = [0] * (N+1)
ans = []
# bfs 큐 사용. (도시, 거리)

q = deque()
q.append((X,0))
while q:
    city, distance = q.popleft()

    if distance == K:
        ans.append(city)

    elif distance < K:
        for c in graph[city]:
            if not visited[c]:
                visited[c]=1
                q.append((c,distance+1))

if not len(ans):
    print(-1)
else:
    ans.sort()
    for a in ans:
        print(a)