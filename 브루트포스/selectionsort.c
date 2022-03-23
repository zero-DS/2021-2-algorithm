#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DATA 500
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}
void selectionSort(int*);
void printArray(int*);
int main(void){
    int num;
    int arr[MAX_DATA]={0};
    srand(time(NULL));
    for(int i=0;i<MAX_DATA;i++){
        num=rand()%10000;
        arr[i]=num;
    }
    printArray(arr);
    clock_t start1 = clock();
    selectionSort(arr);
    clock_t end1 = clock();
    printArray(arr);
    printf("selection sort time : %lf\n",(double)(end1-start1)/CLOCKS_PER_SEC);
    return 0;
}
void printArray(int* arr){
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("...");
    for(int i=MAX_DATA-10;i<MAX_DATA;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void selectionSort(int* arr){
    int temp=0;
    int min;
    int minidx;
    for(int i=0;i<MAX_DATA;i++){
        min=arr[i];
        minidx=i;
        for(int j=i;j<MAX_DATA;j++){
            if(arr[j]<min){
                min=arr[j];
                minidx=j;
            }
        }
        SWAP(arr[i],arr[minidx],temp);
    }
}