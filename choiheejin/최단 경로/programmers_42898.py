# - input
#   - m, n : 그래프 정보 
#   - puddles : 웅덩이 노드 배열 
# - output
#   - (1, 1) -> (m, n) 최단 경로의 개수 
# - constraint
#   - 1 <= m, n <= 100
#   - m == 1 && n == 1 인 경우 없음
#   - 0 <= len(puddles) <= 10
#   - (1, 1), (m, n) not in puddles
# - edge case
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - graph : 그래프를 표현한 2차 배열이자 최단 경로를 저장하는 dp테이블 (101로 초기화 후, 웅덩이 있는 곳을 0으로 저장)
#   - algorithm
#     - Dynamic Programming
#     - 모든 간선의 비용 동일하고
#     - 오른쪽 혹은 아랫쪽으로 가기만 하면 최단 경로일 수 있음을 이용하여
#     - 다음과 같이 점화식 설정
#     - graph[(a, b)]는 (1, 1) -> (a, b) 최단 경로 개수라고 할 때,
#     - graph[(a, b)] = graph[(a-1, b)] + graph[(a, b-1)]
#   - time complexity
#     - O(n * m) <= 10000
#   - space complexity
#     - graph <= 10000

def count(a, b, graph):
    
    # (a, b)가 그래프를 벗어나는 경우: 0
    if a < 1 or b < 1:
        return 0
    
    # 점화식
    up = graph[b][a-1]
    if up == 101:
        up = count(a-1, b, graph)
    left = graph[b-1][a]
    if left == 101:
        left = count(a, b-1, graph)
    graph[b][a] = up + left
    return graph[b][a]
    
def solution(m, n, puddles):
    
    # 그래프 표현(인덱스를 맞추기 위해 한줄씩 더 추가)
    graph = [[101] * (m + 1) for _ in range(n + 1)]
    
    # dp(1, 1) : 1
    graph[1][1] = 1
    
    # 웅덩이 있는 곳 : 0
    for i in puddles:
        graph[i[1]][i[0]] = 0
        
    ans = count(m, n, graph)

    return ans % 1000000007

print(solution(4, 3, [[2, 2]]))