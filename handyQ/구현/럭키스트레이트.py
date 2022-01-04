score = input()

length = len(score)

left = score[:length//2]
# print(left)
right = score[length//2:]
# print(right)

left_sum=0
right_sum=0

for i in range(length//2):
    left_sum += int(left[i])
    right_sum += int(right[i])

if left_sum == right_sum:
    print('LUCKY')
else:
    print('READY')