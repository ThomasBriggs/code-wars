l1= [10, 5, 2, 3, 7, 5]
ans = 10

l2 = [3, 16, 11, 4, 2, 1, 10, 19, 12, 15, 16, 17, 2, 9, 7, 4, 15, 4, 17, 16, 3, 1, 10, 7, 6, 2, 5, 9, 12, 1, 19, 19, 19, 17, 19, 15, 10, 18, 8, 4, 12, 5, 20, 4, 12, 17, 12, 15, 9, 16]
l3 = [3, 5, 1, 6, 8, 3, 6, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 7, 8]

def sum_pairs(ints, s):

    seen_ints = []
    last_num = None
    for i in range(len(ints)):
        current_num = ints[i]
        if current_num == last_num:
            pass
        else:
            last_num = current_num
            needed_num = s - current_num
            for j in seen_ints:
                if j == needed_num:
                    return [needed_num, current_num]
            seen_ints.append(current_num)

def sum_pairs_v2(ints, s):

    seen_ints = []
    last_num = None
    for i in range(len(ints)):
        current_num = ints[i]
        if current_num == last_num:
            pass
        else:
            last_num = current_num
            needed_num = s - current_num
            if needed_num in seen_ints:
                return [needed_num, current_num]
            seen_ints.append(current_num)

            

print(sum_pairs_v2(l3, 12))
