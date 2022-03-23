#include <stdio.h>
#include <math.h>
#define INF 9999999
int stack[10]={0};
int stackTop=-1;
int arr[9][9]={ 
0, 8, 3, INF, INF, 13, INF, INF, INF,
INF, 0, 2, 1, INF, INF, INF, INF, INF,
INF, 3, 0, 9, 2, INF, INF, INF, INF,
INF, INF, INF, 0, 4, INF, 6, 2, INF,
5, INF, INF, 6, 0, 5, INF, INF, 4,
INF, INF, INF, INF, INF, 0, 1, INF, 7,
INF, INF, INF, INF, 3, INF, 0, 4, INF,
INF, INF, INF, INF, INF, INF, INF, 0, 1,
INF, INF, INF, INF, INF, INF, 5, INF, 0 
};
int path[9][9]={
    0, 1, 1, 0, 0, 1, 0, 0, 0,
    0, 0, 2, 2, 0, 0, 0, 0, 0, 
    0, 3, 0, 3, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 4, 0, 4, 4, 0,
    5, 0, 0, 5, 0, 5, 0, 0, 5,
    0, 0, 0, 0, 0, 0, 6, 0, 6,
    0, 0, 0, 0, 7, 0, 0, 7, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 8,
    0, 0, 0, 0, 0, 0, 9, 0, 0
};
void floyd(int);
void printPath(int);
int main(void){
    int size=sqrt(sizeof(arr)/sizeof(int));
    
    floyd(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printPath(size);
    return 0;
}
void floyd(int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                if(i==j || i==k)continue;
                if(arr[i][j]!=INF && arr[k][i]!=INF){
                    if(arr[k][j]>arr[i][j]+arr[k][i]){
                        arr[k][j]=arr[i][j]+arr[k][i];
                        path[k][j]=path[i][j];
                    }
                }
            }
        }
    }
}
void printPath(int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d -> %d의 비용 : %2d ",i+1,j+1,arr[i][j]);
            printf("최단경로 : %d",i+1);
            int insert=j;
            while(insert!=i){
                stack[++stackTop]=insert;
                insert=path[i][insert]-1;
            }
            while(stackTop!=-1){
                printf(" -> %d",stack[stackTop--]+1);
            }
            printf("\n");
        }
    }
}