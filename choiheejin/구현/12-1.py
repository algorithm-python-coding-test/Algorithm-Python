score = input()
front = score[0:len(score) // 2]
frontNo = 0
back = score[len(score) // 2: len(score)]
backNo = 0
for ch in front:
    frontNo += int(ch) 

for ch in back:
    backNo += int(ch)

if frontNo == backNo:
    print('LUCKY')
else:
    print('READY')