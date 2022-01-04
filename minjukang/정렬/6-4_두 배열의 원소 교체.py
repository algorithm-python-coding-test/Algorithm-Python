n, k = map(int, input().split())

A = []
B = []
max = 0

A=list(map(int, input().split()))

B=list(map(int, input().split()))

A = sorted(A)
B = sorted(B, reverse=True)
c = 0
flag = False
while True:
    for i in range(n):
        if A[0] < B[0]:
            temp = A[0]
            A[0] = B[0]
            B[0] = temp
            c += 1
            A = sorted(A)
            B = sorted(B, reverse=True)
        if k == c:
            a = sum(A)
            flag = True
            break
    if flag == True:
        break

print(a)