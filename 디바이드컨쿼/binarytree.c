#include <stdio.h>
#define MAX_NODE 32
int tree[MAX_NODE]={-1,60,41,74,16,53,65,-1,-1,25,46,55,63,70,-1,-1,-1,-1,-1,-1,42,-1,-1,-1,62,64,-1,-1,-1,-1,-1,-1};
void traversal(int,int);
void printTree(int);
int main(void){
    printTree(1);
    printf("\n전위순회 : ");
    traversal(1,0);
    printf("\n중위순회 : ");
    traversal(1,1);
    printf("\n후위순회 : ");
    traversal(1,2);
    return 0;
}
void traversal(int start,int type){
    if(tree[start]==-1)return;
    if(type==0)printf("%d ",tree[start]);
    if(start*2<MAX_NODE) traversal(start*2,type);
    if(type==1)printf("%d ",tree[start]);
    if(start*2+1<MAX_NODE) traversal((start*2)+1,type);
    if(type==2)printf("%d ",tree[start]);
}
void printTree(int start){
    if(tree[start]==-1){
        printf("N");
        return;
    }
    printf("%d",tree[start]);
    if(start*2<MAX_NODE){
        printf("(");
        printTree(start*2);
        printf(",");
        
    }
    if(start*2+1<MAX_NODE){
        printTree((start*2)+1);
        printf(")");
    }
}