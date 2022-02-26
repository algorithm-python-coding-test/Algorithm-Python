#!/usr/bin/env python
# coding: utf-8

# In[ ]:


###개인풀이

###정확성 11/30개 통과
###효율성 통과 못함

def solution(n, k, cmd):
    
    row = [i for i in range(n)]
    num_del = []
    
    for c in cmd:
        # print(k,row,c)
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
    exists = [True for _ in range(n)]
    up = [-1] + [x for x in range(n - 1)]
    down = [x for x in range(1, n)] + [-1]
    deleted = []
    
    for c in cmd:
        op = c[0]
        
        if op == 'U':
            val = int(c.split()[1])
            for _ in range(val):
                k = up[k]
                
        elif op == 'D':
            val = int(c.split()[1])
            for _ in range(val):
                k = down[k]
                
        elif op == 'C':
            if up[k] != -1:
                down[up[k]] = down[k]
            if down[k] != -1:
                up[down[k]] = up[k]
            exists[k] = False
            deleted.append(k)
            k = down[k] if down[k] != -1 else up[k]
            
        elif op == 'Z':
            d = deleted.pop()
            if up[d] != -1:
                down[up[d]] = d
            if down[d] != -1:
                up[down[d]] = d
            exists[d] = True
            
        else:
            raise RuntimeError(op)
    
    return ''.join(['O' if x else 'X' for x in exists])

