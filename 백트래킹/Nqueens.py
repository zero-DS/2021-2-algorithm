N=int(input("해답을 알고 싶은 N-Queens 문제의 N을 입력하세요 : "))
arr=[0]*N
flag=0
def check(arr,y):
    for i in range(y):
        if arr[i]==arr[y] or y-i==abs(arr[i]-arr[y]): return False
    return True
def NQ(arr,x):
    global N,flag
    if flag==1:return
    if x==N:
        flag=1
        for i in range(N):
            for j in range(N):
                if j==arr[i]: print("Q",end=' ')
                else: print("_",end=' ')
            print()
        return
    for i in range(N):
        arr[x]=i
        if check(arr,x)==1: NQ(arr,x+1)
NQ(arr,0)