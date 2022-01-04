n, m = map(int, input().split())
mins = []

for i in range(n):
    array = list(map(int, input().split()))
    mins.append(min(array))

print(max(mins))