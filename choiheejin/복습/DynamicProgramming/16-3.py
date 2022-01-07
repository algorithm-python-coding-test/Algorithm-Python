# - input
#   - 상담할 수 있는 일수(N), 상담에 필요한 날(T), 금액(P)
# - output
#   - N일 동안 벌수 있는 최대 금액
# - constraint
#   - 1 <= n <= 500
# - edge case
#   - N일을 넘는 상담은 받을 수가 없다.
# - solution (어떻게 해서 문제를 풀 것인지)
#   - dp[n] = (Tn=1 -> Pn, Tn > 1 -> 0)
#   - dp[i] -> max(그날 잡힌 상담을 받는 경우, 안받는 경우)
#       - 받는 경우: Pi + dp[i+Ti] (i + Ti -1 < N), Pi (i + Ti -1 == N)
#       - 받지 않는 경우: dp[i + 1]

n = int(input())
t = [0] * (n + 1)
p = [0] * (n + 1)
for i in range(1, n + 1):
    a, b = map(int, input().split())
    t[i] = a
    p[i] = b

dp = [0] * (n + 1)

if t[n] == 1:
    dp[n] = p[n]

for i in range(n - 1, 0, -1):
    if i + t[i] - 1 < n:
        dp[i] = max(p[i] + dp[i+t[i]], dp[i + 1])
    elif i + t[i] - 1 == n:
        dp[i] = max(p[i], dp[i + 1])
    else:
        dp[i] = dp[i + 1]

print(dp[1])

