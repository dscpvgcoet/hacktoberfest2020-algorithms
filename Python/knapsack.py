'''
Program : To maximise the profit by including all the weights such that sum of weights less than total weight of bag.
Also known as knapsack problem . Below are three methods with which , problem can be solved.

For eg:
wt = [5,6,7] # weight array
val = [1,2,3] # value or profit array
Wt = 10  # Total capacity of babg
n = len(wt)

o/p =  3  # as only weight 7 can be include whoose profit is 3.

'''


# 1.Recursive
def rec(wt , val , Wt , n):
    
    
    #if no of elements are zero or Total capcity of bag is zero return zero
    if n==0 or Wt ==0:
        return 0
    # if wt is less than the total weight of bag , then there are 2 choices either include in bag or not
    if wt[n-1] <= Wt:
        return max((val[n-1] +rec(wt , val , Wt - wt[n-1] , n-1)) ,
                     (rec(wt , val , Wt , n-1)))
    
    # if weight is less than total wieght of bag ,we don't include it our bag
    elif wt[n-1] > Wt:
        return rec(wt , val , Wt , n-1)
    
# 2. Memoize Version
def mem(wt , val , Wt , n):
    if n ==0 or Wt ==0:
        return 0
    
    if t[n][Wt]!= -1:
        return t[n][Wt]
    
    if wt[n-1] <= Wt:
        t[n][Wt] = max(val[n-1] + mem(wt , val , Wt-wt[n-1] , n-1) , mem(wt , val , Wt , n-1))
        return t[n][Wt]
    
    else:
        t[n][Wt] = mem(wt , val , Wt , n-1)
        return t[n][Wt]
        
# 3. DP(Bottom -UP)
def bottom_up(wt , val ,Wt , n):
    t = [[0 for i in range(Wt+1)] for _ in range(n+1)]
    
    for i in range(1,n+1):
        for j in range(1,Wt+1):  
            if wt[i-1] <= j:
                t[i][j] = max( (val[i-1] + t[i-1][j - wt[i-1]] ) , (t[i-1][j]))
            else:
                t[i][j] = t[i-1][j]

    return t[n][Wt]            
# ----------------------------------------------------

n = int(input("Enter Total length of weight array:"))
print("Enter weight array values:")
wt = [int(input()) for _ in range(n)]     # [5,6,7] weight array
print()
print("Enter profit array values:")
val =  [int(input()) for _ in range(n)]    #[1,2,3]  value or profit array
print()
Wt = int(input("Enter total capacity of bag:"))    #10   Total capacity of babg


print("Profit is ->" , rec(wt , val , Wt , n))
print("Profit is ->" , mem(wt , val , Wt , n))
print("Profit is ->" , bottom_up(wt , val , Wt , n))