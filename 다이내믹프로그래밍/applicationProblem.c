#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHORD 100
void checkSimilarity(char*,char*,double);
int main(void){//코드진행은 단순한 코드로만 작성합니다
    int N,similarityPercentage;
    double similarityNorm;
    char** scoreList;
    char scoreNorm[MAX_CHORD]={0};
    
    printf("기준 악보 : ");
    scanf("%s",scoreNorm);
    printf("기준 유사도(%%) : ");
    scanf("%d",&similarityPercentage);
    printf("입력할 악보 개수 : ");
    scanf("%d",&N);
    similarityNorm=(double)strlen(scoreNorm)*(double)similarityPercentage/100;
    scoreList=(char**)malloc(sizeof(char*)*(N+1));
    for(int i=0;i<N;i++){
        scoreList[i]=(char*)malloc(sizeof(char)*(MAX_CHORD+1));
    }
    for(int i=0;i<N;i++){
        printf("%d번째 악보 입력 : ",i+1);
        scanf("%s",scoreList[i]);
    }
    printf("=================akbo list=================\n");
    for(int i=0;i<N;i++){
        checkSimilarity(scoreNorm,scoreList[i],similarityNorm);
    }
    printf("===========================================\n");
    for(int i=0;i<N;i++){
        free(scoreList[i]);
    }
    free(scoreList);
    return 0;
}
void checkSimilarity(char* norm, char* score, double simNorm){
    int m=strlen(norm);
    int n=strlen(score);
    int** arr=(int**)malloc(sizeof(int*)*(m+1));
    for(int i=0;i<m+1;i++){
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
            if(norm[i-1]==score[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                if(arr[i-1][j]<arr[i][j-1])arr[i][j]=arr[i][j-1];
                else arr[i][j]=arr[i-1][j];
            }
        }
    }
    if((double)arr[m][n]>=simNorm){
        printf("%s (similar:%d/%d)\n",score,arr[m][n],m);
    }
    for(int i=0;i<m+1;i++){
        free(arr[i]);
    }
    free(arr);
}