N = 1260
fh = int(N/500)
h = int((N-(fh*500))/100)
ft = int((N-(fh*500)-(h*100))/50)
t = int((N-(fh*500)-(h*100)-(ft*50))/10)
count = fh+h+ft+t
print(count)

# n = 1260
# count = 0
#
# # 큰 단위의 화폐부터 차례대로 확인
# coin_types = [500, 100, 50, 10]
#
# for coin in coin_types:
#     count += n // coin # 해당 화폐로 거슬러 줄 수 있는 동전의 개수 세기
#     n %= coin

# print(count)