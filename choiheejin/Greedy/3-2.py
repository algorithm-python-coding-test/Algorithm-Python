str = input()

n = int(str.split()[0])
m = int(str.split()[1])
k = int(str.split()[2])

list = input().split()
for i in range(len(list)):
    list[i] = int(list[i])
list.sort()

first = list[len(list)-1]
second = list[len(list)-2]
print(list)


a = m // (k + 1)
b = m % (k + 1)
result = (first * k + second) * a + first * b
print(result)