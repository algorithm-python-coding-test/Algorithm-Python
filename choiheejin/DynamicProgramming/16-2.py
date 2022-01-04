n = int(input())
array = [[]]
for i in range(n):
    array.append(list(map(int, input().split())))

d = [[0] * i for i in range(n + 1)]

for i in range(n, -1, -1):
    if i == n:
        for j in range(n):
            d[i][j] = array[i][j]
    else:
        for j in range(i):
            d[i][j] = max(d[i+1][j], d[i+1][j+1]) + array[i][j]

print(d[1][0])