#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
int compare(char*,char*);
int main(void){
    char word[MAX_LEN]={0};
    char word1[MAX_LEN]={0};
    char word2[MAX_LEN]={0};
    printf("LCS를 구할 단어를 입력하세요 : ");
    scanf("%s",word);
    printf("%s와 비교할 두 단어를 차례대로 입력하세요 : ",word);
    scanf("%s %s",word1,word2);
    int LCS_Result1=compare(word,word1);
    int LCS_Result2=compare(word,word2);
    if(LCS_Result1<LCS_Result2){
        printf("%s는 %s와 더 유사합니다.\n",word,word2);
    }
    else if(LCS_Result1>LCS_Result2){
        printf("%s는 %s와 더 유사합니다.\n",word,word1);
    }
    else{
        printf("%s는 %s, %s와 각각 동등하게 유사합니다.\n",word,word1,word2);
    }

    return 0;
}
int compare(char* word_a, char* word_b){
    int m=strlen(word_a);
    int n=strlen(word_b);
    int** arr=(int**)malloc(sizeof(int*)*(m+1));
    for(int i=0;i<n+1;i++){
        arr[i]=(int*)malloc(sizeof(int)*(n+1));
    }

    for(int i=0;i<m+1;i++){
        arr[i][0]=0;
    }
    for(int j=0;j<n+1;j++){
        arr[0][j]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(word_a[i-1]==word_b[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                if(arr[i-1][j]<arr[i][j-1]){
                    arr[i][j]=arr[i][j-1];
                }
                else{
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
    }
    printf("%s 와 %s의 비교과정 -> \n",word_a,word_b);
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return arr[m][n];
}