#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void stringMatching(char*,char*);
void censoring(char**,char**,int,int);
int matchCount=0; //한 댓글에서 키워드와 일치한 횟수를 카운트하는 변수
int main(void){
    int len1,num1,len2,num2;
    int tempLen;
    char** censorTargets;//걸러낼 키워드 저장 배열
    char** comments;//사용자 댓글 저장 배열
    int commentNum;
    
    printf("~~유해 댓글 필터링 프로그램~~\n");
    printf("걸러낼 단어 키워드의 개수를 입력하시오 : ");
    scanf("%d",&num1);
    censorTargets=(char**)malloc(sizeof(char*)*(num1+1));
    printf("\n걸러낼 단어 키워드의 최대 길이를 입력하시오 : ");
    scanf("%d",&len1);
    for(int i=0;i<num1;i++){
        censorTargets[i]=(char*)malloc(sizeof(char)*(len1*3+1));//한글은 바이트를 많이 차지함
    }
    printf("\n걸러낼 단어 키워드의 입력을 시작합니다. '엔터키'를 누를 때마다 키워드의 입력이 구분됩니다.\n");
    getchar();
    for(int i=0;i<num1;i++){
        printf("입력 : ");
        fgets(censorTargets[i],sizeof(char)*(len1*3+2),stdin);
        tempLen=strlen(censorTargets[i]);
        censorTargets[i][tempLen-1]='\0';//fgets는 개행문자까지 입력받기 때문에 그 자리를 널값으로 바꿔줌
    }

    printf("\n사용자 댓글의 개수를 입력하시오 : ");
    scanf("%d",&num2);
    comments=(char**)malloc(sizeof(char*)*(num2+1));
    printf("\n사용자 댓글의 최대 길이를 입력하시오 : ");
    scanf("%d",&len2);
    for(int i=0;i<num2;i++){
        comments[i]=(char*)malloc(sizeof(char)*(len2*3+1));
    }
    printf("\n사용자 댓글의 입력을 시작합니다. '엔터키'를 누를 때마다 댓글의 입력이 구분됩니다.\n");
    getchar();
    for(int i=0;i<num2;i++){
        printf("입력 : ");
        fgets(comments[i],sizeof(char)*(len2*3+2),stdin);
        tempLen=strlen(comments[i]);
        comments[i][tempLen-1]='\0';
    }

    censoring(comments,censorTargets,num2,num1);//걸러내기

    for(int i=0;i<num1;i++){//이 아래로는 메모리 해제
        free(censorTargets[i]);
    }
    free(censorTargets);
    for(int i=0;i<num2;i++){
        free(comments[i]);
    }
    free(comments);
    return 0;
}
void stringMatching(char* comment, char* target){//string matching하는 함수, 키워드와 일치하는 부분이 있으면 그 부분을 '-'로 대체함
    int commentLen=strlen(comment);              
    int targetLen=strlen(target);
    for(int i=0;i<commentLen;i++){
        for(int j=0;j<targetLen;j++){
            if(i+j==commentLen || comment[i+j]!=target[j]) break; //한 글자라도 다르면 반복문 탈출, 댓글의 다음 글자로
            if(j==targetLen-1){
                matchCount++;
                memset(&(comment[i]),'-',targetLen);
            }
        }
    }
}
void censoring(char** comments, char** censorTargets, int commentsNum, int targetsNum){//모든 댓글과 모든 걸러낼 키워드를 조합해가며 string matching을 시도하는 함수
    for(int i=0;i<commentsNum;i++){
        matchCount=0;
        for(int j=0;j<targetsNum;j++){
            stringMatching(comments[i],censorTargets[j]);
        }
        if(matchCount>1)memset(comments[i],'-',strlen(comments[i]));//한 댓글에서 키워드를 두 번 이상 걸러냈다면 댓글 전체를 가림
    }
    printf("\n걸러낸 결과 : ");
    for(int i=0;i<commentsNum;i++){
        printf("\n%s",comments[i]);
    }
}