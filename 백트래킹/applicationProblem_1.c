#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRODUCT_NUM 29
#define PRODUCT_NAME_LIMIT 100
#define SWAP(a,b,t) {t=a;a=b;b=t;}
void bubbleSort(int*);
char productNameArr[PRODUCT_NUM+1][PRODUCT_NAME_LIMIT+1]={
    {"더블화이트갈릭팩"},{"화이트갈릭팩"},{"바삭킹&모짜볼10,까망베르치즈소스"},{"몬스터X세트"},{"통새우X세트"},{"더블화이트갈릭와퍼세트"},
    {"스태커2와퍼세트"},{"기네스콰트로치즈와퍼세트"},{"콰트로치즈와퍼세트"},{"베이컨치즈와퍼세트"},{"리얼와퍼세트"},{"불고기와퍼세트"},
    {"치즈와퍼세트"},{"더블화이트갈릭와퍼"},{"화이트갈릭와퍼"},{"스태커2와퍼"},{"리얼와퍼"},{"치즈와퍼"},{"통새우와퍼주니어"},
    {"와퍼주니어"},{"치즈와퍼주니어"},{"앵그리너겟킹4조각"},{"앵그리너겟킹6조각"},{"치즈프라이"},{"프렌치프라이(L)"},{"프렌치프라이(R)"},
    {"아이스아메리카노"},{"코카콜라(L)"},{"코카콜라(R)"}
};
int productPriceArr[PRODUCT_NUM]={
    22100,20600,16000,11700,11100,12200,10200,10700,10100,10100,9300,9300,9900,9900,
    7900,9600,7000,7600,5800,5200,5500,3200,4300,3300,3300,2400,2200,2700,2500
};
int minOrderPrice;
int foundFlag=0;
void priceSatisfy(int*,int,int,int);
void printSatisfyingProducts(int*,int);
int main(void){
    int selected[PRODUCT_NUM]={0};
    int orderPrice;
    printf("최소주문금액을 입력해주세요 : ");
    scanf("%d",&minOrderPrice);
    orderPrice=minOrderPrice;
    bubbleSort(productPriceArr);
    while(!foundFlag){
        memset(selected,0,PRODUCT_NUM);
        priceSatisfy(selected,orderPrice,0,0);
        if(foundFlag==0){
            if(orderPrice==minOrderPrice)printf("최소주문금액인 ");
            printf("%d원을 만족하는 조합이 없습니다. 100원 올려서 다시 진행합니다.\n",orderPrice);
            orderPrice+=100;
        }
    }

    return 0;
}
void priceSatisfy(int* selected, int orderPrice, int sum, int currentProduct){
    if(currentProduct>=PRODUCT_NUM)return;
    if(sum==orderPrice){
        foundFlag=1;
        printSatisfyingProducts(selected,orderPrice);
        return;
    }
    if(sum>orderPrice)return;
    selected[currentProduct]=1;
    sum+=productPriceArr[currentProduct];
    priceSatisfy(selected,orderPrice,sum,currentProduct+1);
    selected[currentProduct]=0;
    sum-=productPriceArr[currentProduct];
    priceSatisfy(selected,orderPrice,sum,currentProduct+1);
    
}
void printSatisfyingProducts(int* selected, int orderPrice){
    for(int i=0;i<PRODUCT_NUM;i++){
        if(selected[i]==1){
            printf("%s ",productNameArr[i]);
        }
    }
    printf("--> ");
    if(orderPrice==minOrderPrice){
        printf("최소주문금액 ");
    }
    printf("%d원 만족\n",orderPrice);
}
void bubbleSort(int* arr){
    char temp[101]={0};
    int tempNum;
    for(int i=0;i<PRODUCT_NUM-1;i++){
        for(int j=0;j<PRODUCT_NUM-1-i;j++){
            if(arr[j]<arr[j+1]){
                SWAP(arr[j],arr[j+1],tempNum);
                strcpy(temp,productNameArr[j]);
                strcpy(productNameArr[j],productNameArr[j+1]);
                strcpy(productNameArr[j+1],temp);
            }
        }
    }
}