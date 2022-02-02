import math

def calTimes(inout):
    inTime, outTime = inout
    outhour, outminute = map(int, outTime.split(':'))
    inhour, inminute = map(int, inTime.split(':'))
    return outhour * 60 + outminute - inhour * 60 - inminute
def solution(fees, records):
    inout = {}
    times = {}
    for record in records:
        time, carNum, inOut = record.split()
        if inOut == 'IN':
            if carNum not in times:
                times[carNum] = 0
            inout[carNum] = [time, '']
        else:
            inout[carNum][1] = time
            times[carNum] += calTimes(inout[carNum])
    for car in inout.keys():
        if inout[car][1] == '':   
            inout[car][1] = '23:59'
            cost = calTimes(inout[car])
            times[car] += cost
        
    timeKeys = list(times.keys())
    timeKeys.sort()
    answer = []
    for key in timeKeys:
        if times[key] <= fees[0]:
            answer.append(fees[1])
        else:
            answer.append(fees[1] + math.ceil((times[key] - fees[0]) / fees[2]) * fees[3])
    return answer