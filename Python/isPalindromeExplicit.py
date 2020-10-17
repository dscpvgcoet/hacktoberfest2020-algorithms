# Python Program to check if string is Palindrome or not
# Needs all characters to be of sme case
# Needs all spaces to be evenly distributed from both sides

def isPalindromeCaseSpace(s):
    return s == s[::-1]


# Driver program
s = 'LOL'
p = isPalindromeCaseSpace(s)
print(p)

#True
