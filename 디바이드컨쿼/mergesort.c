#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_NUM 50
void divide(int*,int,int);
void mergeNsort(int*,int,int,int);
int sorted[ARR_NUM]={0};
int mergeCnt=0;
int main(void){
    int arr[ARR_NUM]={0};
    srand(time(NULL));
    for (int i=0;i<ARR_NUM;i++){
        arr[i]=rand()%100;
    }
    clock_t start = clock();
    divide(arr,0,ARR_NUM-1);
    clock_t end = clock();
    printf("\nsorted result -> ");
    for(int i=0;i<ARR_NUM;i++){
        printf("%d ",arr[i]);
    }
    printf("\nmerge sort time : %lf\n",(double)(end-start)/CLOCKS_PER_SEC);

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
    printf("%d 번째 merge -> ",++mergeCnt);
    for(int i=0;i<ARR_NUM;i++){
        if(i==left)printf("[");
        printf("%d",arr[i]);
        if(i==right){
            printf("]");
        }
        else printf(" ");
    }
    printf("\n");
}