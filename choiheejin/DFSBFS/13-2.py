from collections import deque

# BFS로 0 개수 구하는 함수
def count0(graph):
    newGraph = [item[:] for item in graph]
    visited = [[False] * len(newGraph[0]) for _ in range(len(newGraph))]
    queue = deque()
    x = [-1, +1, 0, 0]
    y = [0, 0, -1, +1]

    for i in range(len(newGraph)):
        print(newGraph[i])

    for i in range(len(newGraph)):
        for j in range(len(newGraph[i])):
            if newGraph[i][j] == 2 and visited[i][j] == False:
                visited[i][j] = True
                queue.append((i, j))

                while queue:
                    (a, b) = queue.popleft()
                    for k in range(4):
                        newA = a + y[k]
                        newB = b + x[k]

                        if newA < 0 or newA >= n or newB < 0 or newB >= m:
                            continue

                        if newGraph[newA][newB] != 1 and visited[newA][newB] == False:
                            newGraph[newA][newB] = 2
                            visited[newA][newB] = True
                            queue.append((newA, newB))

    count = 0
    for i in range(len(newGraph)):
        count += newGraph[i].count(0)
        print(newGraph[i])

    print()
    return count


# n은 행, m은 열
n, m = map(int, input().split())
graph = []
max = 0

for i in range(n):
    graph.append(list(map(int, input().split())))

# 3개의 벽을 세우는 경우의 수
for i in range(n * m):
    if graph[i // m][i % m] != 0:
        continue
    for j in range(i + 1, n * m):
        if graph[j // m][j % m] != 0:
            continue
        for k in range(j + 1, n * m):
            if graph[k // m][k % m] != 0:
                continue
            print(i, j, k)
            graph[i // m][i % m] = 1
            graph[j // m][j % m] = 1
            graph[k // m][k % m] = 1

            count = count0(graph)
            if max < count:
                max = count

            graph[i // m][i % m] = 0
            graph[j // m][j % m] = 0
            graph[k // m][k % m] = 0

print(max)
