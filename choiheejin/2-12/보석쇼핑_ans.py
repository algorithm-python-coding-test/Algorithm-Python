# 답안 확인함!!!
# 최대 소요시간: 68.71ms
# 최소 소요시간: 3.42ms

# 투 포인터 알고리즘 사용
# start 변수 end 변수 선언
# start를 0으로 하고 end를 계속 올려가며 조건을 만족하는 구간 찾기
# 찾으면 조건이 만족하지 않을때까지 start를 올려보기
# 최소 구간을 저장하고 다시 end를 올리는 것을 반복
# 구간이 더이상 줄어들지 않으면 탐색 종료
# defaultdict는 데이터 타입을 주면 굳이 초기화를 하지 않아도 기본값으로 초기화된다.
from collections import defaultdict

def solution(gems):
    answer = [0,0]
    candidates = []
    # strat와 end를 모두 0으로 초기화
    start, end = 0,0
    gems_len, gem_kind = len(gems), len(set(gems))
    # 현재 start end 사이에 있는 보석 종류 각각에 대한 개수
    gems_dict = defaultdict(int)

    while True:
        kind = len(gems_dict)
        # start가 오른쪽 끝까지 갔다면 break
        if start == gems_len:
            break
        # start, end 사이에 있는 보석이 모든 종류를 커버한다면
        if kind ==  gem_kind:
            # 정답 후보에 (start, end) 저장
            candidates.append((start, end))
            # gems_dict에 start에 해당하는 보석 -1
            gems_dict[gems[start]] -= 1
            # 만약 방금 지운 보석이 0개가 됐다면 그 키 자체를 지우기
            if gems_dict[gems[start]] == 0:
                del gems_dict[gems[start]]
            # start를 한칸 오른쪽으로 옮기기
            start += 1
            continue
        # end가 오른쪽 끝까지 갔다면 break
        if end == gems_len:
            break
        # kind가 모든 종류를 커버하지 못했다면
        if kind != gem_kind:
            # gems_dict에서 end 자리에 있는 보석 +1
            gems_dict[gems[end]] += 1
            # end를 한칸 오른쪽으로 옮기기
            end += 1
            continue
    
    # candidates들 중 구간이 가장 짧은 것을 골라서
    # answer 리턴
    length = float('inf')
    for s, e in candidates:
        if length > e - s:
            length = e - s
            answer[0] = s + 1
            answer[1] = e
    return answer
