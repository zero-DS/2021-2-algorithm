#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int* knapsack;
int* weightArr;
int* valueArr;
int* binary;
int weightLimit;
int num;
int maxValue=0;
int maxWeight=0;
int maxOnes=0;
int* maxBinary;
void put_into_knapsack(int,int,int);
void printKnapsack(int);
int main(void){    
    printf("knapsack's item limit 입력 : ");
    scanf("%d",&num);
    printf("item's weight limit 입력 : ");
    scanf("%d",&weightLimit);
    knapsack=(int*)malloc(sizeof(int)*num);
    weightArr=(int*)malloc(sizeof(int)*num);
    valueArr=(int*)malloc(sizeof(int)*num);
    binary=(int*)malloc(sizeof(int)*num);
    maxBinary=(int*)malloc(sizeof(int)*(num+1));
    
    memset(binary,0,num);
    memset(maxBinary,0,num);
    
    printf("각 item의 weight, value 입력 : \n");
    for (int i=0;i<num;i++){
        printf("%d번째 item 입력 : ",i+1);
        scanf("%d %d",&weightArr[i],&valueArr[i]);
    }
    clock_t start = clock();
    put_into_knapsack(0,1,0);
    clock_t end = clock();
    printf("\noptimal result -> ");
    printf("{");
    int cnt=0;
    for(int i=0;i<num;i++){
        if(maxBinary[i+1]==1){
            printf("%d",i+1);
            cnt++;
            if(cnt!=maxOnes)printf(",");
        }
    }
    printf("} ");
    printf("Total weight : %d , Total value : %d\n",maxWeight,maxValue);
    printf("knapsack brute force time : %lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(knapsack);
    free(weightArr);
    free(valueArr);
    free(binary);
    free(maxBinary);
    return 0;
}
void put_into_knapsack(int start, int p, int ones){
    
    if(p==1)printKnapsack(ones);
    binary[start]=1;
    if(start<num)put_into_knapsack(start+1,1,ones+1);
    binary[start]=0;
    if(start<num)put_into_knapsack(start+1,0,ones);
}
void printKnapsack(int ones){
    int cnt=0;
    int weightSum=0;
    int valueSum=0;
    if(ones==0){
        printf("Null\n");
        return;
    }
    printf("{");
    for(int i=0;i<num;i++){
        if(binary[i]==1){
            weightSum+=weightArr[i];
            valueSum+=valueArr[i];
            printf("%d",i+1);
            cnt++;
            if(cnt!=ones)printf(",");
        }
    }
    printf("} ");

    printf("Total weight : %d ",weightSum);
    if(weightSum<=weightLimit){
        printf("Total value : %d\n",valueSum);
        if(valueSum>=maxValue){
            if(!(valueSum==maxValue&&weightSum>maxWeight)){
                maxValue=valueSum;
                maxWeight=weightSum;
                maxOnes=ones;
                for(int i=0;i<num;i++){
                    maxBinary[i+1]=binary[i];
                }
            }
        }
    }
    else printf("not feasible\n");
}