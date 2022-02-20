###개인 풀이

###통과 못함


def solution(stones, k):
    
    ##zero_index는 0의 시작 인덱스와 연속되는 0의 길이를 담은 딕셔너리
    ##ex [1, 3, 4, 2, 1, 0, 3, 1, 4, 0] 인 경우 zero_index = {5: 1, 9: 1}
    
    zero_index = {}
    num=0     
    mx=0
    
    while mx<k:
        
        #전체적으로 1 빼주기  
        stones = [i-1 for i in stones]
        num+=1

        #stones에 0값이 추가되었을 경우 zero_index 딕셔너리에 더해주기
        for p in range(len(stones)):
            if stones[p]==0:
                if p in zero_index:
                    continue
                else:
                    zero_index[p]=1
        
        #해당 인덱스(idx)의 오른쪽(idx+1)에 0이 존재하는 경우 
        #해당 인덱스(idx)의 값을 오른쪽(idx+1)의 0의 길이만큼 더해주고 오른쪽(idx+1)의 값은 -1처리 
        
        for idx in zero_index:
            #인덱스의 값이 -1일 경우 넘어가기
            if zero_index[idx] ==-1:
                continue
                
            # ex [1, 3, 4, 2, 1, 0, 3, 1, 4, 0] -> [0, 2, 3, 1, 0, 0, 2, 0, 3, 0]
            # ex {5: 1, 9: 1} -> {5: 1, 9: 1, 0: 1, 4: 1, 7: 1} -> {5: -1, 9: 1, 0: 1, 4: 2, 7: 1}
            if (idx!=len(stones)-1) and (idx+1 in zero_index) and (zero_index[idx+1]!=-1):
                zero_index[idx]+=zero_index[idx+1]
                zero_index[idx+1] =-1
                
                    
        mx = max(list(zero_index.values()))
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

