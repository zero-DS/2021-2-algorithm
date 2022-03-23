def balance(str):
    stack=[]
    for i in str:
        if i=='[':
            stack.append('[')
        elif i=='(':
            stack.append('(')
        elif i==']':
            if len(stack)==0:
                return 0
            if stack.pop()!='[':
                return 0
        elif i==')':
            if len(stack)==0:
                return 0
            if stack.pop()!='(':
                return 0
    if len(stack)!=0:
        return 0
    return 1
while True:
    str=input()
    if str=='.':
        break
    else:
        if balance(str)==1:
            print("yes")
        else:
            print("no")