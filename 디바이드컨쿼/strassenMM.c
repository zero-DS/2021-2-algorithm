#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** matrix_Sum(int**,int**,int);
int** matrix_Substract(int**,int**,int);
int** matrix_Multiply(int**,int**,int);
int main(void){
    int MATSIZE;
    printf("strassen's algorithm\n");
    printf("N x N 행렬의 크기를 입력하세요 (2의 n제곱꼴만 가능) : ");
    scanf("%d",&MATSIZE);
    int** arr1=(int**)malloc(sizeof(int*)*MATSIZE);
    int** arr2=(int**)malloc(sizeof(int*)*MATSIZE);
    for(int i=0;i<MATSIZE;i++){
        arr1[i]=(int*)malloc(sizeof(int)*MATSIZE);
        arr2[i]=(int*)malloc(sizeof(int)*MATSIZE);
    }
    printf("첫번째 행렬을 입력하세요 : \n");
    for(int i=0;i<MATSIZE;i++){
        for(int j=0;j<MATSIZE;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("두번째 행렬을 입력하세요 : \n");
    for(int i=0;i<MATSIZE;i++){
        for(int j=0;j<MATSIZE;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    int** result = matrix_Multiply(arr1,arr2,MATSIZE);
    printf("matrix multiplication result\n");
    for(int i=0;i<MATSIZE;i++){
        for(int j=0;j<MATSIZE;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<MATSIZE;i++){
        free(result[i]);
    }
    free(result);
    return 0;
}
int** matrix_Sum(int** a, int** b, int len){
    int** result = (int**)calloc(len,sizeof(int*));
    for(int i=0;i<len;i++)result[i] = (int*)calloc(len,sizeof(int));
    for(int i=0;i<len;i++)for(int j=0;j<len;j++)result[i][j]+=(a[i][j]+b[i][j]);
    return result;
}
int** matrix_Substract(int** a, int** b, int len){
    int** result = (int**)calloc(len,sizeof(int*));
    for(int i=0;i<len;i++)result[i] = (int*)calloc(len,sizeof(int));
    for(int i=0;i<len;i++)for(int j=0;j<len;j++)result[i][j]+=(a[i][j]-b[i][j]);
    return result;
}
int** matrix_Multiply(int** a, int** b, int len){
    int** result = (int**)calloc(len,sizeof(int*));
    for(int i=0;i<len;i++)result[i] = (int*)calloc(len,sizeof(int));
    
    if(len==1){
        result[0][0]=a[0][0]*b[0][0];
        return result;
    }
    int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
    
    int** a11 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)a11[i] = (int*)calloc(len/2,sizeof(int));
    int** a12 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)a12[i] = (int*)calloc(len/2,sizeof(int));
    int** a21 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)a21[i] = (int*)calloc(len/2,sizeof(int));
    int** a22 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)a22[i] = (int*)calloc(len/2,sizeof(int));
    int** b11 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)b11[i] = (int*)calloc(len/2,sizeof(int));
    int** b12 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)b12[i] = (int*)calloc(len/2,sizeof(int));
    int** b21 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)b21[i] = (int*)calloc(len/2,sizeof(int));
    int** b22 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)b22[i] = (int*)calloc(len/2,sizeof(int));
    
    for(int i=0;i<len/2;i++){
        for(int j=0;j<len/2;j++){
            a11[i][j]=a[i][j];
            b11[i][j]=b[i][j];
            a12[i][j]=a[i][len/2+j];
            b12[i][j]=b[i][len/2+j];
            a21[i][j]=a[len/2+i][j];
            b21[i][j]=b[len/2+i][j];
            a22[i][j]=a[len/2+i][len/2+j];
            b22[i][j]=b[len/2+i][len/2+j];
        }
    }
    
    M1=matrix_Multiply(matrix_Sum(a11,a22,len/2),matrix_Sum(b11,b22,len/2),len/2);
    M2=matrix_Multiply(matrix_Sum(a21,a22,len/2),b11,len/2);
    M3=matrix_Multiply(a11,matrix_Substract(b12,b22,len/2),len/2);
    M4=matrix_Multiply(a22,matrix_Substract(b21,b11,len/2),len/2);
    M5=matrix_Multiply(matrix_Sum(a11,a12,len/2),b22,len/2);
    M6=matrix_Multiply(matrix_Substract(a21,a11,len/2),matrix_Sum(b11,b12,len/2),len/2);
    M7=matrix_Multiply(matrix_Substract(a12,a22,len/2),matrix_Sum(b21,b22,len/2),len/2);
    
    int** C11 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)C11[i] = (int*)calloc(len/2,sizeof(int));
    int** C12 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)C12[i] = (int*)calloc(len/2,sizeof(int));
    int** C21 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)C21[i] = (int*)calloc(len/2,sizeof(int));
    int** C22 = (int**)calloc(len/2,sizeof(int*));
    for(int i=0;i<len/2;i++)C22[i] = (int*)calloc(len/2,sizeof(int));

    C11=matrix_Substract(matrix_Sum(matrix_Sum(M1,M4,len/2),M7,len/2),M5,len/2);
    C12=matrix_Sum(M3,M5,len/2);
    C21=matrix_Sum(M2,M4,len/2);
    C22=matrix_Sum(matrix_Substract(M1,M2,len/2),matrix_Sum(M3,M6,len/2),len/2);

    for(int i=0;i<len/2;i++){
        for(int j=0;j<len/2;j++){
            result[i][j]=C11[i][j];
            result[i][len/2+j]=C12[i][j];
            result[len/2+i][j]=C21[i][j];
            result[len/2+i][len/2+j]=C22[i][j];
        }
    }
    for(int i=0;i<len/2;i++){
        free(M1[i]);free(M2[i]);free(M3[i]);free(M4[i]);free(M5[i]);free(M6[i]);free(M7[i]);
        free(a11[i]);free(a12[i]);free(a21[i]);free(a22[i]);free(b11[i]);free(b12[i]);free(b21[i]);free(b22[i]);
        free(C11[i]);free(C12[i]);free(C21[i]);free(C22[i]);
    }
    free(M1);free(M2);free(M3);free(M4);free(M5);free(M6);free(M7);
    free(a11);free(a12);free(a21);free(a22);free(b11);free(b12);free(b21);free(b22);
    free(C11);free(C12);free(C21);free(C22);
    
    return result;
}