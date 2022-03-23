MAZE_SIZE=5
directions=[0,-1,0,1,1,0,-1,0]
maze=[
    [1,1,0,1,1],
    [0,1,0,1,0],
    [1,1,1,1,0],
    [0,1,0,1,0],
    [1,0,1,1,1]
]
visited=[]
for i in range(MAZE_SIZE):
    lst=[0]*MAZE_SIZE
    visited.append(lst)
path=[]
lst=[-1]*MAZE_SIZE*MAZE_SIZE
lst1=[-1]*MAZE_SIZE*MAZE_SIZE
path.append(lst)
path.append(lst1)
startX=0
startY=0
endX=4
endY=4
pathIdx=0
solvedFlag=0
def solve(x,y):
    global maze,directions,visited,path,endX,endY,pathIdx,solvedFlag
    flag=0
    visited[x][y]=1
    path[0][pathIdx]=x
    path[1][pathIdx]=y
    pathIdx+=1
    if x==endX and y==endY:
        solvedFlag=1
        return
    for i in range(4):
        newX=x+directions[i*2]
        newY=y+directions[i*2+1]
        if newX<0 or newX>=MAZE_SIZE or newY<0 or newY>=MAZE_SIZE or solvedFlag==1 or visited[newX][newY]==1 or maze[newX][newY]==0:
            continue
        solve(newX,newY)
        flag=1
    if flag==0: pathIdx-=1
    
solve(0,0)
for i in range(MAZE_SIZE):
    for j in range(MAZE_SIZE):
        print(maze[i][j],end=' ')
    print()
if solvedFlag==1:
    print("\npath -> ",end='')
    for i in range(pathIdx):
        print("(%d %d) "%(path[0][i],path[1][i]),end='')
else:
    print("경로가 존재하지 않습니다.")
    
    