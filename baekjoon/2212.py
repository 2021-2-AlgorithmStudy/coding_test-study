sensor = []
dist = []
n = int(input())
k = int(input())
sensor = list(map(int, input().split(' ')))

sensor.sort()
prev = sensor[0]
for item in sensor:
    if item - prev != 0:
        dist.append(item - prev)
    prev = item

dist.sort()
distSize = len(dist)
sumNum = 0
cnt = 0
if n != k:
    for item in dist:
        sumNum += item
        cnt += 1
        if distSize - cnt == k - 1:
            break
print(sumNum)
