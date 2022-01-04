n = int(input())

data = []
for _ in range(n):
    data.append((input().split()))

data = sorted(data, reverse = True)
print(data)
for i in data:
    print(data[i], end=' ')