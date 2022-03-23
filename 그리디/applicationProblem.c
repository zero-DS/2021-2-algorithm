#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(a,b,t) {t=a;a=b;b=t;}
#define MAX_EXAM 100
typedef struct exam{
    char examName[31];
    int startTime;
    int endTime;
    int peopleNum;
}Exam;
typedef struct classRoom{
    Exam exams[MAX_EXAM];
    int examsInClassRoom;
    int classRoomNum;
    int vacancy;
}ClassRoom;
void bubbleSort(Exam*,int);
void renewClassRoom(ClassRoom*,int,int,int);
void determineClassRoom(Exam,ClassRoom*);
int main(void){
    char tempExamName[31]={0};//강의명은 10글자까지
    int tempStartTime,tempEndTime,tempPeopleNum;
    int examNum,ventTime;
    int minimumClassRoom=0;
    printf("총 시험의 수를 입력하세요 : ");
    scanf("%d",&examNum);
    Exam* examArr=(Exam*)malloc(sizeof(Exam)*examNum);
    ClassRoom* classRoomArr=(ClassRoom*)malloc(sizeof(ClassRoom)*31);//31번째 강의실은 온라인
    for(int i=0;i<31;i++){
        classRoomArr[i].classRoomNum=i+1;
        classRoomArr[i].vacancy=1;
        classRoomArr[i].examsInClassRoom=0;
    }
    printf("강의실을 환기할 시간을 정해주세요 : ");
    scanf("%d",&ventTime);
    for(int i=0;i<examNum;i++){
        printf("강의명, 시험의 시작 시간, 끝나는 시간, 시험인원을 차례대로 입력해주세요 : ");
        scanf("%s %d %d %d",tempExamName,&tempStartTime,&tempEndTime,&tempPeopleNum);
        strcpy(examArr[i].examName,tempExamName);
        examArr[i].startTime=tempStartTime;
        examArr[i].endTime=tempEndTime;
        examArr[i].peopleNum=tempPeopleNum;
    }

    bubbleSort(examArr,examNum);
   
    for(int i=0;i<examNum;i++){
        renewClassRoom(classRoomArr,examArr[i].startTime,ventTime,examArr[i].peopleNum);
        determineClassRoom(examArr[i],classRoomArr);
    }
    for(int i=0;i<30;i++){
        if(classRoomArr[i].examsInClassRoom!=0)minimumClassRoom++;
    }
    printf("\n총 %d개 강의실이 필요합니다.\n",minimumClassRoom);
    for(int i=0;i<30;i++){
        if(classRoomArr[i].examsInClassRoom!=0){
            printf("\nCLASS %d : ",classRoomArr[i].classRoomNum);
            for(int j=0;j<classRoomArr[i].examsInClassRoom;j++){
                printf("%s(%d-%d) ",classRoomArr[i].exams[j].examName,classRoomArr[i].exams[j].startTime,classRoomArr[i].exams[j].endTime);
            }
        }
    }
    if(classRoomArr[30].examsInClassRoom!=0){
        printf("\n온라인 : ");
        for(int j=0;j<classRoomArr[30].examsInClassRoom;j++){
            printf("%s(%d-%d) ",classRoomArr[30].exams[j].examName,classRoomArr[30].exams[j].startTime,classRoomArr[30].exams[j].endTime);
        }
        printf("\n");
    }
    free(examArr);
    free(classRoomArr);
    return 0;
}
void bubbleSort(Exam* examArr, int examNum){
    Exam temp;
    for(int i=0;i<examNum-1;i++){
        for(int j=0;j<examNum-i-1;j++){
            if(examArr[j].startTime>examArr[j+1].startTime){
                SWAP(examArr[j],examArr[j+1],temp);
            }
            else if(examArr[j].startTime==examArr[j+1].startTime && examArr[j].endTime>examArr[j+1].endTime){
                SWAP(examArr[j],examArr[j+1],temp);
            }
        }
    }
}
void renewClassRoom(ClassRoom* classRoomArr, int currentTime, int ventTime, int currentPeopleNum){
    int k;
    if(currentPeopleNum<=20){
        k=0;
    }
    else if(currentPeopleNum<=30){
        k=10;
    }
    else if(currentPeopleNum<=60){
        k=20;
    }
    else{
        return;
    }
    for(int i=k;i<k+10;i++){
        if(currentTime>=classRoomArr[i].exams[classRoomArr[i].examsInClassRoom-1].endTime + ventTime){
                classRoomArr[i].vacancy=1;
            }
    }
}
void determineClassRoom(Exam exam, ClassRoom* classRoomArr){
    if(exam.peopleNum<=20){
        for(int i=0;i<10;i++){
            if(classRoomArr[i].vacancy==1){
                classRoomArr[i].vacancy=0;
                classRoomArr[i].exams[classRoomArr[i].examsInClassRoom++]=exam;
                break;
            }
        }
    }
    else if (exam.peopleNum<=30){
        for(int i=10;i<20;i++){
            if(classRoomArr[i].vacancy==1){
                classRoomArr[i].vacancy=0;
                classRoomArr[i].exams[classRoomArr[i].examsInClassRoom++]=exam;
                break;
            }
        }
    }
    else if (exam.peopleNum<=60){
        for(int i=20;i<30;i++){
            if(classRoomArr[i].vacancy==1){
                classRoomArr[i].vacancy=0;
                classRoomArr[i].exams[classRoomArr[i].examsInClassRoom++]=exam;
                break;
            }
        }
    }
    else{
        classRoomArr[30].exams[classRoomArr[30].examsInClassRoom++]=exam;
    }
}