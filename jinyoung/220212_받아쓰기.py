#!/usr/bin/env python
# coding: utf-8

# In[4]:


n, m = map(int, input().split())
answer = input()
corr = input()

answer = ' '+answer
corr=' '+corr
Distance = [[0]*(n) for _ in range(m)]
Distance[0] = [i for i in range(n)]
for j in range(m):
    Distance[j][0]=j

for i in range(1,m):
    for j in range(1,n):

        if answer[i]==corr[j] or (answer[i]=='i' and corr[j] in ['i','j','l']) or (answer[i]=='v' and corr[j] in ['v','w']):
            Distance[i][j]=Distance[i-1][j-1]
        else:
            Distance[i][j]=min(Distance[i][j-1],Distance[i-1][j],Distance[i-1][j-1])+1
            
print(Distance[-1][-1])

# 메모리 230564KB
# 시간 4060ms

