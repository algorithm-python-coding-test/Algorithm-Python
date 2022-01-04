n = 5
build_frame = [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]
wall = [[0] * (n+1) for _ in range(n+1)]
# 교차점에 아무것도 없으면 0
# 기둥 2
# 보 3
# 기둥 + 기둥 4
# 기둥 + 보 5
# 보 + 보 6
# 기둥 + 보 + 보 8
result = []
for build in build_frame:
    column = build[0]
    row = build[1]
    if (build[2] == 0): # 기둥
        
        # 바닥 위에 있거나
        # 보의 한쪽 끝 위 혹은 기둥 위에 있어야한다.
        if (row != 0 and wall[row][column] == 0) :
            continue
            
        # 기둥 세우기
        if (build[3] == 1):
            wall[row][column] += 2
            wall[row+1][column] += 2
        else:
            wall[row][column] -= 2
            wall[row+1][column] -= 2

    else : # 보
        
        # 한 쪽 끝부분이 기둥 위에 있거나
        onTheGidung = (wall[row][column] == 2
                        or wall[row][column] == 4
                        or wall[row][column+1] == 2
                        or wall[row][column] == 4
                        or wall[row][column] == 5
                        or wall[row][column+1] == 5)
        # 양쪽 끝부분이 다른 보와 동시에 연결되어있어야한다.
        onTheBo = (wall[row][column] == 3 
                    and wall[row][column+1] == 3)
        
        if ((onTheGidung or onTheBo) == False):
            continue
            
        # 보 세우기
        column = build[0]
        row = build[1]
        if (build[3] == 1):
            wall[row][column] += 3
            wall[row][column+1] += 3
        else:
            wall[row][column] -= 3
            wall[row][column+1] -= 3
    
    for i in range(5, -1, -1):
        print(wall[i])
    print()

for column in range(6): # 열
    for row in range(6): # 행
        if (wall[row][column] == 2):
            result.append([column, row, 0])
            wall[row][column] -= 2
            wall[row+1][column] -= 2
        
        elif (wall[row][column] == 3):
            result.append([column, row, 1])
            wall[row][column] -= 3
            wall[row][column+1] -= 3

    


print(result)


