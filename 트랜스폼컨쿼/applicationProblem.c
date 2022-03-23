#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODE 100
#define SWAP(a,b,t) {t=a;a=b;b=t;}
typedef struct node{
    int data;
}Node;
typedef struct heap{
    char name[31];
    int size;
    Node heap[MAX_NODE];
}Heap;
typedef struct heapSET{
    Heap* heaplist[MAX_NODE];
    int size;
}HeapSET;
Heap* initheap(char*);
void swap(Heap*,int,int);
void input(Heap*,int);
int delete(Heap*);
void bubbleSort(char**,int*);
int N;
int main(void){
    char* temp=(char*)malloc(sizeof(char)*31);
    char cmd;
    HeapSET* hset=(HeapSET*)malloc(sizeof(HeapSET));
    hset->size=0;
    for(int i=0;i<MAX_NODE;i++){
        hset->heaplist[i]=NULL;
    }
    scanf("%d",&N);
    char** names=(char**)malloc(sizeof(char*)*(N+1));
    int* expDate=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        names[i]=(char*)malloc(sizeof(char)*31);//물품이름은 10글자까지
    }
    for(int i=0;i<N;i++){
        scanf("%s %d",names[i],&expDate[i]);
    }
    bubbleSort(names,expDate);

    hset->heaplist[hset->size]=initheap(names[0]);
    input(hset->heaplist[hset->size],expDate[0]);
    hset->size++;
    for(int i=1;i<N;i++){
        if(strcmp(names[i],names[i-1])){
            hset->heaplist[hset->size]=initheap(names[i]);
            input(hset->heaplist[hset->size],expDate[i]);
            hset->size++;
        }
        else{
            input(hset->heaplist[hset->size-1],expDate[i]);
        }
    }
    printf("찾으시려는 품목은 \"G 품목명\"으로 입력, 프로그램을 종료하려면 \"Q\"입력\n");
    while(1){
        int foundName=0;
        scanf("%c",&cmd);
        if(cmd=='G'){
            scanf("%s",temp);
            for(int i=0;i<hset->size;i++){
                if(!strcmp(hset->heaplist[i]->name,temp)){
                    int deleted=delete(hset->heaplist[i]);
                    if(deleted==0)printf("-> 없어요!\n");
                    else{
                        printf("-> %s %d\n",hset->heaplist[i]->name,deleted);
                    }
                    foundName=1;
                    break;
                }
            }
            if(foundName==0)printf("-> 없어요!\n");
        }
        else if (cmd=='Q')break;
    }
    for(int i=0;i<N;i++){
        free(names[i]);
    }
    free(temp);
    free(names);
    free(expDate);
    return 0;
}
Heap* initheap(char* input){
    Heap* new=(Heap*)malloc(sizeof(Heap));
    new->size=0;
    strcpy(new->name,input);
    return new;
}
void swap(Heap* h, int a, int b){
    int temp;
    temp=h->heap[a].data;
    h->heap[a].data=h->heap[b].data;
    h->heap[b].data=temp;
}
void input(Heap* h, int num){
    h->size++;
    int i=h->size;
    h->heap[h->size].data=num;

    while(i>1){
        if(h->heap[i/2].data > h->heap[i].data){
            swap(h,i,i/2);
            i/=2;
        }
        else break;
    }
}
int delete(Heap* h){
    int value=h->heap[1].data;
    if(h->size==0){
        return 0;
    }
    h->heap[1].data=h->heap[h->size].data;
    if(h->size!=0)h->size--;
    int i=1,j;

    while(i<=h->size){
        j=i*2;
        if(j>h->size)break;
        if(h->heap[i].data < h->heap[j].data && h->heap[i].data < h->heap[j+1].data)break;
        if(h->heap[j].data > h->heap[j+1].data)j+=1;
        swap(h,i,j);
        i=j;
    }
    return value;
}
void bubbleSort(char** arr, int* arr2){
    char* temp;
    int tempNum;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1-i;j++){
            if(strcmp(arr[j],arr[j+1])>0){
                SWAP(arr[j],arr[j+1],temp);
                SWAP(arr2[j],arr2[j+1],tempNum);
            }
        }
    }
}