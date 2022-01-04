# - input
#   - n : 강의의 수
#   - cost, [1, 2, 3,...], -1: 강의 시간, 선수강의 번호, -1
# - output
#   - N개의 강의를 수강하는데 걸리는 최소 시간 
# - constraint
#   - 1 <= n <= 500
#   - 1 <= cost <= 100,000
# - edge case
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - graph: 2차 배열, 노드 간선 정보를 저장하는 인접 리스트
#     - q: 큐
#     - indegree: 1차 배열, 진입 차수 저장
#     - result : 최소 강의 수강 시간
#     - cost : 강의 시간 저장 
#   - algorithm
#     - 위상 정렬 
#     - 동시에 여러 강의를 수강할 수 있으므로 위상 정렬로 나올 수 있는 경우 중,
#     - 큐에 들어가는 강의가 2개 이상일때 강의 시간이 최소인것만을 집어넣으면 될 것 같다...!
#   - time complexity
#     - O(n + m) <= 500 + 100,000
#   - space complexity
#     - graph: 500 * 500 = 250,000 = 900KB
#     - q: 500
#     - indegree: 500

from collections import deque
import copy

n = int(input())
graph = [[] for i in range(n + 1)]
cost = [0] * (n + 1)
indegree = [0] * (n + 1)
for i in range(n):
    array = list(map(int, input().split()))
    # cost 저장
    cost[i + 1] = array[0]
    for j in range(1, len(array) - 1):
        # 간선 정보 저장
        graph[array[j]].append(i + 1)
        indegree[i + 1] += 1

def topology_sort():
    q = deque()

### 포기!! 좀 더 고민하겠슴다ㅠ 







