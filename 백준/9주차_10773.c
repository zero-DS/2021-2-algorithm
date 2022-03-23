#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,size,input;
    scanf("%d",&n);
    size=0;
    int* stack=calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&input);
        if(input==0){
            if(size!=0){
                size--;
                stack[size]=0;
            }
        }
        else{
            stack[size++]=input;
        }
    }
    int i=0,sum=0;
    while(stack[i]){
        sum+=stack[i++];
    }
    printf("%d",sum);
    free(stack);
    return 0;
}