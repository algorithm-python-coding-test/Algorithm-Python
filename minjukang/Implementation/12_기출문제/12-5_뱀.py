n = int(input())
k = int(input())

board = [[0] * n for _ in range(n)]
for i in range(k):
    a, b = map(int, input().split())
    board[a-1][b-1] = 1

rotlist = []
l = int(input())
for i in range(l):
    x, c = input().split()
    rotlist.append((int(x), c))
rot = 0
time = 0
board[0][0] = -1
x = 0
y = 0
for i in range(n):
    print(board[i])
print()
while True:
    for i in range(l):
        if time == rotlist[i][0]:
            if rotlist[i][1] == 'L':
                print(rot)
                if rot == 0:
                    rot = 3
                else:
                    rot -= 1
                print(rotlist[i][1], rot)
            elif rotlist[i][1] == 'D':
                print(rot)
                if rot == 3:
                    rot = 0
                else:
                    rot+=1
                print(rotlist[i][1], rot)
    if rot == 0: #R
        if y+1 >= n or board[x][y+1] == -1:
            break
        if board[x][y+1] == 1 : #오른쪽 사과 o
            board[x][y] = -1
            y+=1
            board[x][y] = -1
            time += 1
        elif board[x][y+1] == 0: #오른쪽 사과 x
            board[x][y] = 0
            y+=1
            board[x][y] = -1
            time += 1
    if rot == 2: #L
        if y-1 <= -1 or board[x][y-1] == -1:
            break
        if board[x][y-1] == 1: #왼쪽 사과 o
            board[x][y] = -1
            y-=1
            board[x][y] = -1
            time += 1
        elif board[x][y-1] == 0: #사과 x
            board[x][y] = 0
            y-=1
            board[x][y] = -1
            time += 1
    if rot == 3: #U
        if x-1 <= -1 or board[x-1][y] == -1:
            break
        if board[x-1][y] == 1: #윗쪽 사과 o
            board[x-1][y] = -1
            x-=1
            board[x][y] = -1
            time += 1
        elif board[x-1][y] == 0: #사과 x
            board[x-1][y] = 0
            x-=1
            board[x][y] = -1
            time += 1
    if rot == 1: #D
        if x+1 >= n or board[x+1][y] == -1:
            break
        if board[x+1][y] == 1: #아랫쪽 사과 o
            board[x][y] = -1
            x+=1
            board[x][y] = -1
            time += 1
        elif board[x+1][y] == 0: #사과 x
            board[x][y] = 0
            x+=1
            board[x][y] = -1
            time += 1
            print("사과없어서 아래로 이동")
    for i in range(n):
        print(board[i])
    print()

print(time)