N=int(input("인원 수를 입력하세요 : "))
CF=int(input("constant factor를 입력하세요 : "))
circle=[]
for i in range(N):
    circle.append(i+1)
left=N
def modify(arr,target):
    global left
    for i in range(target,left-1):
        arr[i]=arr[i+1]
    arr.pop()
    left-=1
def jose(arr,start,cf):
    global left
    modify(arr,start)
    next=start+cf-1
    while next>=left:
        next-=left
    if left==1:
        print("마지막 생존자 :",arr[next],"번째 사람")
        return
    jose(arr,next,cf)
jose(circle,CF-1,CF)