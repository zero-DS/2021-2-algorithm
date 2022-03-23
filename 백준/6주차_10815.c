#include <stdio.h>
#include <stdlib.h>
int* sorted;
void divide(int*,int,int);
void mergeNsort(int*,int,int,int);
void binarySearch(int*,int,int,int);
int existFlag=0;
int main(void){
    int N,M;
    int* sangguen;
    int* sootja;
    scanf("%d",&N);
    sangguen=(int*)malloc(sizeof(int)*N);
    sorted=(int*)malloc(sizeof(int)*N);
    for (int i=0;i<N;i++){
        scanf("%d",sangguen+i);
    }
    scanf("%d",&M);
    sootja=(int*)malloc(sizeof(int)*M);
    for (int i=0;i<M;i++){
        scanf("%d",sootja+i);
    }
    divide(sangguen,0,N-1);
    for(int i=0;i<M;i++){
        existFlag=0;
        binarySearch(sangguen,0,N-1,sootja[i]);
        printf("%d ",existFlag);
    }
    free(sangguen);
    free(sorted);
    free(sootja);
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
    int i=left,j=mid+1;
    int s=left;
    while(1){
        if(arr[i]<arr[j])sorted[s++]=arr[i++];
        else sorted[s++]=arr[j++];
        if(i>mid || j>right)break;
    }
    if(i>mid){
        for(int k=j;k<right+1;k++)sorted[s++]=arr[k];
    }
    else if(j>right){
        for(int k=i;k<mid+1;k++)sorted[s++]=arr[k];
    }
    for(int k=left;k<right+1;k++)arr[k]=sorted[k];
}
void binarySearch(int* arr, int left, int right, int target){
    int mid=(left+right)/2;
    if(arr[mid]==target){
        existFlag=1;
        return;
    }
    if(left>right)return;
    if(arr[mid]>target){
        binarySearch(arr,left,mid-1,target);
    }
    else if(arr[mid]<target){
        binarySearch(arr,mid+1,right,target);
    }
}