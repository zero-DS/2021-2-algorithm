#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODE 100
typedef struct node{
    int data;
}Node;
typedef struct heap{
    int size;
    Node heap[MAX_NODE];
}Heap;
void MINswap(Heap*,int,int);
void MINinput(Heap*,int);
int MINdelete(Heap*);
void MAXinput(Heap*,int);
int MAXdelete(Heap*);
int N;
int main(void){
    Heap* heap=(Heap*)malloc(sizeof(Heap));
    heap->size=0;
    printf("최소 힙을 만들고 싶으면 \"min\", 최대 힙을 만들고 싶으면 \"max\"를 입력하세요 : ");
    char command[10]={0};
    scanf("%s",command);
    printf("입력할 자료의 개수를 입력하세요 : ");
    int cmd;
    scanf("%d",&N);
    printf("%d개의 자료를 입력하세요 : ",N);
    if(!strcmp(command,"min")){
        for(int i=0;i<N;i++){
            scanf("%d",&cmd);
            MINinput(heap,cmd);
        }
        printf("최소 힙을 이용한 오름차순 정렬 -> ");
        int deleted=MINdelete(heap);
        while(deleted!=0){
            printf("%d ",deleted);
            deleted=MINdelete(heap);
        }
    }
    else if(!strcmp(command,"max")){
        for(int i=0;i<N;i++){
            scanf("%d",&cmd);
            MAXinput(heap,cmd);
        }
        printf("최대 힙을 이용한 내림차순 정렬 -> ");
        int deleted=MAXdelete(heap);
        while(deleted!=0){
            printf("%d ",deleted);
            deleted=MAXdelete(heap);
        }
    }
    else{
        printf("잘못된 입력입니다.");
    }


    return 0;
}
void MINswap(Heap* h, int a, int b){
    int temp;
    temp=h->heap[a].data;
    h->heap[a].data=h->heap[b].data;
    h->heap[b].data=temp;
}
void MINinput(Heap* h, int num){
    h->size++;
    int i=h->size;
    h->heap[h->size].data=num;

    while(i>1){
        if(h->heap[i/2].data > h->heap[i].data){
            MINswap(h,i,i/2);
            i/=2;
        }
        else break;
    }
}
int MINdelete(Heap* h){
    int value=h->heap[1].data;
    if(h->size==0)return 0;
    h->heap[1].data=h->heap[h->size].data;
    if(h->size!=0)h->size--;
    int i=1,j;

    while(i<=h->size){
        j=i*2;
        if(j>h->size)break;
        if(h->heap[i].data < h->heap[j].data && h->heap[i].data < h->heap[j+1].data)break;
        if(h->heap[j].data > h->heap[j+1].data)j+=1;
        MINswap(h,i,j);
        i=j;
    }
    return value;
}
void MAXinput(Heap* h, int num){
    h->size++;
    int i=h->size;
    h->heap[i].data=num;
    int temp;
    while(i>1){
        if(h->heap[i/2].data < h->heap[i].data){
            temp=h->heap[i].data;
            h->heap[i].data=h->heap[i/2].data;
            h->heap[i/2].data=temp;
            i/=2;
        }
        else break;
    }
}
int MAXdelete(Heap* h){
    int i=1;
    int value=h->heap[i].data;
    if(h->size==1)h->heap[1].data=0;
    h->heap[i].data=h->heap[h->size].data;
    if(h->size!=0)h->size--;

    int j=0;
    int temp;
    while(i <= h->size){
        j=i*2;
        if(j>h->size)break;
        if(h->heap[i].data > h->heap[j].data && h->heap[i].data > h->heap[j+1].data)break;
        if(h->heap[j].data < h->heap[j+1].data)j+=1;
        temp=h->heap[j].data;
        h->heap[j].data=h->heap[i].data;
        h->heap[i].data=temp;
        i=j;
    }
    return value;
}