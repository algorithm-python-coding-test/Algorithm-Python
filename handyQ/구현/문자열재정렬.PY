# K1KA5CN7
# AJKDLSI412K4JSJ9D

# print(ord('A'),ord('Z'),ord('0'),ord('9'))
# 65 90 48 57

word = input()

alpha = []
num = []

for w in word:
    if ord(w)>=65:
        alpha.append(w)
    else:
        num.append(int(w))

num.sort()
alpha.sort()

for i in range(len(alpha)):
    print(alpha[i],end="")
print(sum(num))




