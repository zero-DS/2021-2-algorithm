import copy
str=input("공간 크기 : ").split()
M=int(str[0])
N=int(str[1])
arr=[]
for i in range(M):
    arr.append([0]*N)
socialDistanceLevel=int(input("거리두기 단계 : "))
str=input("지정석 좌표 : ").split()
fixX=int(str[0])
fixY=int(str[1])
peopleCnt=0
def levelOne(arr,x,y):
    global M,N
    for i in range(M):
        for j in range(N):
            if arr[i][j]==0:
                temp=copy.deepcopy(arr)
                arr[i][j]=1
                if i-1>=0 and arr[i-1][j]!=1:arr[i-1][j]=-1
                if j+1<=N-1 and arr[i][j+1]!=1:arr[i][j+1]=-1
                if i+1<=M-1 and arr[i+1][j]!=1:arr[i+1][j]=-1
                if j-1>=0 and arr[i][j-1]!=1:arr[i][j-1]=-1
                if arr[x][y]==-1:arr=copy.deepcopy(temp)
def levelTwo(arr,x,y):
    global M,N
    for i in range(M):
        for j in range(N):
            if arr[i][j]==0:
                temp=copy.deepcopy(arr)
                arr[i][j]=1
                if i-1>=0 and arr[i-1][j]!=1:arr[i-1][j]=-1
                if j+1<=N-1 and arr[i][j+1]!=1:arr[i][j+1]=-1
                if i+1<=M-1 and arr[i+1][j]!=1:arr[i+1][j]=-1
                if j-1>=0 and arr[i][j-1]!=1:arr[i][j-1]=-1
                if i-1>=0 and j-1>=0 and arr[i-1][j-1]!=1:arr[i-1][j-1]=-1
                if i-1>=0 and j+1<=N-1 and arr[i-1][j+1]!=1:arr[i-1][j+1]=-1
                if i+1<=M-1 and j+1<=N-1 and arr[i+1][j+1]!=1:arr[i+1][j+1]=-1
                if i+1<=M-1 and j-1>=0 and arr[i+1][j-1]!=1:arr[i+1][j-1]=-1
                if arr[x][y]==-1:arr=copy.deepcopy(temp)
def levelThree(arr,x,y):
    global M,N
    diagonal=max(M,N)
    for i in range(M):
        for j in range(N):
            if arr[i][j]==0:
                temp=copy.deepcopy(arr)
                arr[i][j]=1
                for k in range(M):
                    if k!=i: arr[k][j]=-1
                for k in range(N):
                    if k!=j: arr[i][k]=-1
                for k in range(1,diagonal+1):
                    if i-k>=0 and j-k>=0 and arr[i-k][j-k]!=1:arr[i-k][j-k]=-1
                    if i-k>=0 and j+k<=N-1 and arr[i-k][j+k]!=1:arr[i-k][j+k]=-1
                    if i+k<=M-1 and j+k<=N-1 and arr[i+k][j+k]!=1:arr[i+k][j+k]=-1
                    if i+k<=M-1 and j-k>=0 and arr[i+k][j-k]!=1:arr[i+k][j-k]=-1
                if arr[x][y]==-1:arr=copy.deepcopy(temp)
if socialDistanceLevel==1:
    levelOne(arr,fixX,fixY)
elif socialDistanceLevel==2:
    levelTwo(arr,fixX,fixY)
elif socialDistanceLevel==3:
    levelThree(arr,fixX,fixY)
for i in range(M):
    for j in range(N):
        if arr[i][j]==-1:
            print(0,end='')
        else:
            print(arr[i][j],end='')
            peopleCnt+=1
    print()
print("이용할 수 있는 인원은 %d명입니다."%(peopleCnt))