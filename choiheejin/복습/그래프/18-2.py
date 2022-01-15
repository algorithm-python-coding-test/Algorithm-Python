# - input
#   - 탑승구의 수(G), 비행기의 수(P), 탑승구의 정보(gi)
# - output
#   - 비행기를 최대 몇대까지 도킹할 수 있는가
# - constraint
#   - 1 <= G <= 100,000
#   - 1 <= P <= 100,000
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 어떻게 풀어야될지 모르겠어서 답안 확인했습니다...
#   - 답안풀이 획기적이네요..
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

# 탑승구의 개수 입력받기
g = int(input())
# 비행기의 개수 입력받기
p = int(input())

parent = [0] * (g + 1)

for i in range(1, g + 1):
    parent[i] = i

result = 0
for _ in range(p):
    data = find_parent(parent, int(input()))
    if data == 0:
        break
    union_parent(parent, data, data - 1)
    result += 1

print(result)