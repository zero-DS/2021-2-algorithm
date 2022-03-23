STACK_SIZE=5
def knapsack(wArr,vArr,capacity,N):
    arr=[]
    for i in range(N+1):
        arr.append([])
        for j in range(capacity+1):
            arr[i].append(0)
    for i in range(1,N+1):
        for W in range(1,capacity+1):
            if wArr[i-1]<=W:
                if vArr[i-1]+arr[i-1][W-wArr[i-1]]>arr[i-1][W]:
                    arr[i][W]=vArr[i-1]+arr[i-1][W-wArr[i-1]]
                else:
                    arr[i][W]=arr[i-1][W]
            else:
                arr[i][W]=arr[i-1][W]
    i=N
    j=capacity
    stack=[]
    for k in range(STACK_SIZE):
        stack.append(0)
    stackTop=-1
    while arr[i][j]>0:
        if arr[i-1][j]==arr[i][j]:
            i-=1
        elif arr[i-1][j-wArr[i-1]]==arr[i][j]-vArr[i-1]:
            stackTop+=1
            stack[stackTop]=i
            j-=wArr[i-1]
            i-=1
    for i in range(N+1):
        for j in range(capacity+1):
            print("%2d"%(arr[i][j]),end=' ')
        print()
    print("최적의 총 value : %d"%(arr[N][capacity]))
    print("최적의 item 선정 : ",end='')
    while stackTop!=-1:
        print(stack[stackTop],end=' ')
        stackTop-=1
N=int(input("아이템의 개수를 입력하세요 : "))
capacity=int(input("knapsack의 capacity를 입력하세요 : "))
wArr=[]
vArr=[]
for i in range(N):
    print("%d번 째 아이템의 weight와 value를 입력하세요 : "%(i+1),end='')
    string=input().split()
    wArr.append(int(string[0]))
    vArr.append(int(string[1]))
knapsack(wArr,vArr,capacity,N)