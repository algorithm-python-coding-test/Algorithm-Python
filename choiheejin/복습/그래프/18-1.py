# - input
#   - 여행지의 수(N), 여행 계획에 속한 도시의 수(M)
# - output
#   - 한울이의 여행 계획이 가능한지의 여부를 파악
# - constraint
#   - 1 <= n, m <= 500
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 서로소 집합 알고리즘을 사용하여
#   - 한울이의 계획에 포함된 모든 노드들이 하나의 집합에 속해있는지
#   - 같은 루트 노드를 갖고 있는지 확인
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
parent = [0] * (n + 1)
# 인접 행렬
graph = [[0] * (n + 1)]
# 부모 테이블 초기화 
for i in range(1, n + 1):
    parent[i] = i

for i in range(n):
    row = [0] + list(map(int, input().split()))
    graph.append(row)

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if graph[i][j] == 1:
            union_parent(parent, i, j)

plan = list(map(int, input().split()))
root = find_parent(parent, plan[0])
ans = True
for node in plan:
    if root != find_parent(parent, plan[0]):
        ans = False
    
if ans:
    print('YES')
else:
    print('NO')