# 모든 시간 데이터를 초 단위 숫자 데이터로 변환해야 한다.
# 마지막의 답을 리턴하기 전에는 초 데이터를 시간 단위 문자열로 변환한다.
# 예를 들어 동영상 재생 시간은 0 ~ 2*60*60+3*60+55
# 동영상 최대 길이는 99*60*60+59*60+59 = 356,400 * 4 = 1.4MB(리스트 타입)
# 동영상 리스트를 모두 0으로 초기화
# 로그를 더하면서 시청구간을 +1
# 시청구간이 제일 큰 구간을 이분탐색으로 찾아냄(여러개 있을 수 있음)
# 구해진 모든 시청 구간에 대하여
# 구한 시청 구간의 길이보다 광고시간이 길 경우,
# '시청 구간 시작점~(시청 구간 시작점+광고시간 길이)' 누적 시간과
# '(시청 구간 끝점-광고시간 길이)~시청 구간 끝점' 누적 시간 중 큰 것을 고름
# 시청 구간 구간의 길이가 광고시간 보다 길거나 같을 경우,
# '시청 구간 시작점~(시청 구간 시작점+광고시간 길이)' 누적 시간을 구함
# 각 시청 구간에 대하여 누적 시간이 제일 큰 것으로 골라 시작점 답으로 리턴
# 누적 시간이 같은 것이 있다면 그 중 제일 빠른 것으로 골라 답으로 리턴

# 시간 문자열을 초 단위 숫자 데이터로 변환
def timeToSeconds(time):
    timeArray = time.split(':')
    return int(timeArray[0]) * 60 * 60 + int(timeArray[1]) * 60 + int(timeArray[2])

def secondsToTime(seconds):
    hour = seconds // 3600
    minute = (seconds % 3600) // 60
    seconds = (seconds % 3600) % 60

    return str(hour) + ':' + str(minute) + ':' + str(seconds)

def searchMaxTerms(play_bar, maxPeople, maxTerms):
    start = 0
    end = len(play_bar) - 1
    index = 0
    while True:
        if maxPeople not in play_bar[index:]:
            break
        start = play_bar.index(maxPeople, index)
        for i in range(start + 1, len(play_bar)):
            if play_bar[i] != maxPeople:
                end = i - 1
                break
        maxTerms.append((start, end))
        index = end + 1
    
def solution(play_time, adv_time, logs):
    play_time = timeToSeconds(play_time)
    adv_time = timeToSeconds(adv_time)
    
    play_bar = [0] * (play_time + 1)
    
    # 로그를 더하면서 시청구간을 +1
    for log in logs:
        start, end = map(timeToSeconds, log.split('-'))
        for i in range(start, end + 1):
            play_bar[i] = play_bar[i] + 1
    
    # 시청구간이 제일 큰 구간을 이분탐색으로 찾아냄(여러개 있을 수 있음)
    maxTerms = []
    searchMaxTerms(play_bar, max(play_bar), maxTerms)
    
    maxScores = []
    for maxTerm in maxTerms:
        start, end = maxTerm
        fromStartScore = 0
        for i in range(start, start + adv_time):
            fromStartScore += play_bar[i]
        # 구한 시청 구간의 길이보다 광고시간이 길 경우,
        # '시청 구간 시작점~(시청 구간 시작점+광고시간 길이)' 누적 시간과
        # '(시청 구간 끝점-광고시간 길이)~시청 구간 끝점' 누적 시간 중 큰 것을 고름
        if adv_time > end - start:
            toEndScore = 0
            for i in range(end - adv_time, end + 1):
                toEndScore += play_bar[i]
            maxScores.append(max(fromStartScore, toEndScore))
            print(secondsToTime(end - adv_time), secondsToTime(end + 1))
        else:
            maxScores.append(fromStartScore)
    
    maxIndex = 0
    maxScore = 0
    for i in range(len(maxScores)):
        if maxScores[i] > maxScore:
            maxScore = maxScores[i]
            maxIndex = i
    print(secondsToTime(maxTerms[maxIndex][0]))
    
    answer = ''
    return answer

solution("02:03:55", "00:14:15", ["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"])