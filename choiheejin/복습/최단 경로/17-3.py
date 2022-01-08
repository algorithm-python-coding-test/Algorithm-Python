# - input
#   - 테스트 케이스의 수(T), 각 테스트케이스에서 탐사 공간의 크기(N), 각 칸의 비용
# - output
#   - 테스트 케이스마다 [0][0] => [N-1][N-1]의 위치로 이동하는 최소 비용
# - constraint
#   - 1 <= T <= 10
#   - 2 <= n <= 125
#   - 0 <= 비용 <= 9
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - 다익스트라 
#   - algorithm
#     - 상하좌우로 연결되어있는 형태의 그래프에서 다익스트라를 통해 최소 비용 구하기
#     - 시작노드 비용은 0이 아니라 그 시작지 비용으로 초기화
#     - 서로 연결된 상하좌우 간선의 비용은 목적지의 비용으로 계산
#     - 최단 거리 테이블은 그래프 모양 같이 2차원 리스트 형태로 정리
#   - time complexity
#   - space complexity
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

# 상하좌우 방향 설정
dx = [+1, -1, 0, 0]
dy = [0, 0, +1, -1]

def dijkstra(n, graph, cost):
    q = []

    # 힙에 (비용 정보, 위치(x,y)) 정보형태로 시작지점 집어넣기 
    heapq.heappush(q, (graph[0][0], (0, 0)))
    cost[0][0] = graph[0][0]

    while q:
        nowCost, now = heapq.heappop(q)

        # 이미 처리된 적이 있는 노드라면 무시
        if cost[now[0]][now[1]] < nowCost:
            continue

        # 상하 좌우로 인접한 노드들 확인
        for i in range(4):
            nextY = now[0] + dy[i]
            nextX = now[1] + dx[i]
            
            # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧으면 비용 테이블 갱신 후 q에 집어넣기
            if 0 <= nextY and nextY < n and 0 <= nextX and nextX < n:
                nextCost = nowCost + graph[nextY][nextX]
                if nextCost < cost[nextY][nextX]:
                    cost[nextY][nextX] = nextCost
                    heapq.heappush(q, (nextCost, (nextY, nextX)))

    return cost[n-1][n-1]

t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    
    # 그래프(비용 정보) 2차원 리스트에 담기
    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().split())))
    
    # 그래프 모양대로 최소 비용 테이블 초기화
    cost = [[INF] * n for _ in range(n)]

    # 다익스트라 알고리즘 수행
    ans.append(dijkstra(n, graph, cost))

print(ans)

    