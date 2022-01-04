n = int(input())
x, y = 1, 1
plans = input().split()

for plan in plans:
    if (plan == 'L'):
        y -= 1
        if (y < 1):
            y += 1
    elif (plan == 'R'):
        y += 1
        if (y > n):
            y -= 1
    elif (plan == 'U'):
        x -= 1
        if (x < 1):
            x += 1
    else :
        x += 1
        if (x > n):
            x -= 1

print(x, y)