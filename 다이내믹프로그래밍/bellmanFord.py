INF=9999999
arr=[
    [INF, INF, INF, -2, INF],
    [-3, INF, 9, INF, INF],
    [7, INF, INF, INF, 2],
    [5, 8, -4, INF, INF],
    [INF, 7, INF, 6, 0]
]
nameArr=['x','y','z','t','s']
def getIdx(c):
    global nameArr
    startIdx=-1
    for i in range(len(nameArr)):
        if nameArr[i]==c:
            startIdx=i
    return startIdx
def bellmanFord():
    global arr,nameArr
    size=len(nameArr)
    for i in range(size):
        for j in range(size):
            for k in range(size):
                if i==j or i==k: continue
                if arr[i][j]!=INF and arr[k][i]!=INF:
                    if arr[k][j]>arr[i][j]+arr[k][i]:
                        arr[k][j]=arr[i][j]+arr[k][i]

print("존재하는 노드 : ",end='')
for i in range(len(nameArr)):
    print("%c "%(nameArr[i]),end='')
target=input("\n다른 각 정점으로의 최단거리를 구할 노드를 입력하세요 : ")
targetIdx=getIdx(target)
bellmanFord()
for i in range(len(nameArr)):
    if i==targetIdx: continue
    print("%c : %d"%(nameArr[i],arr[targetIdx][i]))