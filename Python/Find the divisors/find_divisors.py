def divisors(integer):
    divisors = []
    for i in range(2, int(integer/2)+1):
        print(i)
        print(integer/i)
        if integer%i == 0:
            divisors.append(i)
    if len(divisors) == 0:
        return "{} is prime".format(integer)
    return divisors

print(divisors(13))

