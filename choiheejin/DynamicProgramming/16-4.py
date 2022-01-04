# - input
#   - n: 병사의 수
#   - array: n명의 병사들의 전투력
# - output
#   - len(d[n-1]): 병사의 수가 최대가 되기 위해 열외해야 하는 병사의 수
# - constraint
#   - 1 <= n <= 2000
#   - 1 <= array[i] <= 10,000,000
# - edge case
#   - d[n-1]
#   - d[0]
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - d: 2차 배열 (array[:i] 동안에 최대의 병사의 수를 남기기 위해 남아야하는 병사들의 배열)
#   - algorithm
#     - dp
#     - 점화식
#       - d[0] = [0]
#       - 0 < i < n에 대하여
#         - array[i] <= array[d[i-1][-1]]이면 d[i] = d[i-1] + i
#         - array[i] > array[d[i-1][-1]]이면 d[i] = d[i-1][:-1] + i
#   - time complexity
#     - O(n)
#   - space complexity
#     - d: 2차 배열(2000 * 2000 = 4,000,000)

n = int(input())
array = list(map(int, input().split()))
d = [[] for i in range(n)]

d[0] = [0]
for i in range(1, n):
    if array[i] <= array[d[i-1][-1]]:
        d[i] = d[i-1]
    else:
        d[i] = d[i-1][:-1]
    d[i].append(i)
    print(d[i])

print(n-len(d[n-1]))

