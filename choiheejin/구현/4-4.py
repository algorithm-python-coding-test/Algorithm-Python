n, m = map(int, input().split())
x, y, d = map(int, input().split())
count = 1
gameMap = []
dList = [(-1, 0), (0, 1), (1, 0), (0, -1)] # 캐릭터 기준 북동남서 위치
continueGame = False

for i in range(n):
    gameMap.append(list(map(int, input().split())))

gameMap[y][x] = 2

while True:
    continueGame = False

    for i in range(4):
        # 1단계
        d = (d + 3) % 4

        # 2단계
        nextX = x + dList[d][1]
        nextY = y + dList[d][0]

        if (gameMap[nextX][nextY] == 0):
            count += 1
            x = nextX
            y = nextY
            gameMap[x][y] = 2
            print(x, y)
            continueGame = True
            break
    
    # 3단계
    if (continueGame == False):
        nextX = x - dList[d][1]
        nextY = x - dList[d][0]
        if (gameMap[nextX][nextY] == 1):
            print(count)
            break
        else :
            x = nextX
            y = nextY
            