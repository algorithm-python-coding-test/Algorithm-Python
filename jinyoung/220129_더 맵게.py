### 개인풀이

import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    for _ in range(len(scoville)):
        i = heapq.heappop(scoville)
        if i >K:
            return answer
        else:
            if len(scoville)==0:
                return -1
            else:
                j = heapq.heappop(scoville)
                n = i+2*j
                heapq.heappush(scoville, n)
                answer+=1
            
    return answer
# 정확도 테스트 통과
# 효율성 테스트 통과

# sort 이용한 풀이
def solution(scoville, K):
    answer = 0
    
    for _ in range(len(scoville)):
        scoville.sort()
        i = scoville.pop(0)
        if i >K:
            return answer
        else:
            if len(scoville)==0:
                return -1
            else:
                j = scoville.pop(0)
                n = i+2*j
                scoville.append(n)
                answer+=1
            
    return answer

# 정확도 테스트 통과
# 효율성 테스트 통과X -> 정렬하는데 시간이 늘어남

### 다른풀이

from heapq import heapify, heappush, heappop
def solution(scoville, K):
    heapify(scoville)
    for i in range(1000000):
        try:
            heappush(scoville, heappop(scoville)+(heappop(scoville)*2))
            if scoville[0] >= K: return i+1
        except:
            return -1
