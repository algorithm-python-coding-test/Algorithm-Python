###개인풀이

###시간 내 통과
###최소 0.02,최대 24.28ms

def solution(s):
    answer =[]
    #'},{를 기준으로 나눈 후 숫자로 분리하여 리스트의 길이 순으로 정렬
    #ex) ['2', '2,1', '2,1,3', '2,1,3,4']
    #    [['2'], ['2', '1'], ['2', '1', '3'], ['2', '1', '3', '4']]
    
    s1 = s[2:-2].split('},{')
    s2 = [i.split(',') for i in s1]
    s2.sort(key=lambda x : len(x))
    
    #각 리스트의 차집합 요소를 더해가면서 리스트 완성
    for k in s2:
        num = set(k).difference(set(answer))
        
        answer.append(list(num)[0])
    answer = [int(n) for n in answer]
    return answer

