def solution(name):
    name = list(name)
    answer = 0
    i = 0
    
    while True:
        answer += min(ord(name[i])-ord('A'), ord('Z')-ord(name[i])+1)
        name[i] = 'A'
        
        if name.count('A') == len(name) : return answer
        
        left, right = 1,1
        for l in range(1,len(name)):
            if name[i-l] == 'A': left += 1
            else: break
        
        for r in range(1,len(name)):
            if name[i+r] == 'A': right += 1
            else: break
        
        if left < right:
            answer += left
            i -= left
        else:
            answer += right
            i += right
            
            
    return answer
# 테스트 케이스 13, 18, 22, 23, 24, 25, 27 실패
# 모든 테케가 성공하는 답안을 못찾았음 ㅠㅠ 