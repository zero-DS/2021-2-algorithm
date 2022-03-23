#include <stdio.h>
#include <string.h>
#define MAZE_SIZE 5
int directions[8]={0,-1,0,1,1,0,-1,0};
int maze[MAZE_SIZE][MAZE_SIZE]={
    {1,1,0,1,1},
    {0,1,0,1,0},
    {1,1,1,1,0},
    {0,1,0,1,0},
    {1,0,1,1,1}
};
int visited[MAZE_SIZE][MAZE_SIZE]={0};
int path[2][MAZE_SIZE*MAZE_SIZE]={0};
void solve(int,int);
int startX=0,startY=0,endX=4,endY=4;
int pathIdx=0,solvedFlag=0;
int main(void){
    memset(path[0],-1,sizeof(int)*(MAZE_SIZE*MAZE_SIZE));
    memset(path[1],-1,sizeof(int)*(MAZE_SIZE*MAZE_SIZE));
    for(int i=0;i<MAZE_SIZE;i++){
        for(int j=0;j<MAZE_SIZE;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    solve(0,0);
    if(solvedFlag==1){
        printf("\npath -> ");
        for(int i=0;i<pathIdx;i++){
            printf("(%d %d) ",path[0][i],path[1][i]);
        }
    }
    else{
        printf("경로가 존재하지 않습니다.");
    }
}
void solve(int x, int y){
    int flag=0;
    visited[x][y]=1;
    path[0][pathIdx]=x;
    path[1][pathIdx++]=y;
    if(x==endX && y==endY){
        solvedFlag=1;
        return;
    }
    for(int i=0;i<4;i++){
        int newX=x+directions[i*2],newY=y+directions[i*2+1];
        if(newX<0 || newX>=MAZE_SIZE || newY<0 || newY>=MAZE_SIZE || solvedFlag==1 || visited[newX][newY]==1 || maze[newX][newY]==0){
            continue;
        }
        solve(newX,newY);
        flag=1;
    }
    if(flag==0)pathIdx--;
}