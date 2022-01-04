inputs = list(map(int, list(input())))
print(inputs)
result = inputs[0]
inputs = inputs[1: len(inputs)]

for no in inputs:
    if (no < 2 or result < 2):
        result += no
    else:
        result *= no

print(result)