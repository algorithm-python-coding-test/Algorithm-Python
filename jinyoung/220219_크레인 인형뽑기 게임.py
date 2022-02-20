def solution(board, moves):
    
    m,n = len(board),len(board[0])
    stack = []
    answer = 0
    
    for move in moves:
        for i in range(len(board)):
            #전체를 돌면서 0인경우는 continue
            if board[i][move-1]==0:
                continue
            else:
                item = board[i][move-1]
                #아무것도 쌓여있지 않은 경우 stack에 append
                if len(stack)==0:
                    stack.append(item)
                else:
                    #이전것과 비교 후 같으면 answer에 2 더하기
                    st_item = st_item.pop()
                    if item==bf_item:
                        answer+=2
                        
                    else:
                        stack.extend([st_item,item])
                board[i][move-1]=0
                break
            
            
    return answer

