#!/usr/bin/env python
# coding: utf-8

# In[ ]:


def solution(places):
    #P의 좌표 리스트
    p_list = [[],[],[],[],[]]
    answer = []
    for k in range(5):
        for i in range(5):
            for j in range(5):
                if places[k][i][j]=='P':
                    p_list[k].append((i,j))

    for k in range(5):
        p = p_list[k]
        #P 좌표의 조합
        num_list=list(combinations([_ for _ in range(len(p))], 2))

        for c1,c2 in num_list:
            #P사이 거리 1인 경우 -> 방역수칙 위배
            if abs(p[c1][0]-p[c2][0]) + abs(p[c1][1]-p[c2][1]) ==1:
                print(1, p[c1],p[c2])
                answer.append(0)
                break
            
            #P사이 거리 2인 경우 
            if abs(p[c1][0]-p[c2][0])+abs(p[c1][1]-p[c2][1]) ==2:
                
                #가로로 2칸 떨어져 있을 경우->사이 칸이 X표시 되어있어야 함
                if abs(p[c1][0]-p[c2][0])==2 and abs(p[c1][1]-p[c2][1])==0:
                    if places[k][int((p[c1][0]+p[c2][0])/2)][p[c1][1]]!='X':
                        answer.append(0)
                        break
                
                #세로로 2칸 떨어져있을 경우->사이 칸이 X표시 되어있어야 함
                if abs(p[c1][0]-p[c2][0])==0 and abs(p[c1][1]-p[c2][1])==2:
                    if places[k][p[c1][0]][int((p[c1][1]+p[c2][1])/2)]!='X':
                        answer.append(0)
                        break
                        
                #대각선으로 위치할 경우->다른 대각선 칸이 X표시 되어있어야 함
                if abs(p[c1][0]-p[c2][0])==1 and abs(p[c1][1]-p[c2][1])==1:
                    if (places[k][p[c1][0]][p[c2][1]]!='X')or(places[k][p[c2][0]][p[c1][1]]!='X'):
                        answer.append(0)
                        break

        else:
            answer.append(1)
    return answer

