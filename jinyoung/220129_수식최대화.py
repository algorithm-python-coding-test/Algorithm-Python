### 개인풀이

# 스택을 활용한 후위표기법으로 변환 후 계산
# 참고 : 후위표기법[https://jamanbbo.tistory.com/53]

import re

#expression의 숫자와 기호를 분리하여 리스트로 만드는 함수
def expression_split(expression):
    
    #indices는 expression +,-,*의 인덱스 저장
    #prec은 expression에 어떤 계산부호가 들어가 있는지(+-*) 저장
    indices = [i.start() for i in re.finditer('[\+\-\*])', expression)]
    prec = [expression[i] for i in indices]
    
    ex_split = []
    ex_split.append(int(expression[:indices[0]]))
    for k in range(len(indices)-1):
        ex_split.append(expression[indices[k]])
        ex_split.append(int(expression[indices[k]+1:indices[k+1]]))
    ex_split.append(expression[indices[-1]])
    ex_split.append(int(expression[indices[-1]+1:]))

    return ex_split,list(set(prec))

#중위표기법을 후위표기법으로 변환하는 함수
def postfix(ex_split,priority):

    oper_list = []
    number_list = []

    for word in ex_split:
        #숫자일 경우 number_list에 저장
        if type(word) is int:
            number_list.append(word)         
        else:
            #계산부호일 경우 oper_list저장 
            if len(oper_list)==0:
                oper_list.append(word)
            else:
                #두번째 계산부호 부터는 이전의 계산부호와 계산 우선순위를 따짐 
                #이전의 계산부호가 우선순위가 더 높을 경우 pop하여 number_list에 저장
                
                while len(oper_list)>0:
                    if priority[oper_list[-1]]>=priority[word]:
                        operator = oper_list.pop()
                        number_list.append(operator)
                    else:
                        break
                #현재 계산부호 oper_list에 저장
                oper_list.append(word)
    #남은 계산부호 num_list에 옮기기
    while len(oper_list)!=0:
        number_list.append(oper_list.pop())
        
    return number_list

#후위표기법 계산하는 함수
def calculator(number_list):
    
    cal_list = []
    for token in number_list:
        if type(token) is int:
            cal_list.append(token)
        elif token=='+':
            n1=cal_list.pop()
            n2=cal_list.pop()
            cal_list.append(n1+n2)
        elif token=='-':
            n1=cal_list.pop()
            n2=cal_list.pop()
            cal_list.append(n2-n1)
        elif token=='*':
            n1=cal_list.pop()
            n2=cal_list.pop()
            cal_list.append(n1*n2)
        
    return abs(cal_list[0])
    
def solution(expression):

    #ex_split은 expression을 숫자와 기호로 분리한 리스트, prec은 여기서 사용한 계산부호의 리스트
    ex_split,prec = expression_split(expression)
    
    results = []
    
    #사용한 계산 부호에 따라 우선순위 경우의 수 부여하기
    
    if len(prec)==1:
        precs = [{prec[0]:1}]
    elif len(prec)==2:
        precs = [{prec[0]:1,prec[1]:2},{prec[0]:2,prec[1]:1}]
    elif len(prec)==3:
        precs = [{'*': 3,'+': 2,'-': 1},{'*': 3,'+': 1,'-': 2},{'*': 2,'+': 3,'-': 1},
                 {'*': 1,'+': 3,'-': 2},{'*': 1,'+': 2,'-': 3},{'*': 2,'+': 1,'-': 3}]
        
    for sign in precs:
        
        number_list = postfix(ex_split,sign)
        result = calculator(number_list)
        results.append(result)

    return max(results)


### 다른 사람 풀이

def solution(expression):
    operations = [('+', '-', '*'),('+', '*', '-'),('-', '+', '*'),('-', '*', '+'),('*', '+', '-'),('*', '-', '+')]
    answer = []
    for op in operations:
        a = op[0]
        b = op[1]
        temp_list = []
        for e in expression.split(a):
            temp = [f"({i})" for i in e.split(b)]
            print(temp)
            temp_list.append(f'({b.join(temp)})')
            print(temp_list)
        answer.append(abs(eval(a.join(temp_list))))
    return max(answer)
