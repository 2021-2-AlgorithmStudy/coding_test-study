input_arr = [[0, 1, 1, 0], [1, 0, 1, 0], [1, 1, 0, 1], [0, 0, 1, 0]]
items = ["A", "B", "C", "D"]
groups = ["A", "AB", "AC", "AD", "BC", "BD",
          "CD", "ABC", "ABD", "ACD", "BCD", "ABCD"]


def find_item_index(str):
    for i in range(len(items)):
        if items[i] == str:
            return i
    return -1


def find_group_index(str):
    if len(str) == 1:
        return 0
    for i in range(len(groups)):
        if groups[i] == str:
            return i
    return -1


def main():
    q = []
    index_size = len(groups)
    output_arr = [[0] * index_size for _ in range(index_size)]

    for item in items:
        q.append(item)

    # queue에 있는 group check
    while len(q) != 0:
        cur_group = q.pop(0)  # string
        cur_group_idx = find_group_index(cur_group)

        # 현재 group에서 연결될 수 있는 경우 탐색, 알파벳 별로 각각 탐색
        for i in range(len(cur_group)):
            item_idx = find_item_index(cur_group[i])

            # 각 알파벳에서 연결될 수 있는 경우 확인하면서 가능한 경우면 다음 group으로 추가해줌
            for j in range(len(input_arr[item_idx])):
                temp = cur_group
                next_group = ""

                if input_arr[item_idx][j] == 1:
                    temp += items[j]
                    l = list(temp)
                    l.sort()

                    for v in l:
                        next_group += v

                    group_idx = find_group_index(next_group)

                    # 중복되는 경우는 걸러줌
                    if group_idx != -1 and output_arr[cur_group_idx][group_idx] == 0:
                        output_arr[cur_group_idx][group_idx] = 1
                        q.append(next_group)
                        print("make group: ", cur_group, "->", next_group)

    # print(output_arr)
    for i in range(len(output_arr)):
        print(groups[i], output_arr[i])


if __name__ == '__main__':
    main()
