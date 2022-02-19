#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#개인 풀이

###


def solution(stones, k):
    
    ##zero_index는 0의 시작 인덱스와 길이를 담은 딕셔너리
    ##ex [1, 3, 4, 2, 1, 0, 3, 1, 4, 0] 인 경우 zero_index = {5: 1, 9: 1}
    
    zero_index = {}
    num=0     
    mx=0
    
    while mx<k:
        
        #전체적으로 1 빼주기  
        stones = [i-1 for i in stones]
        num+=1

        #0값이 추가되었을 경우 딕셔너리에 더해주기
        for p in range(len(stones)):
            if stones[p]==0:
                if p in zero_index:
                    continue
                else:
                    zero_index[p]=1
        print(zero_index)
        for idx in zero_index:
            if zero_index[idx] ==-1:
                continue
            #인덱스의 오른쪽 값(idx+1)에 0이 존재하는 경우 오른쪽 길이 값을 더해주고 idx+1은 -1처리
            # ex {5: 1, 9: 1, 0: 1, 4: 1, 7: 1} -> {5: -1, 9: 1, 0: 1, 4: 2, 7: 1}

            if (idx!=len(stones)-1) and (idx+1 in zero_index) and (zero_index[idx+1]!=-1):
                zero_index[idx]+=zero_index[idx+1]
                zero_index[idx+1] =-1
                
                    
        mx = max(list(zero_index.values()))
        print(zero_index)
    return num-1



#다른사람 풀이

#이진 탐색 적용

def solution(stones, k):
    left = 1
    right = 200000000
    while left <= right:
        temp = stones.copy()
        mid = (left + right) // 2
        cnt = 0
        for t in temp:
            print(t,cnt,mid,left,right)
            if t - mid <= 0:
                cnt += 1
            else:
                cnt = 0
            if cnt >= k:
                break
        if cnt >= k:
            right = mid - 1
        else:
            left = mid + 1
        
    return left

