# 크루스칼 알고리즘

# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
    
v, e = map(int, input().split())
parent = [0] * (v + 1)

edges = []
result = 0

for i in range(1, v + 1):
    parent[i] = i

for _ in range(e):
    a, b, cost = map(int, input().split())
    # 비용 순으로 정렬하기 위해 튜플의 첫번쨰 원소를 비용으로 설정
    edges.append((cost, a, b))

edges.sort()

for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

print(result)