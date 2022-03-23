#include <stdio.h>
#include <math.h>
int karatsuba(int,int);
int getLen(int);
int main(void){
    int x=101, y=202;
    printf("%d * %d = %d\n",x,y,karatsuba(x,y));
    return 0;
}
int karatsuba(int x, int y){
    int B=10,m;
    int len1=getLen(x),len2=getLen(y),len;
    if (len1<=len2)len=len1;
    else len=len2;
    if (len<2) return x*y;
    m=(int)(len/2);

    int x1=x/(int)pow(B,m);
    int x0=x%(int)pow(B,m);
    int y1=y/(int)pow(B,m);
    int y0=y%(int)pow(B,m);
    
    int L=karatsuba(x1,y1), N=karatsuba(x0,y0);
    int M=L+N-karatsuba((x1-x0),(y1-y0));
    return L*(int)pow(B,m*2)+M*(int)pow(B,m)+N;
}
int getLen(int num){
    int len=0;
    while(num){
        len++;
        num/=10;
    }
    return len;
}