#!/usr/bin/env python
# coding: utf-8

# In[1]:


###개인풀이

def solution(s):
    word_dict = {'zero':0,'one':1,'two':2,'three':3,'four':4,'five':5,
                 'six':6,'seven':7,'eight':8,'nine':9}
    word = ''
    answer = ''
    
    for letter in s:
        if ord(letter)>=97 and ord(letter)<=122:
            word+=letter
            if word in word_dict:
                answer+=str(word_dict[word])
                word=''
        else:
            answer+=letter
    
    return int(answer)

