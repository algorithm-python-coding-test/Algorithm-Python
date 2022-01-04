# - input
#   - n : 도시의 개수
#   - m : 버스의 개수
#   - a, b, c = a에서 b로 가는데 필요한 비용 c
# - output
#   - 모든 도시에서 다른 모든 도시로 가는데 필요한 비용의 최솟값 : graph
# - constraint
#   - 1 <= n <= 100
#   - 1 <= m <= 100000
#   - 시작 도시와 도착 도시가 같은 경우 없음
#   - 1 <= c <= 100000
#   - ** 같은 도시를 연결하는 노선이 하나가 아닐 수 있음
# - edge case
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - graph : 각 노드의 간선을 기록한 2차 배열, 각 노드에 대한 최단거리를 저장
#   - algorithm
#     - 플로이드 워셜
#   - time complexity
#     - O(n**3) (<= 1000000)
#   - space complexity
#     - graph : m * 2 (<= 100000)

### 같은 노드를 잇는 간선 중 가장 짧은 것만 사용한다는 것을 제외하고는 
### 9-3.py(플로이드 워셜)이랑 거의 동일

INF = int(1e9)

n = int(input())
m = int(input())

graph = [[INF] * (n + 1) for _ in range(n + 1)]

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    ## a, b를 연결하는 간선 중 가장 짧은 것을 저장해야함
    graph[a][b] = min(graph[a][b], c)

for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            print(0, end = " ")
        else:
            print(graph[a][b], end = " ")
    print()