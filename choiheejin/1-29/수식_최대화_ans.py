import re
def solution(expression):
    answer = []
    combinations = [['+','-','*'],['+','*','-'],['-','+','*'],['-','*','+'],['*','-','+'],['*','+','-']]
    for combination in combinations:
        operand = re.split('[*+-]',expression)
        operator = re.split('[0-9]+',expression)[1:-1]
        for comb in combination:
            while comb in operator:
                # index()라는 메서드를 사용하면 해당 값을 가진 인덱스들 중 제일 첫번째를 리턴한다.
                idx = operator.index(comb)
                # 파이썬은 eval(표현식)을 통해 표현식이 리턴하는 값을 리턴받을 수 있다.
                # eval("1+2") = 3
                operand[idx] = str(eval(operand[idx] + comb + operand[idx+1]))
                del operand[idx+1]
                del operator[idx]
        answer.append(abs(int(operand[0])))
    return max(answer)