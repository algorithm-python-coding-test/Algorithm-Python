# computers 인접 행렬 방식
# DFS로 풀 수 있을 것같고 하나의 연결된 DFS 탐색이 완료될 때마다 count +1
# visited 관리해서 DFS 탐색이 완료될 때마다 visited에 방문 안된 노드가 있는 지 확인
# 있다면 그것을 시작으로 DFS 탐색
# visited에서 모든 노드가 탐색될때까지 이를 반복
def solution(n, computers):
    count = 0
    visited = [False] * n
    start = 0
    
    while (False in visited):
        for i in range(n):
            if not visited[i]:
                start = i
                break
            
        dfs(computers, visited, start, n)
        count += 1
    
    return count

def dfs(computers, visited, start, n):
    visited[start] = True
    print(start)
    print(visited)
    for i in range(n):
        if not visited[i] and computers[start][i] == 1:
            dfs(computers, visited, i, n)