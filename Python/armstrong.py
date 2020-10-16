num=int(input("Enter a number"))
n=num
sum = 0

while num>0:
	r = int(num % 10)
	sum = sum + (r**3)
	num = int(num / 10)
if sum == n:
	print(n,"is Armstrong Number")

else:
	print(n,"is not Armstrong Number")