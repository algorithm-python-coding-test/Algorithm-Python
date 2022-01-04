# - input
#   - n : 도시의 개수
#   - m : 통로의 개수
#   - c : 출발점 도시
#   - a, b, c : 간선정보(a : 출발, b : 도착, c : 시간)
# - output
#   - distance[i]들 중 INFINITY가 아닌 개수
#   - max(distance)
# - constraint
#   - 1 <= n <= 30000
#   - 1 <= m <= 200000
#   - 1 <= c <= n
# - edge case

# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - graph : 각 노드의 간선을 기록한 2차 배열
#     - distance : 최단 거리를 기록한 1차 배열
#     - heapq : 우선순위큐를 구현하기 위한 힙
#   - algorithm
#     - 다익스트라
#   - time complexity
#     - O((노드에 연결된 최대 간선 개수) * logn)
#   - space complexity
#     - graph : m (최대 200000)
#     - distance : n (최대 30000)
#     - heapq : n (최대 30000)

### 9-2.py(우선순위큐를 이용한 다익스트라 구현)이랑 거의 동일

import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

n, m, start = map(int, input().split())
graph = [[] for i in range(n + 1)]
distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)

# 도달 가능한 도시 개수
result = 0
maxDis = 0

for i in distance:
    if i != INF:
        result += 1
        maxDis = max(maxDis, i)
print(result - 1, maxDis)

