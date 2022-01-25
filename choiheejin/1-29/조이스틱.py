# 커서를 옮기는데 필요한 최솟값과
# 알파벳을 바꾸는데 필요한 최솟값을 따로 구한다.

# __BB_B_ 길이:7 0-6 A가 아닌 것만을 찾음 ex) 2,3,5
# 거리 최솟값은 현재 노드에서 가장 가까운 것을 방문 처리하면서 하나씩 거리를 더해감
# 첫노드는 무조건 0

# 알파벳을 바꾸는데 필요한 최솟값
# A-Z 길이: 26 0-25 
# 특정 알파벳에 대하여 왼쪽 방향 오른쪽 방향 두방향 거리 중 최솟값
# 0-25 0-12 -> 오른쪽 방향이 더 짧음 13-25 -> 왼쪽 방향이 더 짧음 
    
# 특정 위치에서 가장 가까운 위치를 찾는 함수
def findClosest(node, length, alphabets, visited):
    left = node
    right = node
    while visited[left]:
        left -= 1
        if left < 0:
            left = len(alphabets) - 1
    while visited[right]:
        right += 1
        if right >= len(alphabets):
            right = 0

    if node > left:
        dFromLeftNode = alphabets[node][0] - alphabets[left][0]
    else:
        dFromLeftNode = length - alphabets[left][0] + alphabets[node][0]
    if right > node:
        dFromRightNode = alphabets[right][0] - alphabets[node][0]
    else:
        dFromRightNode = length - alphabets[node][0] + alphabets[right][0] 
              
    if dFromLeftNode < dFromRightNode:
        return (left, dFromLeftNode)
    return (right, dFromRightNode)
        
    
    
def solution(name):
    alphabets = []
    for i in range(0, len(name)):
        if ord(name[i]) - ord('A') != 0 or i == 0:
            alphabets.append((i, ord(name[i]) - ord('A')))
    acost = 0
    
    for i in range(len(alphabets)):
        if alphabets[i][1] < 13:
            acost += alphabets[i][1]
        else:
            acost += 26 - alphabets[i][1]
    
    lcost = 0
    visited = [False] * len(alphabets)
    visited[0] = True
    node = 0

    while False in visited:
        nextNode, distance = findClosest(node, len(name), alphabets, visited)
        lcost += distance
        visited[nextNode] = True
        node = nextNode
    
    print(acost, lcost)
    
    return acost + lcost

print(solution("ABB"))