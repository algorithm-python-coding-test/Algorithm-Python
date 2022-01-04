# - input
#   - n: 0번~n번 학생 
#   - m: union/find 연산 개수
#   - 0 a b : union 연산으로 a번 학생과 b번 학생이 속한 팀을 합침
#   - 1 a b : find 연산으로 a번 학생과 b번 학생이 같은 팀에 속하는 지 확인
# - output
#   - find 연산에 대한 결과를 한줄에 하나씩 YES/NO 출력
# - constraint
#   - 1 <= n, m <= 100,000
# - edge case
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - parent: 1차 배열로, 부모 노드를 저장하는 부모 테이블 
#   - algorithm
#     - 서로소 집합 연산 union과 find를 수행
#     - 경로 압축 기법 사용 
#   - time complexity
#     - O(n + m * log(n)) <= 100,000 + 1600,000 = 1700,000 <= 2000,000(1초)
#   - space complexity
#     - parent <= 100,000 = 400KB

def find_parent(parent, a):
    if parent[a] != a:
        parent[a] = find_parent(parent, parent[a])
    return parent[a]

def union_parent(parent, a, b):
    a = find_parent(parent, a) 
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n, m = map(int, input().split())
parent = [i for i in range(n + 1)]
ans = []

for _ in range(m):
    k, a, b = map(int, input().split())
    # union 연산
    if k == 0:
        union_parent(parent, a, b)
    else:
        if find_parent(parent, a) == find_parent(parent, b):
            ans.append("YES")
        else:
            ans.append("NO")
        
for rs in ans:
    print(rs)
