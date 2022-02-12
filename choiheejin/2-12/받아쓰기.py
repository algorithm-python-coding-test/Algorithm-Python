# i -> i,j,l, v -> v, w
# 답안의 길이, 정답의 길이 m
# 비교 테이블 n * m  <= 10,000,000

# 문자 비교
def check(a, b):
    if a == b:
        return True
    elif a == 'i':
        if b == 'j' or b == 'l':
            return True
    elif a == 'v' and b =='w':
        return True
    return False

nlength, mlength = map(int, input().split())
n = input()
m = input()

# 테이블 준비 n * m, 0행 & 0열 초기화 
LCS = [[i for i in range(mlength + 1)]] + [[i + 1] + [0] * (mlength) for i in range(nlength)]

# (1,1) 부터 초기화
for i in range(1, nlength + 1):
    for j in range(1, mlength + 1):
        if check(n[i-1], m[j-1]):
            LCS[i][j] = LCS[i-1][j-1]
        else:
            LCS[i][j] = min(LCS[i][j - 1], LCS[i - 1][j - 1]) + 1

print(LCS[nlength][mlength])

# 시간초과