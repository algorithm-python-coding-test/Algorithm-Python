# - input
#   - 삼각형 크기(n), 삼각형 값 
# - output
#   - 합이 최대가 되는 경로에 있는 수의 합 
# - constraint
#   - 1 <= n <= 500
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 위에서 아래로 바텀업 반복문
#   - dp[i][j] = tri[i][j] + max(dp[i-1][j-1], dp[i-1][j])

n = int(input())
tri = []
for i in range(n):
    tri.append(list(map(int, input().split())))

# 두번째 줄부터 시작 
for i in range(1, n):
    for j in range(i + 1):
        # 제일 왼쪽에 있는 요소는 왼쪽에서 내려올 수 없다. 
        if j == 0:
            left = 0
        else:
            left = tri[i - 1][j - 1]

        # 제일 오른쪽에 있는 요소는 오른쪽에서 내려올 수 없다. 
        if j == i:
            right = 0
        else:
            right = tri[i - 1][j]
        
        tri[i][j] = tri[i][j] + max(left, right)

print(max(tri[n - 1]))

        
