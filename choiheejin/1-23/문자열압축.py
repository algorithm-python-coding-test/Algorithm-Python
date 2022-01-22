# 1부터 len(s)//2 단위로 다 잘라보기 

def cutString(s, i):
    # 완성된 문자열
    answer = ''
    # 똑같은 문자열이 시작되는 지점
    index = 0
    # 반복되는 횟수
    repeat = 1
    # 다음 단위까지의 문자열 인덱스가 실제 인덱스를 넘지 않는지 확인
    while index + (repeat + 1) * i <= len(s):
        # 현재 단위와 다음 단위가 같은 지 비교
        if s[index + (repeat - 1) * i : index + repeat * i] == s[index + repeat * i : index + (repeat + 1) * i]:
            # 같다면 repeat +1 
            repeat += 1
        else:
            if repeat > 1:
                # 반복이 지속되다가 끝났다면 여태 반복된 횟수와 함꼐 반복된 단위를 answer에 더함
                answer = answer + str(repeat) + s[index : index + i]
                # index와 repeat 초기화
                index = index + (repeat) * i
                repeat = 1
            else:
                # 반복이 하나도 되지 않았다면, answer에 그 단위를 그대로 넣고
                answer = answer + s[index:index + i]
                # index 초기화
                index = index + i
    # 다음 단위가 실제 문자열 길이보다 커졌을 경우에 대비하여 answer에 추가되지 못한 문자열을 뒤에 더해줌
    if repeat > 1:
        answer = answer + str(repeat) + s[index:index + i] + s[index + repeat * i:]
    else:
        answer = answer + s[index:]
        
    return answer
    

def solution(s):
    # 단위별로 자른 문자열들을 저장
    array = []
    # 단위별로 문자열 자르기
    for i in range(1, len(s) // 2 + 1):
        array.append(cutString(s, i))
    min = len(s)
    # 최솟값 구하기 
    for e in array:
        if min > len(e):
            min = len(e)
    return min

print(solution("aabbaccc"))