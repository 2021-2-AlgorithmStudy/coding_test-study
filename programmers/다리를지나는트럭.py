def solution(bridge_length, weight, truck_weights):
    answer = 1
    idx = 0
    curWeight = 0
    q = []

    q.append([truck_weights[idx], 1])
    curWeight += truck_weights[idx]
    idx += 1
    while len(q):
        cur = q[0]
        answer += 1
        if answer - cur[1] >= bridge_length:
            q.pop(0)
            curWeight -= cur[0]
        if idx < len(truck_weights):
            if curWeight + truck_weights[idx] <= weight:
                q.append([truck_weights[idx], answer])
                curWeight += truck_weights[idx]
                idx += 1
    return answer


print(solution(100, 100, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]))
