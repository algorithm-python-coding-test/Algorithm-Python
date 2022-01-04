import sys

n, m = map(int, input().split())
array = []
for i in range(n):
    array.append(int(input()))

d = [-1] * 10000

for i in range(m+1):
    # i가 제일 작은 화폐보다 작을 경우
    if i < min(array):
        continue
    # i가 화폐 단위와 같을 경우
    elif i in array:
        d[i] = 1
    # i가 제일 작은 화폐보다 클 경우,
    # i보다 작은 화폐만큼 빼보고 그 중에서 결과가 가장 작은 것을 채택하여
    # d[i]에 넣음
    # 만약 모든 화폐 단위에 대하여 d[i-j] = -1일 경우에는 d[i]=-1
    else:
        minV = sys.maxsize
        noAns = True
        for j in array:
            if j > i:
                break
            elif d[i-j] != -1:
                minV = min(minV, 1 + d[i-j])
                noAns = False
        if noAns:
            d[i] = -1
        else:
            d[i] = minV

print(d[i])
