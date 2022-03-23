#include <stdio.h>
#include <stdlib.h>
void jose(int*,int,int);
void modify(int*,int);
int left;
int main(void){
    int N,CF;
    printf("인원 수를 입력하세요 : ");
    scanf("%d",&N);
    int* circle=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        circle[i]=i+1;
    }
    left=N;
    printf("constant factor를 입력하세요 : ");
    scanf("%d",&CF);
    jose(circle,CF-1,CF);
    free(circle);
    return 0;
}
void jose(int* arr, int start, int cf){
    modify(arr,start);
    int next=start+cf-1;
    while(next>=left){
        next-=left;
    }
    if(left==1){
        printf("마지막 생존자 : %d 번째 사람",arr[next]);
        return;
    }
    jose(arr,next,cf);
}
void modify(int* arr, int target){
    for(int i=target;i<left-1;i++){
        arr[i]=arr[i+1];
    }
    left--;
}