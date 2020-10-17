# Python Program to check if string is Palindrome or not
# Allows characters to be of any case
# Allows characters to have any amount of spaces between them

def isPalindromeCaseSpace(s):
    s = s.lower()
    s = s.replace(" ", "")
    return s == s[::-1]


# Driver program
s = 'a2b2 A'
p = isPalindromeCaseSpace(s)
print(p)

#True
