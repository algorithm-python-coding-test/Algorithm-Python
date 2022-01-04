n = int(input())

data = []
for _ in range(n):
    data.append(list(input().split()))

data = sorted(data)

for i in data:
    print(i[0], end=' ')