#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DATA 1000
int sorted[MAX_DATA]={0};//여기부터
int flag=0;
void divide(int*,int,int);
void mergeNsort(int*,int,int,int);//여기까지 mergesort
void binarySearch(int*,int,int,int);
void linearSearch(int*,int);
int main (void){
    int num,key;
    int sortedArray[MAX_DATA]={0};
    int unsortedArray1[MAX_DATA]={0};
    int unsortedArray2[MAX_DATA]={0};
    srand((unsigned int)time(NULL));
    for(int i=0;i<MAX_DATA;i++){
        num=rand();
        num=(int)num % MAX_DATA;
        sortedArray[i]=i;
        unsortedArray1[i]=num;
        unsortedArray2[i]=num;
    }

    key=rand();
    key=(int)key % MAX_DATA;
    printf("찾고자 하는 수 : %d\n",key);
    
    clock_t start1 = clock();
    linearSearch(sortedArray,key);
    clock_t end1 = clock();
    printf("sorted array linear search time : %lf\n",(double)(end1-start1)/CLOCKS_PER_SEC);
    clock_t start2 = clock();
    binarySearch(sortedArray,0,MAX_DATA-1,key);
    clock_t end2 = clock();
    printf("sorted array binary search time : %lf\n",(double)(end2-start2)/CLOCKS_PER_SEC);
    clock_t start3 = clock();
    linearSearch(unsortedArray1,key);
    clock_t end3 = clock();
    printf("unsorted array linear search time : %lf\n",(double)(end3-start3)/CLOCKS_PER_SEC);
    clock_t start4 = clock();
    flag=0;
    divide(unsortedArray2,0,MAX_DATA-1);
    binarySearch(unsortedArray2,0,MAX_DATA-1,key);
    clock_t end4 = clock();
    printf("unsorted array binary search time : %lf\n",(double)(end4-start4)/CLOCKS_PER_SEC);

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
void binarySearch(int* arr, int left, int right, int key){
    if(left<right && flag==0){
        int mid=(left+right)/2;
        if(arr[mid]<key)binarySearch(arr,mid+1,right,key);
        else if(arr[mid]>key)binarySearch(arr,left,mid-1,key);
        else {
            printf("%d 번째에 존재 -> ",mid);
            flag=1;
        }
    }
}
void linearSearch(int* arr, int key){
    for(int i=0;i<MAX_DATA;i++){
        if(arr[i]==key){
            printf("%d 번째에 존재 -> ",i);
            break;
        }
    }
}