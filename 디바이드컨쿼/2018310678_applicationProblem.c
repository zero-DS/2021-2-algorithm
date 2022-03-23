#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}
void pivotDivide(int*,int,int,int);
int selectPivot(int*,int,int);
void printTeam(int*,int);
int judge=-1;
char** name;
int main(void){
    int N;
    int* arr;
    printf("총 학생의 수를 입력하세요 : ");
    scanf("%d",&N);
    arr=(int*)malloc(sizeof(int)*N);             //키와 이름 저장할 배열 동적할당
    name=(char**)malloc(sizeof(char*)*(N+1));
    for(int i=0;i<N;i++){
        name[i]=(char*)malloc(sizeof(char)*15);
    }
    srand(time(NULL));
    for(int i=0;i<N;i++){//키 랜덤 배정
        arr[i]=rand()%50+140;
    }
    printf("각 학생의 키는 140~190으로 랜덤하게 부여됩니다. \n");
    printf("%d명의 학생의 이름을 차례대로 입력하세요 : \n",N);
    for(int i=0;i<N;i++){//이름은 입력받음
        printf("%d번째 학생 : ",i+1);
        scanf("%s",name[i]);
    }

    pivotDivide(arr,0,N-1,0);   //퀵정렬
    printTeam(arr,N);           //두개로 나눠진 팀 출력. N이 홀수면 judge가 존재

    free(arr);             //메모리 해제
    for(int i=0;i<N;i++){
        free(name[i]);
    }
    free(name);
    
    return 0;
}
void pivotDivide(int* arr, int left, int right, int step){
    if(left>=right)return;
    int temp;
    char* temp2;
    int pivotIdx=selectPivot(arr,left,right);//평균과 가장 가까운 학생을 피봇으로
    SWAP(arr[right],arr[pivotIdx],temp);//피봇을 맨 오른쪽과 swap
    temp2=name[right];
    name[right]=name[pivotIdx];
    name[pivotIdx]=temp2;
    int low=left,high=right-1;
    
    while(low<=high){
        while(low<right && arr[right]>=arr[low])low++;
        while(high>=left && arr[right]<=arr[high])high--;
        if(low<=high){
            SWAP(arr[low],arr[high],temp);
            temp2=name[low];
            name[low]=name[high];
            name[high]=temp2;
        }
        else{
            SWAP(arr[right],arr[low],temp);
            temp2=name[low];
            name[low]=name[right];
            name[right]=temp2;
        }
    }
    pivotDivide(arr,left,low-1,step+1); //피봇기준 왼쪽을 정렬
    pivotDivide(arr,low+1,right,step+1); //피봇기준 오른쪽을 정렬
    if(step==0){
        if((right-left+1)%2==1)judge=low; //총인원이 홀수인 경우 마지막 피봇이 심판이 됨
    }
}
int selectPivot(int* arr, int left, int right){
    int sum=0;
    double average=0;
    double gap=10000000;//맨처음에 비교하기 위해 매우 큰값으로 초기화
    int minGapIdx=-1;
    for(int i=left;i<right+1;i++)sum+=arr[i];
    average=(double)sum/(right-left+1);
    for(int i=left;i<right+1;i++){          //기존의 가장 평균에 가까웠던 사람보다 더 가까우면 갱신
        if(fabs(arr[i]-average)<=fabs(gap)){
            gap=arr[i]-average;
            minGapIdx=i;
        }
    }
    return minGapIdx;  //제일 평균에 가까운 사람의 index 리턴
}
void printTeam(int* arr, int teamNum){
    if(teamNum%2==0){                   //팀인원이 짝수일때
        printf("\nTeam A -> ");
        for(int i=0;i<teamNum/2;i+=2){
            printf("%s:%d ",name[i],arr[i]);
        }
        
        for(int i=teamNum/2;i<teamNum;i+=2){
            if(i+1<teamNum)printf("%s:%d ",name[i+1],arr[i+1]);
        }
        printf("\nTeam B -> ");
        for(int i=0;i<teamNum/2;i+=2){
            if(i+1<teamNum/2)printf("%s:%d ",name[i+1],arr[i+1]);
        }
        
        for(int i=teamNum/2;i<teamNum;i+=2){
            printf("%s:%d ",name[i],arr[i]);
        }
    }
    else{                                 //팀인원이 홀수일때
        printf("\nJudge -> %s:%d",name[judge],arr[judge]);
        for(int i=judge;i<teamNum-1;i++){//심판을 제외
            arr[i]=arr[i+1];
            strcpy(name[i],name[i+1]);
        }
        teamNum-=1;//제외시켰으니까 총 인원 수 1감소
        printf("\nTeam A -> ");
        for(int i=0;i<teamNum/2;i+=2){
            printf("%s:%d ",name[i],arr[i]);
        }
        
        for(int i=teamNum/2;i<teamNum;i+=2){
            if(i+1<teamNum)printf("%s:%d ",name[i+1],arr[i+1]);
        }
        
        printf("\nTeam B -> ");
       
        for(int i=0;i<teamNum/2;i+=2){
            if(i+1<teamNum/2)printf("%s:%d ",name[i+1],arr[i+1]);
        }
        ;
        for(int i=teamNum/2;i<teamNum;i+=2){
            printf("%s:%d ",name[i],arr[i]);
        }
        
    }
}