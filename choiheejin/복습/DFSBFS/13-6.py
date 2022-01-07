# - input
#   - 그래프 크기(N), 복도 정보
# - output
#   - 3개의 추가적인 장애물로 모든 학생이 선생님의 감시를 피할 수 있는지 여부 
# - constraint
#   - 3 <= N <= 6
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 선생님이 막힌 부분이 없다면 끝까지 볼 수 있기 때문에 이를 한번에 계산하려면 DFS
#   - algorithm
#      - 3개의 장애물을 설치하는 모든 경우의 수에 대하여 
#      - DFS 게산을 하여 선생님 감시영역 구하기 
#      - 만약 그렇게 했을때 감시영역이 아닌 곳에서 S가 있다면 YES

# 그래프 그리기 
n = int(input())
graph = []
for _ in range(n):
    graph.append(list(input().split()))

# 상하좌우 방향 설정
dx = [0, 0, +1, -1]
dy = [+1, -1, 0, 0]


# DFS로 선생님 감시 영역 구하기
# teacher는 그래프 모양의 감시영역 (감시영역: 1, 감시영역X: 0)
def dfs(i, j, d, teacher):
    global n

    nx = j + dx[d]
    ny = i + dy[d]
    if nx >= 0 and nx < n and ny >= 0 and ny < n:
        if graph[ny][nx] != 'O':
            teacher[ny][nx] = 1
            dfs(ny, nx, d, teacher)
    

# 3개의 장애물 설치하고 학생들이 감시를 피할 수 있으면 True, 없으면 False
def place(nodes):
    global n
    
    # 3개 중 한 위치라도 빈공간이 아닐 경우
    # 아무것도 하지 않고 리턴
    for node in nodes:
        if graph[node // n][node % n] != 'X':
            return False
    
    for node in nodes:
        graph[node // n][node % n] = 'O'

    # 현재 존재하는 모든 'T'에 대하여 dfs를 통해 감시영역 체크 
    # 방향은 상하좌우 방향으로 
    teacher = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if graph[i][j] == 'T':
                teacher[i][j] = 1
                for d in range(4):
                    dfs(i, j, d, teacher)

    # 감시영역이 아닌 곳에 학생이 있을 경우 ans = True
    ans = False
    for i in range(n):
        for j in range(n):
            if teacher[i][j] == 0 and graph[i][j] == 'S':
                ans = True
                break

    for node in nodes:
        graph[node // n][node % n] = 'X'
    
    return ans


# 중복없이 장애물 3개 설치하는 모든 경우에 대하여
# 피할 수 있는 케이스가 있으면 ans = True
# 없으면 False
ans = False
for i in range(n * n):
    for j in range(i + 1, n * n):
        for k in range(j +1, n * n):
            if place([i, j, k]):
                ans = True

if (ans):
    print('YES')
else:
    print('NO')


