#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define NUM 500
void divide(int*,int,int);
void mergeNsort(int*,int,int,int);
void binarySearch(int*,int,int,int);
int sorted[NUM]={0};
int flag=0;
int main(void){
    int arr[NUM]={0};
    srand(time(NULL));
    for(int i=0;i<NUM;i++){
        arr[i]=rand()%1000;
    }
    divide(arr,0,NUM-1);
    for(int i=0;i<NUM;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    while(1){
        char cmd[1000]={0};
        printf("index를 알고자 하는 숫자를 입력하세요. 종료하고 싶으면 Q를 입력하세요 : ");
        scanf("%s",cmd);
        if(cmd[0]=='Q'){
            printf("이진 탐색 종료\n");
            break;
        }
        int num=0,len=strlen(cmd);
        for(int i=len-1;i>=0;i--){
            num+=((int)cmd[i]-48)*(int)pow(10,len-i-1);
        }
        flag=0;
        binarySearch(arr,0,NUM-1,num);
        if(flag==0)printf("%d는 존재하지 않습니다.\n",num);
    }


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
void binarySearch(int* arr, int left, int right, int key){
    if(left<right && flag==0){
        int mid=(left+right)/2;
        if(arr[mid]<key)binarySearch(arr,mid+1,right,key);
        else if(arr[mid]>key)binarySearch(arr,left,mid-1,key);
        else {
            printf("%d 번째에 존재 \n",mid);
            flag=1;
        }
    }
}