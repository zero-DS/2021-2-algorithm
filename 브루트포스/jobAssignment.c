#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int arr[10][10]={{13, 6, 7, 12, 14, 15, 10, 11, 15, 4},
                  {8, 14, 11, 9, 6, 14, 7, 9, 16, 12},
                  {10, 8, 10, 10, 8, 15, 11, 5, 7, 9},
                  {13, 13, 16, 9, 13, 16, 15, 9, 14, 16},
                  {11, 4, 9, 14, 12, 11, 5, 16, 8, 14},
                  {7, 10, 12, 13, 4, 11, 16, 12, 15, 9},
                  {6, 11, 10, 11, 13, 15, 7, 16, 11, 12},
                  {7, 15, 5, 10, 4, 16, 12, 4, 10, 16},
                  {5, 14, 10, 15, 8, 8, 8, 14, 14, 4},
                  {8, 11, 4, 16, 8, 12, 4, 14, 9, 6}}; //가로줄이 job 세로줄이 person
int visitedJob[10]={0};
int personAssignedToJob[10];//1번 job부터 10번까지 부여된 사람들
int minCost=-1;
int minArr[10]={0};
void assign(int,int);
int checkFullAssigned();
void checkMin();
int main(void){
    memset(personAssignedToJob,-1,10);
    clock_t start = clock();
    assign(-1,0);
    clock_t end = clock();
    for(int i=0;i<10;i++){
        printf("%d번째 job : person %d\n",i+1,minArr[i]+1);
    }
    printf("-> minimum cost : %d\n",minCost);
    printf("job assignment time : %lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
void assign(int person, int job){
    if(person==-1){
        for(int i=0;i<10;i++){
            if(visitedJob[i]==0)assign(person+1,i);
        }
        return;
    }
    if(person<10){
        visitedJob[job]=1;
        personAssignedToJob[job]=person;
        if(checkFullAssigned()){
            checkMin();
            visitedJob[job]=0;
            personAssignedToJob[job]=-1;
            return;
        }
        for(int i=0;i<10;i++){
            if(visitedJob[i]==0)assign(person+1,i);
        }
        visitedJob[job]=0;
        personAssignedToJob[job]=-1;
    }
}
int checkFullAssigned(){
    for(int i=0;i<10;i++){
        if(visitedJob[i]==0)return 0;
    }
    return 1;
}
void checkMin(){
    int sum=0;
    for(int i=0;i<10;i++){
        sum+=arr[personAssignedToJob[i]][i];
    }
    if(minCost==-1){
        minCost=sum;
        memcpy(minArr,personAssignedToJob,sizeof(int)*10);
        return;
    }
    if(minCost>sum){
        minCost=sum;
        memcpy(minArr,personAssignedToJob,sizeof(int)*10);
    }
}