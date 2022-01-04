from collections import deque

n, k = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))
s, x, y = map(int, input().split())

count = 0
x = [-1, +1, 0, 0]
y = [0, 0, -1, +1]

# 0초에 존재하는 바이러스(시작점) 찾기
queues = {}
for i in range(n):
    for j in range(n):
        if graph[i][j] != 0:
            queue = deque()
            queue.append((i, j))
            queues[graph[i][j]] = queue

# BFS
while count == s:
    for type in queues.keys():
        queue = queues[type]
        (a, b) = queue.popleft()

        for turn in range(4):
            newA = a + x[turn]
            newB = b + y[turn]
            if newA < 0 or newA >= n or newB < 0 or newB >= n or graph[newA][newB] != 0:
                continue
            queue.append((newA, newB))

    for type in queues.keys():
        queue
