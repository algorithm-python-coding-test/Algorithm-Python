def go(node, dir):
    if (dir == 0):
        return [node[0]-1, node[1]]
    elif (dir == 1):
        return [node[0], node[1]+1]
    elif (dir == 2):
        return [node[0]+1, node[1]]
    else:
        return [node[0], node[1]-1]

def checkTailDir(turnList, tail, dir):
    for turn in turnList:
        if (len(turn) == 3):
            if tail == turn[2]:
                if turn[1] == 'D':
                    dir += 1
                else:
                    dir -= 1

    return dir


n = int(input())
k = int(input())
head = [0, 0]
tail = [0, 0]
headDir = 1 # 북:0 동:1 남:2 서:3
tailDir = 1
gameMap = [[0] * n for _ in range(n)]
for i in range(k):
    row, column = map(int, input().split())
    gameMap[row - 1][column - 1] = 1

gameMap[0][0] = 2

print(gameMap)

turnList = []
for i in range(int(input())):
    a, b = input().split()
    turnList.append([int(a), b])

count = 0
nextTurn = 0
while True:



    if nextTurn < len(turnList):
        if count == turnList[nextTurn][0]:
            print("머리 턴할 시간입니다. : " + str(count))
            if turnList[nextTurn][1] == 'D':
                headDir = (headDir + 1) % 4
            else:
                headDir = (headDir - 1) % 4
            # 꼬리가 턴해야하는 곳 저장
            turnList[nextTurn].append(head)
            # 다음 턴 저장
            nextTurn += 1

    # 머리 이동
    count += 1
    head = go(head, headDir)
    if (head[0] < 0 or head[0] >= n or head[1] < 0 or head[1] >= n):
        break
    elif (gameMap[head[0]][head[1]] == 2):
        break

    if gameMap[head[0]][head[1]] == 1:
        print("사과 먹었습니다. : " + str(count) )
        gameMap[head[0]][head[1]] = 2

    else:
        print("이동. : "+ str(count) )
        gameMap[head[0]][head[1]] = 2
        tailDir = checkTailDir(turnList, tail, tailDir)
        gameMap[tail[0]][tail[1]] = 0
        tail = go(tail, tailDir)

    for i in gameMap:
        print(i)

print(count)



