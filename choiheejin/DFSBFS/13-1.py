from collections import deque

n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)


# BFS로 a, b 사이에서 갈 수 있는 경로 모두 구하기
queue = deque()

counts = {0: [x]}
visited = [x]
queue.append(x)

count = 0

while queue:
    node = queue.popleft()
    # count는 popleft될때마다 count 되어서는 안된다.
    # 이번에 찾은 노드의 거리 = 전에 찾은 노드(pop한 것)의 거리 +1
    count += 1
    counts[count] = []
    for i in graph[node]:
        if i not in visited:
            queue.append(i)
            visited.append(i)
            counts[count].append(i)

if len(counts[k]) == 0:
    print(-1)

for result in counts[k]:
    print(result)
