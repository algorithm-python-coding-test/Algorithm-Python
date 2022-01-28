import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    print(scoville)
    count = 0
    while scoville:
        a = heapq.heappop(scoville)
        if a >= K:
            return count
        if len(scoville) == 0:
            return -1
        b = heapq.heappop(scoville)
        heapq.heappush(scoville, a + b * 2)
        count += 1
    
    return count