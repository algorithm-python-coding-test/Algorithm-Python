def turnKey(key):
    newKey = []

    for i in range(len(key)):
        newRow = []
        for j in range(len(key)-1, -1, -1):
            newRow.append(key[j][i])
        newKey.append(newRow)
    
    return newKey

key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
lock = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]

if (key == lock):
    print('True')

else:
    key 

print(turnKey(key))
