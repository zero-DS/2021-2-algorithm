INF=9999999
arr=[[0, 8, 3, INF, INF, 13, INF, INF, INF],
    [INF, 0, 2, 1, INF, INF, INF, INF, INF],
    [INF, 3, 0, 9, 2, INF, INF, INF, INF],
    [INF, INF, INF, 0, 4, INF, 6, 2, INF],
    [5, INF, INF, 6, 0, 5, INF, INF, 4],
    [INF, INF, INF, INF, INF, 0, 1, INF, 7],
    [INF, INF, INF, INF, 3, INF, 0, 4, INF],
    [INF, INF, INF, INF, INF, INF, INF, 0, 1],
    [INF, INF, INF, INF, INF, INF, 5, INF, 0]]
path=[[0, 1, 1, 0, 0, 1, 0, 0, 0],
      [0, 0, 2, 2, 0, 0, 0, 0, 0],
      [0, 3, 0, 3, 3, 0, 0, 0, 0],
      [0, 0, 0, 0, 4, 0, 4, 4, 0],
      [5, 0, 0, 5, 0, 5, 0, 0, 5],
      [0, 0, 0, 0, 0, 0, 6, 0, 6],
      [0, 0, 0, 0, 7, 0, 0, 7, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 8],
      [0, 0, 0, 0, 0, 0, 9, 0, 0]]

def floyd(size):
    global arr,path
    for i in range(size):
        for j in range(size):
            for k in range(size):
                if i==j or i==k: continue
                if arr[i][j]!=INF and arr[k][i]!=INF:
                    if arr[k][j]>arr[i][j]+arr[k][i]:
                        arr[k][j]=arr[i][j]+arr[k][i]
                        path[k][j]=path[i][j]
def printPath(size):
    global arr,path
    stack=[]
    for i in range(10):
        stack.append(0)
    stackTop=-1
    for i in range(size):
        for j in range(size):
            print("%d -> %d의 비용 : %2d "%(i+1,j+1,arr[i][j]),end='')
            print("최단경로 : %d"%(i+1),end='')
            insert=j
            while insert!=i:
                stackTop+=1
                stack[stackTop]=insert
                insert=path[i][insert]-1
            while stackTop!=-1:
                print(" -> %d"%(stack[stackTop]+1),end='')
                stackTop-=1
            print()
size=len(arr)
floyd(size)
for i in range(size):
    for j in range(size):
        print("%2d"%(arr[i][j]),end=' ')
    print()
printPath(size)
