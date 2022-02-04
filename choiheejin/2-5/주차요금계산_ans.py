from collections import defaultdict
import math

def solution(fees, records):
    """
    :param fees: 기본 시간(분) 기본 요금(원)	단위 시간(분)	단위 요금(원)
    :param records: 시각, 차량번호, 내역
    :return: 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수 배열에 담아
    """

    def get_minute(time):
        h, m = time.split(":")
        return int(h) * 60 + int(m)

    answer = list()
    parking = dict()
    total = defaultdict(int)

    # 1. records를 통해 총 주차 시간 구하기
    for r in records:
        t, n, f = r.split()  # 시각, 차량번호, 내역
        minute = get_minute(t)   # 분으로 변환
        if n in parking:  # 이미 입차한 경우, 출차로 총 시간 측정
            total[n] += minute - parking[n]
            del parking[n]
        else:   # 입차인 경우
            parking[n] = minute

    # 2. 출차를 안 한 경우 처리
    end_minute = get_minute('23:59')
    for k, v in parking.items():
        total[k] += (end_minute - v)

    # 3. 요금 계산하기
    s1, m1, s2, m2 = fees   # 기본 시간(분) 기본 요금(원) 단위 시간(분) 단위 요금(원)
    for k, v in total.items():
        all = m1  # 기본요금 내기
        if v > s1:
            all += math.ceil((v - s1) / s2) * m2
        answer.append((k, all))

    answer.sort()
    return [a[1] for a in answer]