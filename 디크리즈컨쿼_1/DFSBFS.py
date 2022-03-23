from collections import deque
graph={}
vertexNum=int(input("그래프의 정점 개수 입력 : "))
edgeNum=int(input("그래프의 간선 개수 입력 : "))
queue=deque()
visited=[0]*(vertexNum)
found=0
for i in range(vertexNum):
    graph[i]=[]
for i in range(edgeNum):
    print("연결된 두 정점 입력 : ",end='')
    nums=input().split()
    a=int(nums[0])-1
    b=int(nums[1])-1
    graph[a].append(b)
    graph[b].append(a)
startNum=int(input("탐색 시작 지점 입력 : "))
targetNum=int(input("탐색 대상 입력 : "))
def DFS(g, start, target):
    global visited, found
    if found == 1 or visited[start]==1: return
    visited[start]=1
    print(start+1,end=' ')
    if start == target:
        found = 1
        return
    for i in g[start]:
        DFS(g,i,target)
def BFS(g, start, target):
    global visited, found, queue
    if found == 1 or visited[start]==1: return
    visited[start]=1
    print(start+1,end=' ')
    if start == target:
        found = 1
        return
    for i in g[start]:
        if visited[i]==0: queue.append(i)
    while True:
        try:
            BFS(g,queue.popleft(),target)
        except IndexError:
            break
    visited[start]=0

print("Depth First Search : ",end='')
DFS(graph,startNum-1,targetNum-1)
for i in range(vertexNum):
    visited[i]=0
found = 0
print("\nBreadth First Search : ",end='')
BFS(graph,startNum-1,targetNum-1)
