# 답안 확인함!!!

# 투 포인터 알고리즘 사용
# start 변수 end 변수 선언
# start를 0으로 하고 end를 계속 올려가며 조건을 만족하는 구간 찾기
# 찾으면 조건이 만족하지 않을때까지 start를 올려보기
# 최소 구간을 저장하고 다시 end를 올리는 것을 반복
# 구간이 더이상 줄어들지 않으면 탐색 종료

from collections import defaultdict


def solution(gems):
    answer = [0, 0]
    candidates = []
    start, end = 0, 0
    gems_len, gem_kind = len(gems), len(set(gems))
    gems_dict = defaultdict(lambda: 0)
    
    while True:
        kind = len(gems_dict)
        if start == gems_len:
            break
        if kind == gem_kind:
            candidates.append((start, end))
            gems_dict[gems[start]] -= 1
            if gems_dict[gems[start]] == 0:
                del gems_dict[gems[start]]
            start += 1
            continue
        if end == gems_len:
            break
        if kind != gem_kind:
            gems_dict[gems[end]] += 1
            end += 1
            continue

    length = float('inf')
    for s, e in candidates:
        if length > e-s:
            length = e-s
            answer[0] = s + 1
            answer[1] = e
    return answer