#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(a,b,t) {t=a;a=b;b=t;}
char fastest[52]={0};
void reverse(char*,int,int);
void three(char*,int,int);
int main(void){
    char arr[51]={0};
    scanf("%s",arr);
    memset(fastest,'z',strlen(arr));
    
    three(arr,0,strlen(arr)-1);
    printf("%s",fastest);


    return 0;
}
void reverse(char* arr, int left, int right){
    int halflen=(right-left+1)/2;
    char temp;
    for(int i=0;i<halflen;i++){
        SWAP(arr[left+i],arr[right-i],temp);
    }
}
void three(char* arr, int left, int right){
    int one,twoStart,twoEnd,three;
    for(int i=0;i<right-1;i++){
        for(int j=right;j>1;j--){
            if(j-i<=1)break;
            one=i;
            three=j;
            twoStart=i+1;
            twoEnd=j-1;
            reverse(arr,left,one);
            reverse(arr,twoStart,twoEnd);
            reverse(arr,three,right);
            if(strcmp(fastest,arr)>0){
                for(int i=0;i<strlen(arr);i++)fastest[i]=arr[i];
            }
            reverse(arr,left,one);
            reverse(arr,twoStart,twoEnd);
            reverse(arr,three,right);
        }
    }
}