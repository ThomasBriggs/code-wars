l1= [1, 4, 8, 7, 3, 15]
ans = 8

l2 = [10, 5, 2, 3, 7, 5]
ans2 = 10

def sum_pairs(ints, s):
    #possible_pairs -> pp
    pp = []
    for i in range(len(ints)):
        for j in range(i+1, len(ints)):
            if ints[i] + ints[j] == s:
                pp.append([i,j])
    
    #num_possible_pairs -> npp
    npp = len(pp)
    if npp == 0:
        return None

    best_pair = pp[0]
    for i in range(1, npp):
        if pp[i][0] > best_pair[0]:
            if pp[i][1] < best_pair[1]:
                best_pair = pp[i]

    return best_pair
print(sum_pairs(l1, ans))