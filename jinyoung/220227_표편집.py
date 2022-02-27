###개인풀이

###정확성 11/30개 통과 
###효율성 통과 못함 -> 연결리스트나 힙을 이용해서 삽입삭제 시간 복잡도를 줄이는 것이 포인트!

def solution(n, k, cmd):
    
    #현재 행을 나타내는 리스트 row와 삭제한 행의 정보가 들어가는 리스트 num_del
    row = [i for i in range(n)]
    num_del = []
    
    for c in cmd:

        if c[0]=='D':
            k = k+int(c[2])
        elif c[0]=='U':
            k = k-int(c[2])
        elif c=='C':
            num_del.append((k,row.pop(k)))
            if k==len(row):                
                k=k-1
        elif c=='Z':
            info = num_del.pop(-1)
            row.insert(info[0],info[1])
            if info[0]<=k:
                k+=1
                
    answer = ['X']*n
    for num in row:
        answer[num]='O'
    answer = ''.join(answer)
        
        
    return answer

###다른사람풀이

def solution(n, k, cmd):
    
    answer = ''

    linked_list = {i: [i - 1, i + 1] for i in range(1, n+1)} #n=8일때 1~8까지
    #ex) linked_list = {1: [0, 2], 2: [1, 3], 3: [2, 4], 4: [3, 5], 5: [4, 6], 6: [5, 7], 7: [6, 8], 8: [7, 9]}
    
    OX = ["O" for i in range(1,n+1)]
    stack = []
    k += 1

    for c in cmd:
        if c[0] == 'D':
            for _ in range(int(c[2:])):
                k = linked_list[k][1]
                
        elif c[0] == 'U':
            for _ in range(int(c[2:])):
                k = linked_list[k][0]
                
        elif c[0] == 'C':
            prev, next = linked_list[k]
            stack.append([prev, next, k])
            OX[k-1] = "X"
            
            
            #k값 업데이트(현재행이 마지막일 경우/아닐경우 나누어서)
            if next == n+1:
                k = linked_list[k][0]
            else:
                k = linked_list[k][1]
                
            #prev와 next값을 따라 링크드 리스트 업데이트
            if prev == 0:
                linked_list[next][0] = prev
            elif next == n+1:
                linked_list[prev][1] = next
            else:
                linked_list[prev][1] = next
                linked_list[next][0] = prev
            print(linked_list)

        elif c[0] == 'Z':
            prev, next, now = stack.pop()
            OX[now-1] = "O"
            
            #최근에 지운 prev, next,now 값을 pop해서 링크드 리스트 업데이트
            if prev == 0:
                linked_list[next][0] = now
            elif next == n+1:
                linked_list[prev][1] = now
            else:
                linked_list[prev][1] = now
                linked_list[next][0] = now


    return "".join(OX)
