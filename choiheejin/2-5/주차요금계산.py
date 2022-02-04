import math

# 입차 시간과 출차 시간을 갖고 총 시간을 계산하는 함수
def calTimes(inout):
    inTime, outTime = inout
    outhour, outminute = map(int, outTime.split(':'))
    inhour, inminute = map(int, inTime.split(':'))
    return outhour * 60 + outminute - inhour * 60 - inminute

def solution(fees, records):
    # 각 차 번호에 대하여 입차 출차 시간과 총 시간을 관리한다.
    inout = {}
    times = {}
    # 각 기록에 대하여 
    for record in records:
        time, carNum, inOut = record.split()
        # 입차이면
        if inOut == 'IN':
            # 시간 딕셔너리에 해당 차 데이터가 없다면 0으로 초기화하고 
            if carNum not in times:
                times[carNum] = 0
            # inout에 입차시간을 갱신해준다.
            inout[carNum] = [time, '']
        # 출차이면
        else:
            # 출차 시간을 갱신하고
            inout[carNum][1] = time
            # 총시간을 바로 계산한다.
            times[carNum] += calTimes(inout[carNum])
    # 기록을 모두 처리한 후에도 출차가 되지 않은 차를 찾아
    # 출차 시간을 23:59로 갱신해준뒤 총 시간 계산
    for car in inout.keys():
        if inout[car][1] == '':   
            inout[car][1] = '23:59'
            cost = calTimes(inout[car])
            times[car] += cost
    
    # 차 번호를 정렬
    timeKeys = list(times.keys())
    timeKeys.sort()
    answer = []
    for key in timeKeys:
        # 총시간이 기본 시간을 넘지 않으면 기본 요금
        if times[key] <= fees[0]:
            answer.append(fees[1])
        # 총시간이 기본 시간을 넘으면 추가 요금 계산
        else:
            answer.append(fees[1] + math.ceil((times[key] - fees[0]) / fees[2]) * fees[3])
    return answer