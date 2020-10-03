def validate(string):
    opening=['(','{','[']
    closing=[')','}',']']
    
    matching={'(':')','[':']','{':'}'}
    stack=[]
    flag=True
    count=0
    for s in string:
        #if bracket is opening
        if s in opening:
            stack.append(s)
        elif s in closing:
            #get topmost element
            try:
                top=stack.pop()
            except:
                #If the stack is empty
                flag=False
                break
            if matching[top]!=s:
                flag=False
                break
        else:
            flag=False
            break
    if len(stack)==0 and flag:
        return True
    else:
        return False

string=input("Enter String to check:")
if validate(string):
    print("Parentheses Matched")
else:
    print("Parentheses Not Matched")
        