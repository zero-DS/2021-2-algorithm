#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void NQ(int*,int);
int check(int*,int y);
int N,flag=0;
int main(void){
    printf("해답을 알고 싶은 N-Queens 문제의 N을 입력하세요 : ");
    scanf("%d",&N);
    int* arr=(int*)malloc(sizeof(int)*N);
    
    NQ(arr,0);
    free(arr);
    return 0;
}
void NQ(int* arr, int x){
    if(flag)return;
    if(x==N){
        flag=1;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j==arr[i])printf("Q ");
                else printf("_ ");
            }
            printf("\n");
        }
        return;
    }
    for(int i=0;i<N;i++){
        arr[x]=i;
        if(check(arr,x))NQ(arr,x+1);
    }
}
int check(int* arr, int y){
    for(int i=0;i<y;i++){
        if(arr[i]==arr[y] || y-i==abs(arr[i]-arr[y]))return 0;
    }
    return 1;
}