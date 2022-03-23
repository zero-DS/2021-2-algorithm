#include <stdio.h>
#include <stdlib.h>
void insertionSort(int*,int,int);
void insert(int);
int N,checkNum;
int main(void){
    int* arr;
    printf("정렬할 배열의 크기를 입력하세요 : ");
    scanf("%d",&N);
    arr=(int*)malloc(sizeof(int)*N);
    printf("정렬할 배열을 입력하세요 : \n");
    for(int i=0;i<N;i++)scanf("%d",arr+i);
    printf("확인할 숫자를 입력하세요 : ");
    scanf("%d",&checkNum);
    insertionSort(arr,0,N-1);
    printf("정렬한 결과 : \n");
    for(int i=0;i<N;i++)printf("%d ",arr[i]);
    free(arr);
    return 0;
}
void insertionSort(int* arr, int left, int right){
    if(left>right)return;
    int copy=arr[left];
    if(copy==checkNum){
        printf("%d를 삽입정렬하기 직전의 정렬 상태 : \n",checkNum);
        for(int i=0;i<N;i++)printf("%d ",arr[i]);
    }
    int i;
    for(i=left-1;i>=0;i--){
        if(arr[i]>=copy)arr[i+1]=arr[i];
        else{
            arr[i+1]=copy;
            break;
        }
    }
    if(i==-1)arr[0]=copy;
    if(copy==checkNum)printf("\n%d의 삽입직후의 index : %d\n",checkNum,i+1);
    insertionSort(arr,left+1,right);
}