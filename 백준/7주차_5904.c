#include <stdio.h>
#include <stdlib.h>
int N, idx;
void moo(int);
int main(void){
    scanf("%d",&N);
    idx=0;
    moo(29);
    return 0;
}
void moo(int n){
    if(n==0){
        if(idx+1==N){
            printf("m");
            exit(0);
        }
        if(idx+2==N || idx+3==N){
            printf("o");
            exit(0);
        }
        idx+=3;
        return;
    }
    moo(n-1);
    if(idx+1==N){
        printf("m");
        exit(0);
    }
    idx++;
    for(int i=0;i<n+2;i++){
        if(idx+1==N){
            printf("o");
            exit(0);
        }
        idx++;
    }
    moo(n-1);
}