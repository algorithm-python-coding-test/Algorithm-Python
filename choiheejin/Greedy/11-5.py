n, m = map(int, input().split())
k = list(map(int, input().split()))
length = len(k)
count = []
for i in range(m):
    count.append(0)

for i in range(1, m+1):
    for no in k:
        if (i == no):
            count[i-1] += 1

result = length * (length - 1) // 2

for i in count:
    if (i > 1):
        result -= i * (i-1) // 2

print(result)