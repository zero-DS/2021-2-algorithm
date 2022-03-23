#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int visited[5]={0};
int course[5]={-1,-1,-1,-1,-1};
int min_course[5]={-1,-1,-1,-1,-1};
int arr[5][5]={
        {0,2,3,2,3},{2,0,3,4,1},{3,3,0,2,4},{2,4,2,0,5},{3,1,4,5,0}
    };
int min_length=-1;
int startpoint;
void travel(int,int,int);
int main(void){
    clock_t start = clock();
    startpoint=0;
    travel(startpoint,0,0);
    printf("\n최적 경로 : ");
    for(int i=0;i<5;i++){
        printf("%d -> ",min_course[i]+1);
    }
    printf("%d",min_course[startpoint]+1);
    printf(" 최적 길이 : %d",min_length);
    clock_t end = clock();
    printf("\nTSP time : %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
void travel(int start, int length, int courseIdx){
    int flag=1;
    if(visited[start]==0){
        course[courseIdx]=start;
        visited[start]=1;
        for(int i=0;i<5;i++){
            if(visited[i]==0)flag=0;
        }
        if(flag==1){
            length+=arr[start][startpoint];
            if(min_length==-1){
                min_length=length;
                for(int i=0;i<5;i++){
                    min_course[i]=course[i];
                }
            }
            else{
                if(min_length>length){
                    min_length=length;
                    for(int i=0;i<5;i++){
                        min_course[i]=course[i];
                    }
                }
            }
            printf("경로 : ");
            for(int i=0;i<5;i++){
                printf("%d -> ",course[i]+1);
            }
            printf("%d",course[startpoint]+1);
            printf(" 길이 : %d",length);
            printf("\n");
        }
        for(int i=0;i<5;i++){
            if(visited[i]==0)travel(i,length+arr[start][i],courseIdx+1);
        }
    }
    course[courseIdx]=-1;
    visited[start]=0;
}