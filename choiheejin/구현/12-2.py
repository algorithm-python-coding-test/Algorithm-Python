inputStr = input()
alpha = []
result = ""
num = 0
for ch in inputStr:
    if (ord(ch) >= 65 and ord(ch) <= 90):
        alpha.append(ch)
    else:
        num += int(ch)

alpha.sort()

for ch in alpha:
    result = result + ch

print(result + str(num))