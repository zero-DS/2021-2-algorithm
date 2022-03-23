#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_NUM 100
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}

void pivotDivide(int*,int,int);
int cnt=0;
int main (void){
    int arr[ARR_NUM]={0};
    srand(time(NULL));
    for(int i=0;i<ARR_NUM;i++){
        arr[i]=rand()%1000;
    }
    clock_t start = clock();
    pivotDivide(arr,0,ARR_NUM-1);
    clock_t end = clock();
    printf("\nsorted result -> ");
    for(int i=0;i<ARR_NUM;i++){
        printf("%d ",arr[i]);
    }
    printf("\nquick sort time : %lf",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}

void pivotDivide(int* arr, int left, int right){
    if(left>=right)return;
    printf("%d번째 과정 -> ",++cnt);
    for(int i=0;i<ARR_NUM;i++){
        if(i==left)printf("[");
        if(i==right)printf("p");
        if(i>=left && i<=right)printf("%d ",arr[i]);
        if(i==right)printf("]");
    }
    printf("\n");
    int pivot=arr[right];//맨 뒤의원소를 피벗으로 지정
    int low=left,high=right-1;
    int temp;
    while(low<=high){
        while(low<right && pivot>=arr[low])low++;
        while(high>=left && pivot<=arr[high])high--;
        if(low<=high){
            SWAP(arr[low],arr[high],temp);
        }
        else{
            SWAP(arr[right],arr[low],temp);
        }
    }
    
    pivotDivide(arr,left,low-1);
    pivotDivide(arr,low+1,right);
}