#include <stdio.h>
void GCD(int,int);
int result;
int main(void){
    int a,b;
    printf("최대공약수를 구할 두 수를 입력하세요 : ");
    scanf("%d %d",&a,&b);
    GCD(a,b);
    printf("GCD = %d",result);

    return 0;
}
void GCD(int m, int n){
    int r=m%n;
    printf("m = %d n = %d\n",m,n);
    if(n==0){
        result=m;
        return;
    }
    m=n;
    n=r;
    GCD(m,n);
}