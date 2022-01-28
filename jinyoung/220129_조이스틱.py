#!/usr/bin/env python
# coding: utf-8

# In[160]:


def solution(name):
    
    #상하이동 카운트
    cnt = 0
    for s in name:
        num = ord(s)-65
        if num<=12:
            cnt+=num
        else:
            cnt+=abs(num-25)+1
    print('cnt:',cnt)

            
    #좌우이동 -> A가 포함될 경우와 아닌 경우
    if 'A' in name:
        
        #이름의 길이가 1,2,3인 경우와 4이상인 경우 나누어서 실행
        if len(name)==1:
            length=0
        elif len(name) in [2,3]:
            #이름의 길이가 2 or 3인 경우 -> A가 아닌 경우만 이동
            lengths = [1 if i=='A' else 0 for i in list(name)[1:]]
            length=lengths.count(0)
        else:
            #이름의 길이가 4이상인 경우
            #연속된 A의 문자열 길이와 연속된 A가 아닌 문자열의 길이 담은 cnt_list와
            #해당 항목이 연속된 A인지 아닌지 담는 리스트 A_list
            #EX) 이름이 AABBBABBAA인 경우 
            #    cnt_list = [2,3,1,2,2]
            #    A_list = [1,0,1,0,1]
            
            cnt_n=0
            cnt_A=0
            cnt_list = []
            A_list = [1 if list(name)[0]=='A' else 0]

            for i in range(1,len(name)-1):
                if list(name)[i]=='A' and list(name)[i-1]=='A':
                    cnt_A+=1
                elif list(name)[i]=='A' and list(name)[i-1]!='A':
                    cnt_list.append(cnt_n)
                    A_list.append(1)
                    cnt_A=1
                elif list(name)[i]!='A' and list(name)[i-1]=='A':
                    cnt_list.append(cnt_A)
                    A_list.append(0)
                    cnt_n=1
                elif list(name)[i]!='A' and list(name)[i-1]!='A':
                    cnt_n+=1

            if list(name)[-1]=='A':
                cnt_list.append(cnt_A+1)
            else:
                cnt_list.append(cnt_n+1)
        
            
            #모든 경우의 수 계산해서 route에 추가
            route = []
            for k in range(len(A_list)):
                if A_list[k]==0:
                    continue
                else:
                    if k==0:
                        route.append(sum(cnt_list[k+1:])*2)
                    elif k==len(A_list):
                        route.append(sum(cnt_list[:k])*2)
                    else:
                        route.append(sum(cnt_list[:k])*2+sum(cnt_list[k+1:]))
                        route.append(sum(cnt_list[:k])+sum(cnt_list[k+1:])*2)
                        
            
            length = min(route)
        
        
    else:
        length=len(name)-1

    answer = cnt+length
        
    return answer

### 7개 테스트 통과 못함

