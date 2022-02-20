###개인 풀이

###효율성 테스트 통과X
from bisect import bisect_left

def solution(k, room_number):
    rooms = [i for i in range(1,k+1)]
    answer = []
    
    for num in room_number:
        if num in rooms:
            answer.append(num)
            rooms.remove(num)
        else:
            idx = bisect_left(rooms, num)
            answer.append(rooms[idx])
            rooms.pop(idx)

    return answer

### 다른사람 풀이

#1)
#최소 162,최대 524 ms
import sys
sys.setrecursionlimit(10000) # 재귀 허용깊이 임의로 지정
#파이썬의 기본 재귀 깊이 제한은 1000

def solution(k, room_number):
    rooms = dict() # {방번호: 바로 다음 빈방 번호}
    for num in room_number:
        print(num)
        chk_in = find_emptyroom(num,rooms)
    return list(rooms.keys())

def find_emptyroom(chk, rooms): # 재귀함수
    
    if chk not in rooms.keys(): # 빈 방이면
        rooms[chk] = chk+1 # rooms에 새 노드 추가
        print('빈방',rooms)
        return chk # 요청한 방

    empty = find_emptyroom(rooms[chk], rooms) # 재귀함수 호출
    rooms[chk] = empty+1 # (배정된 방+1)을 부모노드로 변경
    return empty # 새로 찾은 빈 방

#2)
#최소 139, 최대 461ms
def solution(k, room_number):
    room_dic = {}
    ret = []
    for i in room_number:
        n = i
        visit = [n]
        #방문한 기록이 있을 경우
        while n in room_dic:
            n = room_dic[n]
            visit.append(n)
        #방문 기록에 append
        ret.append(n)
        #다음 노드로 업데이트
        for j in visit:
            room_dic[j] = n+1
    return ret
