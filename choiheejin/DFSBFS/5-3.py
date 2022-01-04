from collections import deque

n, m = map(int, input().split(' '))
map = []
for i in range(n):
    map.append(list(input()))

# graph
graph = []
no = 0
for i in range(n):
    for j in range(m):
        graph.append([])
        if map[i][j] == '0':
            if (j>=1 and map[i][j-1] == '0'):
                graph[no].append(no-1)
            if (j<= m-2 and map[i][j+1] == '0'):
                graph[no].append(no+1)
            if (i>=1 and map[i-1][j] == '0'):
                graph[no].append(no-m)
            if (i<=n-2 and map[i+1][j] == '0'):
                graph[no].append(no+m)
        no += 1
print(graph)

# bfs
visited = [False] * n * m
count = 0

for i in range(n * m):
    # 아직 방문을 하지 않았고, map에서 0인 부분일 경우
    # 아이스크림 개수 하나 올리고 
    # 그 아이스크림에 해당하는 모든 부분 방문 처리
    if (visited[i]==False and map[i//m][i%m]=='0'):
        count += 1

        # bfs 구현
        queue = deque([i])
        visited[i] = True

        while queue:
            v = queue.popleft()
            for i in graph[v]:
                if not visited[i]:
                    queue.append(i)
                    visited[i] = True                

print(count)
