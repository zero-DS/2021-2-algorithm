#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 10000
#define NUM_LIMIT 1000
int arr[ARR_SIZE]={0};
int check[NUM_LIMIT]={0};
int sorted[ARR_SIZE]={0};
void bruteForce();
void preSorting();
void divide(int,int);
void mergeNsort(int,int,int);
int main(void){
    srand(time(NULL));
    for(int i=0;i<ARR_SIZE;i++){
        arr[i]=rand()%NUM_LIMIT;
    }
    clock_t start1=clock();
    bruteForce();
    for(int i=0;i<NUM_LIMIT;i++){
        if(check[i]!=0){
            printf("(%d,%d)",i,check[i]);
        }
    }
    clock_t end1=clock();
    printf("\n\n");
    clock_t start2=clock();
    preSorting();
    clock_t end2=clock();

    printf("\nbrute force time : %lf, presorting time : %lf\n",(double)(end1-start1)/CLOCKS_PER_SEC,(double)(end2-start2)/CLOCKS_PER_SEC);
    return 0;
}
void bruteForce(){
    for(int i=0;i<ARR_SIZE;i++){
        if(check[arr[i]]!=0)continue;
        if(i==ARR_SIZE-1){
            check[arr[i]]++;
            break;
        }
        check[arr[i]]++;
        for(int j=i+1;j<ARR_SIZE;j++){
            if(arr[i]==arr[j]){
                check[arr[i]]++;
            }
        }
    }
}
void preSorting(){
    divide(0,ARR_SIZE-1);
    int cnt=0;
    for(int i=0;i<ARR_SIZE-1;i++){
        if(arr[i]==arr[i+1])cnt++;
        else{
            printf("(%d,%d)",arr[i],cnt+1);
            cnt=0;
        }
    }
    if(arr[ARR_SIZE-1]==arr[ARR_SIZE-2]){
        printf("(%d,%d)",arr[ARR_SIZE-1],cnt+1);
    }
    else{
        printf("(%d,%d)",arr[ARR_SIZE-1],1);
    }
}
void divide(int left, int right){
    int mid=(left+right)/2;
    if(left<right){
        divide(left,mid);
        divide(mid+1,right);
        mergeNsort(left,mid,right);
    }
}
void mergeNsort(int left, int mid, int right){
    int i=left,j=mid+1;
    int s=left;
    while(1){
        if(i>mid || j>right)break;
        if(arr[i]<arr[j]){
            sorted[s++]=arr[i++];
        }
        else{
            sorted[s++]=arr[j++];
        }
    }
    if(i>mid){
        for(int k=j;k<right+1;k++){
            sorted[s++]=arr[k];
        }
    }
    else if(j>right){
        for(int k=i;k<mid+1;k++){
            sorted[s++]=arr[k];
        }
    }
    for(int k=left;k<right+1;k++){
        arr[k]=sorted[k];
    }
}