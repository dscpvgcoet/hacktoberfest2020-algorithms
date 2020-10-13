# importing collections for ChainMap operations 
import collections 

# initializing dictionaries 
dic1 = { 'a' : 1, 'b' : 2 } 
dic2 = { 'b' : 3, 'c' : 4 } 

# initializing ChainMap 
chain = collections.ChainMap(dic1, dic2) 

# printing chainMap using maps 
print ("All the ChainMap contents are : ") 
print (chain.maps) 

# printing keys using keys() 
print ("All keys of ChainMap are : ") 
print (list(chain.keys())) 

# printing keys using keys() 
print ("All values of ChainMap are : ") 
print (list(chain.values())) 
