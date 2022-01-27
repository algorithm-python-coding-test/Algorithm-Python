# 우선순위에 따라 모두 값 계산해보기
# 문자열 파싱해서 리스트로 만들기
# 연산자 리스트와 피연산자 리스트로 만들기
# 우선순위에 따라 계산해보기
from itertools import permutations
import re

# 현재 계산해야할 연산자(operatorNow)를 계산하고 수식을 변경
def cal(operatorNow, operands, operators):
    for i in range(len(operators)):
        # 계산해야할 연산자를 찾으면 피연산자 두개를 찾기
        # 하나는 연산자 바로 오른쪽에 있는 것
        # 하나는 연산자 왼쪽에 있는 것들 중 아직 계산하지 않은 것 (j)
        if operators[i] == operatorNow:
            j = i
            # -1이 아닌 피연산자를 찾기
            while operands[j] == -1:
                j -= 1
                if j == -1:
                    break
            # 왼쪽에 피연산자가 없는 경우 패스
            if j == -1:
                continue

            # 왼쪽 피연산자를 찾은 후에는 연산 결과를 왼쪽 피연산자에 갱신
            if operatorNow == '+':
                operands[j] = operands[j] + operands[i + 1]
            elif operatorNow == '-':
                operands[j] = operands[j] - operands[i + 1]
            elif operatorNow == '*': 
                operands[j] = operands[j] * operands[i + 1]
            
            # 오른쪽 피연산자를 -1로, 해당 연산자를 'X'로 갱신
            operands[i + 1] = -1
            operators[i] = 'X'
                  
def solution(expression):
    
    # 모든 경우의 수 6가지
    priorities = list(permutations(['+', '-', '*']))
    results = []
    
    # 우선순위에 따라 계산
    for priority in priorities:
        operands = list(map(int, re.split(r'[\+\-\*]', expression)))
        operators = re.findall(r'[\+\-\*]',expression)
        for i in range(3):
            cal(priority[i], operands, operators)
        # 제일 왼쪽에 마지막 계산 결과가 모임
        results.append(abs(operands[0]))
        
    return max(results)