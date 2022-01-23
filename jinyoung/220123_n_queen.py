#!/usr/bin/env python
# coding: utf-8

# In[ ]:


def dfs(x,y,n,graph):
    if x<=-1 or x>=n or y<=-1 or y>=n:
        return False
    if graph[x][y]==0:
        for p in range(n):
            graph[x][p]=1
            graph[p][y]=1
            graph[abs(x-p)][abs(y-p)]=1
        dfs(x+1,y,n,graph)
        dfs(x,y+1,n,graph)
        return True
        
    return False

def solution(n):
    graph = [[0]*n for _ in range(n)]
    result=0
    for i in range(n):
        for j in range(n):
            if dfs(i,j,n,graph)==True:
                s = 0
                for i in graph:
                    for j in i:
                        s+=j
                if n*n-s==n:
                    result+=1

