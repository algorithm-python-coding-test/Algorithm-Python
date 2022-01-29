# 상하이동+좌우이동으로 나누어 진행
# 좌우이동은 A가 포함된 경우와 아닐 경우로 나누어서 

def solution(name):
    
    #상하이동 카운트
    cnt_ud = 0
    for s in name:
        num = ord(s)-65
        if num<=12:
            cnt_ud+=num
        else:
            cnt_ud+=abs(num-25)+1
            
    #좌우이동 카운트 -> A가 포함될 경우와 아닌 경우
    if 'A' in name:
        
        #이름의 길이가 1,2,3인 경우와 4이상인 경우 나누어서 실행
        
        if len(name)==1:
            move=0
        
        elif len(name) in [2,3]:
            
            #이름의 길이가 2 or 3인 경우 -> A가 아닌 알파벳이 있을 경우에만 이동
            #A인 경우 1, A가 아닌경우 0으로 나누어서 0인 경우만 카운트
            
            A_binary = [1 if i=='A' else 0 for i in list(name)[1:]]
            move=A_binary.count(0)
        
        else:
            #이름의 길이가 4이상인 경우
            #연속된 A의 문자열 길이와 연속된 A가 아닌 문자열의 길이 담은 cnt_list와
            #해당 항목이 연속된 A인지 아닌지 담는 리스트 A_list
            #EX) 이름이 AABBBABBAA인 경우 
            #    cnt_list = [2,3,1,2,2]
            #    A_list = [1,0,1,0,1]
            
            cnt_n=0
            cnt_A=0
            len_list = []
            A_binary = [1 if list(name)[0]=='A' else 0]

            for i in range(1,len(name)-1):
                if list(name)[i]=='A' and list(name)[i-1]=='A':
                    cnt_A+=1
                elif list(name)[i]=='A' and list(name)[i-1]!='A':
                    len_list.append(cnt_n)
                    A_binary.append(1)
                    cnt_A=1
                elif list(name)[i]!='A' and list(name)[i-1]=='A':
                    len_list.append(cnt_A)
                    A_binary.append(0)
                    cnt_n=1
                elif list(name)[i]!='A' and list(name)[i-1]!='A':
                    cnt_n+=1

            if list(name)[-1]=='A':
                len_list.append(cnt_A+1)
            else:
                len_list.append(cnt_n+1)
        
            
            #기준점이 되는 A에 대해서 나올 수 있는 경우의 수 카운팅
            #1)A로 시작할 경우 -> 끝부분부터 A전까지 진행 -> 첫번째 A빼고 나머지 더하기
            #2)A로 끝날 경우 -> 처음부터 A전까지 더하기
            #3)시작과 끝에 A가 없을 경우 -> 처음부터 A시작 전까지 갔다가 되돌아오기 or 반대방향 출발해서 A끝부분까지 갔다가 돌아오기
            
            route = []
            for k in range(len(A_binary)):
                if A_binary[k]==0:
                    continue
                else:
                    if k==0:
                        route.append(sum(len_list[k+1:]))
                    elif k==len(A_binary):
                        route.append(sum(len_list[:k]))
                    else:
                        route.append(sum(len_list[:k])*2+sum(len_list[k+1:]))
                        route.append(sum(len_list[:k])+sum(len_list[k+1:])*2)
                        
            
            move = min(route)
        
        
    else:
        move=len(name)-1

    answer = cnt_ud+move
        
    return answer

### 5,10,13,20,24,25,27 통과X

