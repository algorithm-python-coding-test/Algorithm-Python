### 개인풀이

import math

def solution(fees, records):

    records_dict = {}
    answer=[]

    #차량별 주차시간 딕셔너리만들기
    for i in records:
        if records_dict.get(i.split()[1]) is not None:
            records_dict[i.split()[1]].append(i.split()[0])
        else:
            records_dict[i.split()[1]] = [i.split()[0]]

    #차량 번호순으로 정렬해서 차량별 총 주차시간계산
    car_list = sorted(list(records_dict.keys()))
    for car in car_list:
        #주차기록이 짝수인경우/홀수인경우로 나누어 계산
        if len(records_dict[car])%2==0:
            total_time = calculate_time(records_dict[car])
        else:
            #홀수인 경우 마지막 기록만 따로 계산하여 더해줌
            total_time = calculate_time(records_dict[car][:-1])
            hour =  23-int(records_dict[car][-1][:2])
            minute = 59-int(records_dict[car][-1][3:])
            time = hour*60+minute
            total_time+=time

        #주차요금 계산
        if total_time <=fees[0]:
            answer.append(fees[1])
        else:
            fee = fees[1]+math.ceil((total_time-fees[0])/fees[2])*fees[3]
            answer.append(fee)

    return answer

#짝수개의 원소를 가지고 있는 주차시간 리스트로 총 주차시간 계산하는 함수
def calculate_time(time_list):
    total_time=0
    for i in range(0,len(time_list),2):
        hour =  int(time_list[i+1][:2])-int(time_list[i][:2])
        minute = int(time_list[i+1][3:])-int(time_list[i][3:])
        time = hour*60+minute
        total_time+=time
    return total_time


### 다른사람 풀이

