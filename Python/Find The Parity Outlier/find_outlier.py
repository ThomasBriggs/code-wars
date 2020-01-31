l1 = [2, 4, 6, 8, 10, 3] 
l1_ans = 3

l2 = [2, 4, 0, 100, 4, 11, 2602, 36]
l2_ans = 11

l3 = [160, 3, 1719, 19, 11, 13, -21]
l3_ans = 160

def find_outlier(integers):
    evens = 0
    odds = 0
    result = None
    for i in range(3):
        if integers[i] % 2 == 0:
            evens += 1
        else: 
            odds += 1
    if evens > odds:
        result = True
    else:
        result = False


    for i in integers:
        if result:
            if i % 2 == 1:
                return i
        else:
            if i % 2 == 0:
                return i

print(find_outlier(l2))
