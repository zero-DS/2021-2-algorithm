#include <stdio.h>
#include <stdlib.h>
void levelOne(int**,int,int);
void levelTwo(int**,int,int);
void levelThree(int**,int,int);
int getMax(int,int);
int M,N;
int main(void){
    printf("공간 크기 : ");
    scanf("%d %d",&M,&N);
    int** arr=(int**)malloc(sizeof(int*)*M);
    for(int i=0;i<M;i++){
        arr[i]=(int*)calloc(N,sizeof(int));
    }
    int socialDistanceLevel;
    int fixX,fixY;
    int peopleCnt=0;
    printf("거리두기 단계 : ");
    scanf("%d",&socialDistanceLevel);
    printf("지정석 좌표 : ");
    scanf("%d %d",&fixX,&fixY);
    switch (socialDistanceLevel)
    {
    case 1:
        levelOne(arr,fixX,fixY);
        break;
    case 2:
        levelTwo(arr,fixX,fixY);
        break;
    case 3:
        levelThree(arr,fixX,fixY);
        break;
    default:
        break;
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==-1)printf("0");
            else {
                printf("%d",arr[i][j]);
                peopleCnt++;
            }
        }
        printf("\n");
    }
    printf("이용할 수 있는 인원은 %d명입니다.\n",peopleCnt);
    for(int i=0;i<M;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}
void levelOne(int** arr, int x, int y){
    int** temp=(int**)malloc(sizeof(int*)*M);
    for(int i=0;i<M;i++){
        temp[i]=(int*)malloc(sizeof(int)*N);
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==0){
                for(int k=0;k<M;k++){
                    for(int l=0;l<N;l++){
                        temp[k][l]=arr[k][l];
                    }
                }
                arr[i][j]=1;
                if(i-1>=0 && arr[i-1][j]!=1)arr[i-1][j]=-1;
                if(j+1<=N-1 && arr[i][j+1]!=1)arr[i][j+1]=-1;
                if(i+1<=M-1 && arr[i+1][j]!=1)arr[i+1][j]=-1;
                if(j-1>=0 && arr[i][j-1]!=1)arr[i][j-1]=-1;
                if(arr[x][y]==-1){
                    for(int k=0;k<M;k++){
                        for(int l=0;l<N;l++){
                            arr[k][l]=temp[k][l];
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<M;i++){
        free(temp[i]);
    }
    free(temp);
}
void levelTwo(int** arr, int x, int y){
    int** temp=(int**)malloc(sizeof(int*)*M);
    for(int i=0;i<M;i++){
        temp[i]=(int*)malloc(sizeof(int)*N);
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==0){
                for(int k=0;k<M;k++){
                    for(int l=0;l<N;l++){
                        temp[k][l]=arr[k][l];
                    }
                }
                arr[i][j]=1;
                if(i-1>=0 && arr[i-1][j]!=1)arr[i-1][j]=-1;
                if(j+1<=N-1 && arr[i][j+1]!=1)arr[i][j+1]=-1;
                if(i+1<=M-1 && arr[i+1][j]!=1)arr[i+1][j]=-1;
                if(j-1>=0 && arr[i][j-1]!=1)arr[i][j-1]=-1;
                if(i-1>=0 && j-1>=0 && arr[i-1][j-1]!=1)arr[i-1][j-1]=-1;
                if(i-1>=0 && j+1<=N-1 && arr[i-1][j+1]!=1)arr[i-1][j+1]=-1;
                if(i+1<=M-1 && j+1<=N-1 && arr[i+1][j+1]!=1)arr[i+1][j+1]=-1;
                if(i+1<=M-1 && j-1>=0 && arr[i+1][j-1]!=1)arr[i+1][j-1]=-1;
                if(arr[x][y]==-1){
                    for(int k=0;k<M;k++){
                        for(int l=0;l<N;l++){
                            arr[k][l]=temp[k][l];
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<M;i++){
        free(temp[i]);
    }
    free(temp);
}
void levelThree(int** arr, int x, int y){
    int diagonal = getMax(M,N);
    int** temp=(int**)malloc(sizeof(int*)*M);
    for(int i=0;i<M;i++){
        temp[i]=(int*)malloc(sizeof(int)*N);
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==0){
                for(int k=0;k<M;k++){
                    for(int l=0;l<N;l++){
                        temp[k][l]=arr[k][l];
                    }
                }
                arr[i][j]=1;
                for(int k=0;k<M;k++){
                    if(k!=i && arr[k][j]!=1)arr[k][j]=-1;
                }
                for(int k=0;k<N;k++){
                    if(k!=j && arr[i][k]!=1)arr[i][k]=-1;
                }
                for(int k=1;k<diagonal+1;k++){
                    if(i-k>=0 && j-k>=0 && arr[i-k][j-k]!=1)arr[i-k][j-k]=-1;
                    if(i-k>=0 && j+k<=N-1 && arr[i-k][j+k]!=1)arr[i-k][j+k]=-1;
                    if(i+k<=M-1 && j+k<=N-1 && arr[i+k][j+k]!=1)arr[i+k][j+k]=-1;
                    if(i+k<=M-1 && j-k>=0 && arr[i+k][j-k]!=1)arr[i+k][j-k]=-1;
                }
                if(arr[x][y]==-1){
                    for(int k=0;k<M;k++){
                        for(int l=0;l<N;l++){
                            arr[k][l]=temp[k][l];
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<M;i++){
        free(temp[i]);
    }
    free(temp);
}
int getMax(int a, int b){
    if(a<b)return b;
    else return a;
}