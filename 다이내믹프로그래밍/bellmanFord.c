#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 9999999
int arr[5][5]={
    {INF, INF, INF, -2, INF},
    {-3, INF, 9, INF, INF},
    {7, INF, INF, INF, 2},
    {5, 8, -4, INF, INF},
    {INF, 7, INF, 6, 0}
};
char nameArr[5]={'x','y','z','t','s'};
int getIdx(char);
void bellmanFord();
int main(void){
    int size=strlen(nameArr);
    char target;
    printf("존재하는 노드 : ");
    for(int i=0;i<size;i++){
        printf("%c ",nameArr[i]);
    }
    printf("\n다른 각 정점으로의 최단거리를 구할 노드를 입력하세요 : ");
    scanf("%c",&target);
    bellmanFord();
    int targetIdx=getIdx(target);
    for(int i=0;i<size;i++){
        if(i==targetIdx)continue;
        printf("%c : %d\n",nameArr[i],arr[targetIdx][i]);
    }

    return 0;
}
int getIdx(char c){
    int startIdx=-1;
    int size=strlen(nameArr);
    for(int i=0;i<size;i++){
        if(c==nameArr[i])startIdx=i;
    }
    return startIdx;
}
void bellmanFord(){
    int size=strlen(nameArr);

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                if(i==j || i==k)continue;
                if(arr[i][j]!=INF && arr[k][i]!=INF){
                    if(arr[k][j]>arr[i][j]+arr[k][i]){
                        arr[k][j]=arr[i][j]+arr[k][i];
                    }
                }
            }
        }
    }
}