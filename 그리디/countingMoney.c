#include <stdio.h>
void greedyChange(int);
int main(void){
    int prize;
    int paidMoney;
    printf("물건의 가격을 입력하세요 : ");
    scanf("%d",&prize);
    printf("지불한 금액을 입력하세요 : ");
    scanf("%d",&paidMoney);
    greedyChange(paidMoney-prize);
    return 0;
}
void greedyChange(int money){
    if(money<0){
        printf("돈이 부족합니다.");
        return;
    }
    printf("\n총 거스름돈 -> %d원\n",money);
    int units[8]={50000,10000,5000,1000,500,100,50,10};
    int num[8]={0};
    for(int i=0;i<8;i++){
        num[i]=money/units[i];
        money-=units[i]*num[i];
    }
    for(int i=0;i<8;i++){
        printf("%5d원 %2d개\n",units[i],num[i]);
    }
}