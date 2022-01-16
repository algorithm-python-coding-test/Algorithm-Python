# - input
#   - 집의 수(N), 도로의 수(M), 도로 정보(X, Y, Z)
# - output
#   - 일부 가로등 비활성화하여 절약할 수 있는 최대 금액
# - constraint
#   - 1 <= N <= 200,000
#   - N - 1 <= M <= 200,000
#   - 도로 길이의 합 (Z의 합) <= 2 ** 31
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 크루스칼 알고리즘 사용하여
#   - 최소비용으로 신장트리를 만들 수 있는 방법을 탐색하고
#   - 도중에 사이클이 만들어질 수 있는 간선의 비용을 모으면 절약 비용이 됨

# 루트 노드 찾기 
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 집합 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n, m = map(int, input().split())
parent = [0] * (n)

edges = []
result = 0

# 부모테이블 자기 자신으로 초기화
for i in range(n):
    parent[i] = i

for i in range(m):
    a, b, cost = map(int, input().split())
    # 비용순 정렬
    edges.append((cost, a, b))

edges.sort()

for edge in edges:
    cost, a, b = edge
    # 사이클이 아니면 두 노드 집합 합치기 
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
    # 사이클이면 두 노드 집합 합치지 않고, 절약할 수 있는 비용에 추가
    else:
        result += cost

print(result)
