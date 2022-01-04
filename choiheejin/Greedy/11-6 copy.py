food_times = [1, 1, 3, 2, 4]
k = 8
time = len(food_times)
turn = time
for i in range(1, max(food_times)+1):
    for j in range(len(food_times)):
        if (i == food_times[j]):
            turn -= 1
            food_times[j] = 0
    
    if (k < time + turn):

        a = 0
        for i in len(food_times):
            if (food_times[i] != 0):
                
    else:
        time += turn
    