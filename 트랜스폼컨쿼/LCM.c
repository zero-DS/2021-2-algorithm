#include <stdio.h>
int GCD(int,int);
int LCM(int,int);
int main(void){
    int x,y;
    printf("LCM을 구할 두 수를 입력하세요 : ");
    scanf("%d %d",&x,&y);
    printf("%d와 %d의 LCM : %d\n",x,y,LCM(x,y));

    return 0;
}
int GCD(int a, int b){
    int temp;
    while(b){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int LCM(int a, int b){
    int result=(a*b)/GCD(a,b);
    return result;
}