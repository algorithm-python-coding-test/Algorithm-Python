n, m = map(int, input().split())

map = []
for i in range(n):
    map.append(list(input()))

n -= 1
m -= 1

visited = []
answers = []
count = 0

# DFS로 1인 부분을 탐색하여 (n, m) 일 때의 스택 개수 출력
def dfs(x, y):

    global count
    count += 1

    if x < 0 or x > n or y < 0 or y > m:
        count -= 1
        return

    if x == n and y == m:
        answers.append(count)
        return

    if map[x][y] == "1" and (x, y) not in visited:
        visited.append((x, y))
        dfs(x - 1, y)
        dfs(x + 1, y)
        dfs(x, y - 1)
        dfs(x, y + 1)

    count -= 1


dfs(0, 0)
print(min(answers))
