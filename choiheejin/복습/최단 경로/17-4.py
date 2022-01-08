# - input
#   - 헛간 개수(N), 양방향 통로(M), 통로 정보(A, B)
# - output
#   - 동빈이가 숨을 헛간 번호(여러개일 경우 가장 작은 헛간 번호), 거리, 같은 거리를 갖는 헛간의 개수
# - constraint
#   - 2 <= n <= 20000
#   - 1 <= m <= 50000
#   - 1 <= a, b <= n
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - 출발지점이 정해져있기에 다익스트라 
#     - BFS도 가능
#   - algorithm
#     - 양방향 간선 (간선의 비용은 모두 1로 같음)
#     - 다익스트라를 통해 1번으로부터 모든 헛간의 최단 거리 구함
#     - 제일 먼 것을 고름
#   - time complexity
#   - space complexity

# 9-2와 거의 동일 
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())

# 인접 리스트 형태 그래프 
graph = [[] for i in range(n + 1)]

distance = [INF] * (n + 1)

# 모든 간선 정보 입력받기
for _ in range(m):
    a, b = map(int, input().split())

    # 양방향이므로 양쪽으로 간선 추가
    graph[a].append(b)
    graph[b].append(a)

# 다익스트라 
q = []
heapq.heappush(q, (0, 1))
distance[1] = 0
while q:
    dist, now = heapq.heappop(q)
    if distance[now] < dist:
        continue

    for i in graph[now]:
        # 모든 간선의 비용 1
        cost = dist + 1
        
        if cost < distance[i]:
            distance[i] = cost
            heapq.heappush(q, (cost, i))

num = 0
maxValue = 0
count = 0
for i in range(1, n + 1):
    if maxValue < distance[i]:
        num = i
        maxValue = distance[i]
        count = 1
    elif maxValue == distance[i]:
        count += 1

print(num, maxValue, count)

