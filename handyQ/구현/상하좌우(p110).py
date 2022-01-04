import sys
sys.stdin = open("input_상하좌우.txt")

N = int(input())
D = input().split()

lst =[[0 for _ in range(N)] for _ in range(N)]

p = [1,1]

for d in D:
    if d == 'R' and p[1] != N:
        p[1] += 1

    elif d == 'L' and p[1] != 1:
        p[1] -= 1

    elif d == 'U' and p[0] != 1:
        p[0] -= 1

    elif d == 'D' and p[0] != N:
        p[0] += 1

for i in range(2):
    print(p[i],end=" ")