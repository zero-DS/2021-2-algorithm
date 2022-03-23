#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 500
#define SWAP(a,b,t) {t=a;a=b;b=t;}
int arr[ARR_SIZE]={0};
void IPSearch(int,int,int);
void bubbleSort();
int main(void){
    int key;
    srand(time(NULL));
    for(int i=0;i<ARR_SIZE;i++){
        arr[i]=rand()%ARR_SIZE;
    }
    bubbleSort();
    printf("찾고자하는 값을 입력하세요 : ");
    scanf("%d",&key);
    for(int i=0;i<ARR_SIZE;i++){
        printf("%d ",arr[i]);
    }
    IPSearch(0,ARR_SIZE-1,key);
    return 0;
}
void IPSearch(int left, int right, int key){
    if(left>=right){
        if(arr[left]==key){
            printf("\n%d번째에 %d존재\n",left,key);
            return;
        }
        printf("찾는 값이 존재하지 않습니다.\n");
        return;
    }
    int pos=left+(key-arr[left])*(right-left)/(arr[right]-arr[left]);
    if(arr[pos]==key){
        printf("\n%d번째에 %d존재\n",pos,key);
        return;
    }
    else if(arr[pos]<key){
        IPSearch(pos+1,right,key);
    }
    else if(arr[pos]>key){
        IPSearch(left,pos-1,key);
    }
}
void bubbleSort(){
    int temp;
    for(int i=0;i<ARR_SIZE-1;i++){
        for(int j=0;j<ARR_SIZE-1;j++){
            if(arr[j]>arr[j+1])SWAP(arr[j],arr[j+1],temp);
        }
    }
}