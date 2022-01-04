# - input
#   - n : 집(노드)의 개수
#   - m : 길(간선)의 개수
#   - a, b, c : 길의 정보로, a와 b를 연결하는 비용 c
# - output
#   - 마을을 두 개로 나누고, 각 마을에서 임의의 집 두 개에 대한 경로가 존재하는 경우의 각 길의 유지비 합의 최솟값 
# - constraint
#   - 1 <= n, m <= 1000,000
# - edge case
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - parent : 1차 배열, 부모 노드를 저장하는 부모 테이블
#     - edges : 간선 배열
#     - maxC : 최소 신장 트리 길 비용 중 최댓값 
#     - result : 최소 비용 
#   - algorithm
#     - 크루스칼 알고리즘을 이용한 최소 신장트리 구하기
#     - 하나의 신장 트리를 구한다음 비용이 가장 큰 간선 삭제
#   - time complexity
#     - O(m * logm) <= 1000,000 * 6
#   - space complexity
#     - parent <= 1000,000 = 4MB
#     - edges <= 1000,000 = 4MB
#     - rsEdges
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
    
n, m = map(int, input().split())
parent = [i for i in range(n + 1)]

edges = []
result = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))

edges.sort()
maxC = 0

for edge in edges:
    c, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        maxC = c
        union_parent(parent, a, b)
        result += c


print(result - maxC)

#### 시간 초과!!!!!
