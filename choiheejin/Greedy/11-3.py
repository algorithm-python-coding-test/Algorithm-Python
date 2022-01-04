s = input()
count0 = 0
count1 = 0
for i in range(len(s)):
    if (s[i] == '0'):
        if (i == 0):
            count0 += 1
        elif (s[i-1] == '1'):
            count0 += 1
    else:
        if (i == 0):
            count1 += 1
        elif (s[i-1] == '0'):
            count1 += 1

if (count0 <= count1) :
    print(count0)
else :
    print(count1)