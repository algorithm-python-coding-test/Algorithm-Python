# - input
#   - n : 회사의 개수
#   - m : 경로의 개수
#   - a, b : 연결된 두 회사
#   - x, k : 목적지와 중간 지점
# - output
#   - graph[1][k] + graph[k][x]
# - constraint
#   - 1 <= n,m <= 100
#   - 1 <= k <= 100
# - edge case
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - graph : 각 노드의 간선을 기록한 2차 배열, 각 노드에 대한 최단거리를 저장
#   - algorithm
#     - 플로이드 워셜
#   - time complexity
#     - O(n**3) (<= 1000000)
#   - space complexity
#     - graph : m * 2 (<= 200)

### 9-3.py(플로이드 워셜)이랑 거의 동일

INF = int(1e9)

n, m = map(int, input().split())

graph = [[INF] * (n + 1) for _ in range(n + 1)]

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[a][b] = 1

for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

x, k = map(int, input().split())

ans = graph[1][k] + graph[k][x]
if ans == INF:
    print(-1)
else:
    print(ans)