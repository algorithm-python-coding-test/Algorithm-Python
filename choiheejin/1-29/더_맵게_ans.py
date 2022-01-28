import heapq


def solution(scoville, k):
    heapq.heapify(scoville)

    mix_cnt = 0
    while scoville[0] < k:
        # 최소힙은 이진 트리로 구현되므로 제일 앞에 있는 요소가 제일 작은 값
        try:
            heapq.heappush(scoville, heapq.heappop(scoville) + (heapq.heappop(scoville) * 2))
        except IndexError:
            return -1
        mix_cnt += 1

    return mix_cnt