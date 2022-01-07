# - input
#   - 도시 개수(N), 도로 개수(M), 거리 정보(K), 출발 도시 정보 (X)
# - output
#   - 1번 도시에서 출발하여 도착할 수 있는 도시 중 최단 거리 2인 도시
# - constraint
#   - 2 <= N <= 300,000
#   - 1 <= M <= 1,000,000
#   - 1 <= K <= 300,000
#   - 1 <= X <= N
# - edge case
#   - 최단 거리 K인 도시가 존재하지 않으면 -1 출력
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 각 도시 사이의 거리가 같은 조건에서 최단 거리를 구하는 문제 => BFS
#   - algorithm
#       - 인접 리스트 형태로 그래프 표현(단방향 간선)
#       - BFS 알고리즘을 사용하면서
#       - 방문한 도시들의 리스트를 거리의 형태로 표현
#       - BFS로 차례로 거리를 하나씩 더해가면서 구하다가
#       - 꺼낸 노드의 거리가 원하는 최단 거리를 넘게 되면 더이상 거리를 확인할 필요없이
#       - 반복문에서 나와 최단 거리가 K인 도시를 차례대로 출력 (이미 오름차순으로 들어가있을 것이기 때문에 정렬 필요 없음)
from collections import deque

def bfs(graph, start, dist, minimumDistList):
    queue = deque([start])
    ansList = []
    minimumDistList[start] = 0

    while queue:
        a = queue.popleft()
        if minimumDistList[a] > dist:
            break
        for b in graph[a]:
            if minimumDistList[b] == -1:
                queue.append(b)
                minimumDistList[b] = minimumDistList[a] + 1
                if minimumDistList[b] == dist:
                    ansList.append(b)

    for i in ansList:
        print(i)
    if len(ansList) == 0:
        print(-1)


n, m, k, x = map(int, input().split())

graph = [[] for i in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
minimumDistList = [-1] * (n + 1)

    
bfs(graph, x, k, minimumDistList)
