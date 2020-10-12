
n = int(input("entre the number"))
def solution(n):
    prime_nums = []
    for num in range(n):
        if num > 1:                  # all prime numbers are greater than 1
            for i in range(2, num):
                if (num % i) == 0:   # if the no == 0 
                    break
            else:
                prime_nums.append(num)
    return prime_nums
solution(n)