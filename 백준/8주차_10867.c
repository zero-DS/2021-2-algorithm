#include <stdio.h>
#include <stdlib.h>
void divide(int*,int,int);
void mergeNsort(int*,int,int,int);
void printArr(int*,int);
int* sorted;
int main(void){
    int N;
    int* arr;
    scanf("%d",&N);
    arr=(int*)malloc(sizeof(int)*N);
    sorted=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d",arr+i);
    }
    divide(arr,0,N-1);
    printArr(arr,N);
    free(arr);
    free(sorted);
    return 0;
}
void divide(int* arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,left,mid);
        divide(arr,mid+1,right);
        mergeNsort(arr,left,mid,right);
    }
}
void mergeNsort(int* arr, int left, int mid, int right){
    int i=left, j=mid+1;
    int s=left;
    while(1){
        if(i>mid || j>right)break;
        if(arr[i]>arr[j])sorted[s++]=arr[j++];
        else sorted[s++]=arr[i++];
    }
    if(i>mid){
        for(int k=j;k<right+1;k++)sorted[s++]=arr[k];
    }
    else if(j>right){
        for(int k=i;k<mid+1;k++)sorted[s++]=arr[k];
    }
    for(int k=left;k<right+1;k++)arr[k]=sorted[k];
}
void printArr(int* arr, int N){
    for(int i=0;i<N;i++){
        if(!(i>0 && arr[i]==arr[i-1]))printf("%d ",arr[i]);
    }
}