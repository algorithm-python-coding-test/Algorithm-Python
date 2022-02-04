def solution(priorities, location):
  answer = 0
  from collections import deque

  # enumerate()라는 함수를 사용하면 (인덱스, 값) 이런식으로 각 요소의 값을 받아 for문을 돌릴 수 있다.
  # queue 사용  
  d = deque([(v,i) for i,v in enumerate(priorities)])
  
  while len(d):
      # 큐에서 하나를 꺼내어
      item = d.popleft()
      # d에 값이 아직 있고, d에 있는 것들 중 우선순위 최댓값이 0보다 크다면 
      if d and max(d)[0] > item[0]:
          # d를 item의 제일 뒤로 추가
          d.append(item)
      # d에 값이 없거나 꺼낸 값의 우선순위가 대기목록에 있는 것들 중 최대라면
      else:
          # answer +1하고 바로 뒤에 있는 것이 우리가 찾는 것이라면 바로 answer 리턴
          answer += 1
          if item[1] == location:
              break
  return answer