#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DATA 500
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}
void bubbleSort(int*);
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
    bubbleSort(arr);
    clock_t end1 = clock();
    printArray(arr);
    printf("bubble sort time : %lf\n",(double)(end1-start1)/CLOCKS_PER_SEC);
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
void bubbleSort(int* arr){
    int temp;
    for(int i=0;i<MAX_DATA-1;i++){
        for(int j=0;j<MAX_DATA-1;j++){
            if(arr[j]>arr[j+1])SWAP(arr[j],arr[j+1],temp);
        }
    }
}