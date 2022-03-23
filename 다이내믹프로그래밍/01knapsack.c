#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5
void knapsack(int*,int*,int,int);
int main(void){
    int N,capacity;
    printf("아이템의 개수를 입력하세요 : ");
    scanf("%d",&N);
    int* wArr=(int*)malloc(sizeof(int)*N);
    int* vArr=(int*)malloc(sizeof(int)*N);
    printf("knapsack의 capacity를 입력하세요 : ");
    scanf("%d",&capacity);
    for(int i=0;i<N;i++){
        printf("%d번째 아이템의 weight와 value를 입력하세요 : ",i+1);
        scanf("%d %d",&wArr[i],&vArr[i]);
    }
    knapsack(wArr,vArr,capacity,N);
    free(wArr);
    free(vArr);
    return 0;
}
void knapsack(int* wArr, int* vArr, int capacity, int N){
    int** arr=(int**)malloc(sizeof(int*)*(N+1));
    for(int i=0;i<N+1;i++){
        arr[i]=(int*)malloc(sizeof(int)*(capacity+1));
    }
    
    for(int i=0;i<capacity+1;i++){
        arr[0][i]=0;
    }
    for(int i=1;i<N+1;i++){
        arr[i][0]=0;
    }
    for(int i=1;i<N+1;i++){
        for(int W=1;W<capacity+1;W++){
            if(wArr[i-1]<=W){
                if(vArr[i-1]+arr[i-1][W-wArr[i-1]]>arr[i-1][W]){
                    arr[i][W]=vArr[i-1]+arr[i-1][W-wArr[i-1]];
                }
                else{
                    arr[i][W]=arr[i-1][W];
                }
            }
            else{
                arr[i][W]=arr[i-1][W];
            }
        }
    }
    int i=N;
    int j=capacity;
    int stack[STACK_SIZE]={0};
    int stackTop=-1;
    while(arr[i][j]>0){
        if(arr[i-1][j]==arr[i][j])i--;
        else if(arr[i-1][j-wArr[i-1]]==arr[i][j]-vArr[i-1]){
            stack[++stackTop]=i;
            j-=wArr[i-1];
            i--;
        }
    }
    for(int i=0;i<N+1;i++){
        for(int j=0;j<capacity+1;j++){
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("최적의 총 value : %d\n",arr[N][capacity]);
    printf("최적의 item 선정 : ");
    while(stackTop!=-1){
        printf("%d ",stack[stackTop--]);
    }
    for(int i=0;i<N+1;i++){
        free(arr[i]);
    }
    free(arr);
}