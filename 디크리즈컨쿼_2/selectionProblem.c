#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ARR_SIZE 500
#define SWAP(a,b,t) {t=a; a=b; b=t;}
int arr[ARR_SIZE]={0};
void select(int,int,int);
int main(void){
    srand(time(NULL));
    for(int i=0;i<ARR_SIZE;i++){
        arr[i]=rand()%ARR_SIZE;
    }
    int k;
    printf("몇 번째 원소를 찾고 싶은지 입력하세요 : ");
    scanf("%d",&k);
    for(int i=0;i<ARR_SIZE;i++){
        printf("%d ",arr[i]);
    }
    select(0,ARR_SIZE-1,k);

    return 0;
}
void select(int left, int right, int k){
    if(left>=right)return;
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
    if(low==k){
        printf("\n%d번째 원소는 %d\n",k,arr[k]);
    }
    else if(low<k){
        select(low+1,right,k);
    }
    else if(low>k){
        select(left,low-1,k);
    }
}