#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DATA 10000
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}
int sorted[MAX_DATA]={0};//여기부터
void divide(int*,int,int);
void mergeNsort(int*,int,int,int);//여기까지 mergesort
void sort(int*,int,int);//여기부터
int pivotDivide(int*,int,int);//여기까지 quicksort
void bubblesort(int*,int);
int main(void){
    int num;
    int array1[MAX_DATA]={0};
    int array2[MAX_DATA]={0};
    int array3[MAX_DATA]={0};
    for(int i=0;i<MAX_DATA;i++){
        num=rand();
        array1[i]=num;
        array2[i]=num;
        array3[i]=num;
    }
    clock_t start1 = clock();
    divide(array1,0,MAX_DATA-1);
    clock_t end1 = clock();
    clock_t start2 = clock();
    sort(array2,0,MAX_DATA-1);
    clock_t end2 = clock();
    clock_t start3 = clock();
    bubblesort(array3,MAX_DATA);
    clock_t end3 = clock();

    printf("merge sort time : %lf\n",(double)(end1-start1)/CLOCKS_PER_SEC);
    printf("quick sort time : %lf\n",(double)(end2-start2)/CLOCKS_PER_SEC);
    printf("bubble sort time : %lf\n",(double)(end3-start3)/CLOCKS_PER_SEC);
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
    int s=left,k;
    while(1){
        if(arr[i]<arr[j]){
            sorted[s++]=arr[i++];
        }
        else{
            sorted[s++]=arr[j++];
        }
        if(i>mid || j>right)break;
    }
    if(i>mid){
        for(k=j;k<right+1;k++){
            sorted[s++]=arr[k];
        }
    }
    else if(j>right){
        for(k=i;k<mid+1;k++){
            sorted[s++]=arr[k];
        }
    }
    for(k=left;k<right+1;k++){
        arr[k]=sorted[k];
    }
}
void sort(int* arr, int left, int right){
    if(left<right){
        int pivot=pivotDivide(arr,left,right);
        sort(arr,left,pivot-1);
        sort(arr,pivot+1,right);
    }
}
int pivotDivide(int* arr, int left, int right){
    int pivot=arr[left];//맨 앞의원소를 피벗으로 지정
    int low=left+1,high=right;
    int temp;
    while(low<high){
        while(low<right && pivot>=arr[low])low++;
        while(high>left && pivot<=arr[high])high--;
        if(low<high){
            SWAP(arr[low],arr[high],temp);
        }
    }
    SWAP(arr[left],arr[high],temp);
    return high;
}
void bubblesort(int* arr, int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1])SWAP(arr[j],arr[j+1],temp);
        }
    }
}