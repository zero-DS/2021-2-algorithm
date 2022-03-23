#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, left;
void jose(char**,int,int);
void modify(char**,int);
int main(void){
    char** people_weekday;//이름길이제한은 한글로 다섯글자까지
    char** people_weekend;
    char* temp=(char*)malloc(sizeof(char)*16);
    int CF_1,CF_2;
    printf("당직 근무의 총 대상 인원을 입력하세요 : ");
    scanf("%d",&N);
    
    people_weekday=(char**)malloc(sizeof(char*)*(N+1));
    people_weekend=(char**)malloc(sizeof(char*)*(N+1));
    for(int i=0;i<N;i++){
        people_weekday[i]=(char*)malloc(sizeof(char)*16);
        people_weekend[i]=(char*)malloc(sizeof(char)*16);
    }
    
    printf("당직 근무 대상의 이름을 입력해주세요 : ");
    for(int i=0;i<N;i++){
        scanf("%s",temp);
        strcpy(people_weekday[i],temp);
        strcpy(people_weekend[i],temp);
    }
    printf("평일 당직표 지정을 위한 난수값을 입력해주세요. (1 ~ %d) : ",N);
    scanf("%d",&CF_1);
    printf("주말 당직표 지정을 위한 난수값을 입력해주세요. (1 ~ %d) : ",N);
    scanf("%d",&CF_2);
    left=N;
    printf("\n평일 당직 순서 : ");
    jose(people_weekday,CF_1-1,CF_1);
    left=N;
    printf("\n주말 당직 순서 : ");
    jose(people_weekend,CF_2-1,CF_2);
    
    free(people_weekday);
    free(people_weekend);
    free(temp);
    return 0;
}
void jose(char** people, int target, int CF){
    if(left==0)return;
    int next=target+CF-1;
    printf("%s ",people[target]);
    modify(people,target);
    if(left==0)return;
    while(next>=left){
        next-=left;
    }
    jose(people,next,CF);
}
void modify(char** people, int target){
    for(int i=target;i<left-1;i++){
        people[i]=people[i+1];
    }
    left--;
}