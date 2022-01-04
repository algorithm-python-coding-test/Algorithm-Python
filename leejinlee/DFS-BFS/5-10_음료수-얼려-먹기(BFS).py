from collections import deque

n,m= map(int, input().split())
graph=[]
for i in range(n):
    graph.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visit=[[0 for col in range(m)] for row in range(n)]
def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    visit[x][y]=1
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if graph[nx][ny] == 1:
                continue
            if graph[nx][ny] == 0 and not visit[nx][ny]:
                queue.append((nx, ny))
                visit[nx][ny]=1

count=0
for i in range(n):
    for j in range(m):
        if graph[i][j]==0 and visit[i][j]==0:
            bfs(i,j)
            count+=1
print(count)