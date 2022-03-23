#include <stdio.h>
#include <stdlib.h>
void GE(double**,int);
int main(void){
    double** simulEquation;
    int num;
    printf("해결하고자 하는 연립방정식의 미지수의 개수를 입력하세요 : ");
    scanf("%d",&num);
    simulEquation=(double**)malloc(sizeof(double*)*num);
    for(int i=0;i<num;i++){
        simulEquation[i]=(double*)malloc(sizeof(double)*(num+1));
    }
    for(int i=0;i<num;i++){
        printf("%d번째 방정식의 계수들을 입력하세요 ex) 2x+3y=5 -> 2 3 5 : ",i+1);
        for(int j=0;j<num+1;j++){
            int temp;
            scanf("%d",&temp);
            simulEquation[i][j]=(double)temp;
        }
    }
    GE(simulEquation,num);
    printf("Answer ->\n");
    for(int i=0;i<num;i++){
        printf("x%d = %.2lf\n",i,simulEquation[i][num]/simulEquation[i][i]);
    }
    for(int i=0;i<num;i++){
        free(simulEquation[i]);
    }
    free(simulEquation);
    return 0;
}
void GE(double** sEquation, int num){
    for(int i=0;i<num;i++){
        double diagnoal=sEquation[i][i];
        for(int j=i+1;j<num;j++){
            double factor=sEquation[j][i]/diagnoal;
            for(int k=i;k<num+1;k++){
                sEquation[j][k]-=sEquation[i][k]*factor;
            }
        }
    }
    printf("Gaussian Elimination Result ->\n");
    for(int i=0;i<num;i++){
        for(int j=0;j<num+1;j++){
            printf("%2.2lf ",sEquation[i][j]);
        }
        printf("\n");
    }
    for(int i=num-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            double factor=sEquation[j][i]/sEquation[i][i];
            sEquation[j][i]-=sEquation[i][i]*factor;
            sEquation[j][num]-=sEquation[i][num]*factor;
        }
    }
}