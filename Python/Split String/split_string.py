def solution(s):
    sub_strings = []
    if len(s) % 2 == 0:
        for i in range(0, len(s), 2):
            sub_strings.append(s[i:i+2])
    else:
        for i in range(0, len(s)-1, 2):
            sub_strings.append(s[i:i+2])
        sub_strings.append("{}_".format(s[-1]))
    return sub_strings

print(solution("Testt"))