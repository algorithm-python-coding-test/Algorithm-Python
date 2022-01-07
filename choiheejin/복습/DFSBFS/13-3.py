# - input
#   - 시험관 크기(N), 바이러스 종류(K), 그래프, S, X, Y
# - output
#   - S초가 지난 이후 (X, Y)에 존재하는 바이러스의 종류
# - constraint
#   - 1 <= N <= 200
#   - 1 <= K <= 1000
# - edge case
#   - S초 뒤에 해당 위치에 바이러스가 없으면 0 출력
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 가까운 노드부터 차례대로 퍼져나가기 때문에 13-1처럼 => BFS (거리 개념 = 초 개념)
#   - algorithm
#     - 간선은 상하좌우 방향으로 하기 위해 dx, dy 설정 
#     - 점수가 낮은 바이러스부터 정렬하기 위해 처음에 존재하는 바이러스 그룹화 viruses

from collections import deque

# 정보 입력받아서 그래프 그리고 
# 처음에 존재하는 바이러스 그룹화 [[], [(0, 0)] -> 1번, [(0, 2)] -> 2번, [(2, 0)] -> 3번]
# 시간 정보도 그래프 모양대로 준비
n, k = map(int, input().split())
graph = []
time = [[0] * n for _ in range(n)]

viruses = [[] for _ in range(k + 1)]
for i in range(n):
    row = list(map(int,input().split()))
    for j in range(n):
        if row[j] != 0:
            viruses[row[j]].append((i, j))
    graph.append(row)
s, y, x = map(int, input().split())
print(viruses)

# 상하좌우 설정 
dx = [0, 0, +1, -1]
dy = [+1, -1, 0, 0]

# 현재 바이러스 위치를 오름차순으로 큐에 집어넣기 viruses 이용
queue = deque([])
for i in range(1, k + 1):
    for node in viruses[i]:
        queue.append(node)
    
# BFS
while queue:
    now = queue.popleft()
    if time[now[0]][now[1]] > s:
        break
    # 상하좌우로 0인 노드를 now와 같은 바이러스로 채워나가기 & time 그래프도 채우기
    for i in range(4):
        nextY = now[0] + dy[i]
        nextX = now[1] + dx[i]
        if nextY >= 0 and nextY < n and nextX >= 0 and nextX < n:
            if graph[nextY][nextX] == 0:
                graph[nextY][nextX] = graph[now[0]][now[1]]
                queue.append((nextY, nextX))
                time[nextY][nextX] = time[now[0]][now[1]] + 1

# 바이러스가 채워지는 시간이 s초보다 크면 0
# 아니면 바이러스 번호
if time[y-1][x-1] > s:
    print(0)
else:
    print(graph[y-1][x-1])



