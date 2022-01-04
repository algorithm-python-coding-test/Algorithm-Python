n, m = map(int, input().split())

array = []
for i in range(n):
    array.append(int(input()))

# 나올 수 있는 결과 값 중 최댓값이 10000이다.
d = [10001] * (m+1)

# d[0] = 0으로 설정하면 i가 화폐단위와 같을 경우를 따로 처리하지 않아도 1로 처리 가능
d[0] = 0
# 화폐 단위 별로 검사 (2, 3, 5)
for i in range(n):
    # (2~m, 3~m, 5~m)
    for j in range(array[i], m+1):
        if d[j-array[i]] != 10001:
            d[j] = min(d[j], d[j-array[i]] + 1)
    
if d[m] == 10001:
    print(-1)
else:
    print(d[m])