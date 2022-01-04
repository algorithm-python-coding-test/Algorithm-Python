# - input
#   - n : 퇴사까지 남은 일 수
#   - (t, p) : 각 예약에 필요한 상담일 수와 금액
# - output
#   - p[0] : 전체 출근일 동안 있을 수 있는 상담 경우의 수 중 나올 수 있는 금액의 최댓값
# - constraint
#   - 1 <= n <= 15
#   - 1 <= t <= 5
#   - 1 <= p <= 1000
# - edge case
#   - t[i] == n - i인 경우
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - t : 리스트
#     - p : 리스트
#   - algorithm
#     - 점화식을 세운 후 dp
#       - t[n-1] = [n-1] (t[n-1]이 1일 경우) / t[n-1] = [] (t[n-1]가 1보다 클 경우)
#       - p[n-1] = p[i] (t[n-1]이 1일 경우) / t[n-1] = 0 (t[n-1]가 1보다 클 경우)
#       - i < n-1 일 때, p[i] + p[i+t[i]] (i일 상담을 예약하면 i+t[i]일부터 상담 예약이 가능)가 
#         p[i+1] (i일 상담을 예약하지 않으면 i+1일부터 상담 예약 가능)보다 
#         크면 t[i] = t[i+t[i]] + i, 작으면 t[i] = t[i+1]
#   - time complexity
#     - O(n**2) -> 1 <= n <= 15이므로 - 안정적
#   - space complexity
#     - 리스트 2개 -> 리스트 하나당 최대 15개 크기 - 안정적

n = int(input())
t = []
p = []
for i in range(n):
    a, b = map(int, input().split())
    t.append(a)
    p.append(b)

for i in range(n-1, -1, -1):
    # d[n-1] 초기화
    # t[n-1]가 1이면 예약 ㄱ
    if i == n-1:
        if t[i] > 1:
            t[i] = []
            p[i] = 0
        else:
            t[i] = [i]

    # t[i]가 남은 출근 일수보다 크면 i일 예약은 안함
    elif t[i] > n - i:
        t[i] = t[i + 1]
        p[i] = p[i + 1]
    # t[i]가 남은 출근 일수보다 같거나 작은 경우
    else:
        # i일 상담을 예약할 경우 최댓값
        if (t[i] == n - i): countA = p[i]
        else: countA = p[i] + p[i+t[i]]

        # i일 상담을 예약하지 않을 경우 최댓값
        countB = p[i+1]
        
        # 두 경우 비교하여 더 클 경우 저장
        a = []
        if (countA >= countB):
            if (t[i] < n - i):
                for j in (t[i+t[i]]):
                    a.append(j)
            a.append(i)
            t[i] = a
            p[i] = countA
        else:
            for j in (t[i+1]):
                a.append(j)
            t[i] = a
            p[i] = countB

print(p[0])
    
    