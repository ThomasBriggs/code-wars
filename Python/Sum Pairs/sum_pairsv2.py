l1= [10, 5, 2, 3, 7, 5]
ans = 10

l2 = [3, 16, 11, 4, 2, 1, 10, 19, 12, 15, 16, 17, 2, 9, 7, 4, 15, 4, 17, 16, 3, 1, 10, 7, 6, 2, 5, 9, 12, 1, 19, 19, 19, 17, 19, 15, 10, 18, 8, 4, 12, 5, 20, 4, 12, 17, 12, 15, 9, 16]

def sum_pairs(ints, s):

    best_pair = [0, len(ints)]
    last_pair = None
    last_i = None
    
    for i in range(len(ints)):
        if last_i == ints[i]:
            pass
        else:
            last_i = ints[i]
            if i >= best_pair[1]:
                return [ints[best_pair[0]], ints[best_pair[1]]]
            for j in range(i+1, best_pair[1]):
                if (last_pair == [ints[i],ints[j]]):
                    pass
                else:
                    last_pair = [ints[i],ints[j]]
                    print("i_index={}, i_value={}\tj_index={}, j_value={}".format(i, ints[i], j, ints[j]))
                    if ints[i] + ints[j] == s:
                        print("found pair ={},{}".format(i,j))
                        if i >= best_pair[0]:
                            if j <= best_pair[1]:
                                best_pair = [i, j]
                                print(best_pair)
    return None
print(sum_pairs(l2, ans))