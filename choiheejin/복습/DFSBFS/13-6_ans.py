n = int(input())
graph = []
for i in range(n):
    graph.append(list(input().split()))
count = 0
result = False

dx = [-1, +1, 0, 0]
dy = [0, 0, -1, +1]

# 특정 노드에서 특정방향으로 가는 동안 S 만나는지 확인
def meetS(nodeX, nodeY, d):
    global graph

    newX = nodeX + dx[d]
    newY = nodeY + dy[d]
    if newX >= 0 and newX < len(graph) and newY >= 0 and newY < len(graph):
        if graph[newX][newY] == "S":
            return True
        elif graph[newX][newY] != "O":
            meetS(newX, newY, d)
    return False


# 조건에 부합하는지 판단
def check():
    global graph

    teachers = []
    for i in range(len(graph) ** 2):
        if graph[i // n][i % n] == "T":
            teachers.append(i)

    for t in teachers:
        x = t // n
        y = t % n

        for j in range(4):
            if meetS(x, y, j):
                return False

    return True


# 장애물 3개 세우기 DFS
def place():
    global graph
    global count
    global result

    if count == 3:
        result = check()
        return

    for i in range(len(graph) ** 2):
        if graph[i // n][i % n] == "X":
            count += 1
            graph[i // n][i % n] = "O"
            place()
            count -= 1
            graph[i // n][i % n] = "X"

place()
if result:
    print("YES")
else:
    print("NO")