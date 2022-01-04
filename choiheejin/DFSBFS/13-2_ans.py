# 이 문제는 BFS/DFS 모두 사용해도 괜찮다.
# 답안은 DFS
n, m = map(int, input().split())
data = [] # 초기 맵 리스트
temp = [[0] * m for _ in range(n)] # 벽을 설치한 뒤의 맵 리스트

for _ in range(n):
    data.append(list(int, input().split()))

# 4가지 이동 방향에 대한 리스트
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

result = 0

# DFS로 바이러스가 사방으로 퍼지도록 하기
def virus(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        # 상 하 좌 우 중에서 바이러스가 퍼질 수 있는 경우
        if nx >= 0 and nx < n and ny >= 0 and ny < m:
            if temp[nx][ny] = 2
            virus(nx, ny)

# 안전 영역의 크기 계산하는 메서드
def get_score():
    score = 0
    for i in range(m):
        if temp[i][j] == 0:
            score += 1
    return score


# DFS로 맵에 3개의 벽을 설치(조합), 안전영역의 크기 계산
def dfs(count):
    global result

    # 울타리가 3개 설치된 경우
    if count == 3:
        for i in range(n):
            for j in range(m):
                temp[i][j] = data[i][j]

        # 각 바이러스의 위치에서 전파 진행
        for i in range(n):
            for j in range(m):
                if temp[i][j] == 2:
                    virus(i, j)
        
        # 안전 영역의 최댓값 구하기
        result = max(result, get_score())
        return
    
    # 빈 공간에 울타리 설치
    for i in range(n):
        for j in range(m):
            if data[i][j] == 0:
                data[i][j] = 1
                count += 1
                # count가 3보다 작을 경우: 벽이 덜 세워진 경우로, 첫번째, 두번째, 세번째 함수가 호출될 때까지
                # 벽만 세울 것이다.
                # count가 3이 되는 경우: 세번째 함수 호출 시점으로, 이때 바이러스 확산, 안전영역 최댓값 계산이 실행되며
                # 여태 실행된 경우들 중 안전영역 최댓값을 갱신하고 나면 세번째 함수가 최초로 리턴된다.
                # 세번째 함수가 리턴되면 두번째 함수로 나와서 이전의 벽을 세웠던 것을 허물고 count도 1 줄인다.
                # 두 번째 함수에서 이어서 반복문을 또 실행하고 세번쨰 함수가 또다시 호출된다.
                dfs(count)
                data[i][j] = 0
                count -= 1

# 조합이 재귀를 통해서 구현될 수 있다는 점은 알겠으나 이것이 왜 DFS 인지 잘 모르겠다.
# 단순 재귀 함수와 DFS의 차이는 무엇인가???
                
dfs(0)
print(result)

        


        
