from bisect import bisect_left, bisect_right

# 데이터의 개수 세기
def count_by_range(a, left_value, right_value):
    right_index = bisect_right(a, right_value)
    left_index = bisect_left(a, left_value)
    return right_index - left_index

# 모든 단어를 길이마다 나누어서 저장하기 위한 리스트
array = [[] for _ in range(10001)]
# 모든 단어를 길이마다 나누어서 뒤집어 저장하기 위한 리스트
reversed_array = [[] for in range(10001)]

def solution(words, queries):
    answer = []
    for word in words:
        array[len(word)].append(word)
        reversed_array[len(word)].append(word[::-1])
    
    for i in range(10001):
        array[i].sort()
        reversed_array[i].sord()
    
    for q in queries:
        # 접미사에 와일드카드
        if q[0] != '?':
            res = count_by_range(array[len(q)], q.replace('?', 'a'). q.replace('?', 'z'))
        # 접두사에 와일드카드
        else:
            res = count_by_range(reversed_array[len(q)], q[::-1].replace('?', 'a'), q[::-1].replace('?', 'z'))
        
        answer.append(res)
    return answer