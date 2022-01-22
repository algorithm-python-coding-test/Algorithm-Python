#!/usr/bin/env python
# coding: utf-8

# In[ ]:


def solution(s):
    #길이담을 리스트 sol
    sol = []
    #길이가 1인 경우
    if len(s)==1:
        return 1
    
    #잘라낼 문자열 길이를 나타내는 변수 cut(전체의 절반을 넘어가지 않음)
    for cut in range(1,int(len(s)/2)+1):
        #압축된 문자열 담을 리스트 short
        #문자의 위치 나타내는 변수 start
        short=[]
        start=0
        while start<len(s):
            
            #반복된 문자열 횟수를 나타내는 변수 n
            n=1
            
            #같은 문자 반복될 때마다 n이 1씩 증가
            while s[start+(n-1)*cut:start+n*cut]==s[start+n*cut:start+(n+1)*cut]:
                n+=1
                
            #문자열 반복될 경우 short에 추가, 반복되지 않을 경우 그대로 씀
            if n!=1:
                short.append(str(n)+s[start+(n-1)*cut:start+n*cut])
            else:
                short.append(s[start+(n-1)*cut:start+n*cut])
                
            #start 지점 반복된 문자 다음으로 변경
            start=start+n*cut
        
        #압축된 길이를 계산하여 sol에 추가
        if len(''.join(short))!=0:
            sol.append(len(''.join(short)))
            
    answer = min(sol)
    return answer

