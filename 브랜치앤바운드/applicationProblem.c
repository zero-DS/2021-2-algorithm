#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRODUCT_COMPANY_NUM 6
char productName[PRODUCT_COMPANY_NUM+1][10]={
    {"에어컨"},{"실외기"},{"냉장고"},{"보일러"},{"샷시"},{"조명"}
};
char companyName[PRODUCT_COMPANY_NUM+1]={'A','B','C','D','E','F'};
int costArr[PRODUCT_COMPANY_NUM+1][PRODUCT_COMPANY_NUM+1]={
    {0,0,0,0,0,0,0},
    {0,20,12,18,12,230,37},{0,23,14,29,14,150,43},{0,17,16,15,12,300,40},
    {0,19,13,23,11,220,35},{0,21,15,15,14,190,30},{0,25,14,15,13,280,31}
};
void selectProduct(char*);
void selectCompany(char);
int** getArr(int);
void assignStart(int);
void assign(int,int,int**,int);
int checkFullAssigned(int);
void checkMin(int**,int);
int* visitedProduct;
int* companyAssignedToProduct;
int minCost=-1;
int* minArr;
int companyCnt=0;
int main(void){
    char pTemp[30]={0};
    char cTemp;
    while(companyCnt<PRODUCT_COMPANY_NUM){
        printf("수리할 제품명을 입력하세요 : ");
        scanf("%s",pTemp);
        if(!strcmp(pTemp,"Q")){
            getchar();
            break;
        }
        selectProduct(pTemp);
    }
    for(int i=0;i<companyCnt;i++){
        printf("원하는 업체 후보 %d은? ",i+1);
        scanf("%s",pTemp);
        cTemp=pTemp[strlen(pTemp)-1];
        selectCompany(cTemp);
    }
    visitedProduct=(int*)malloc(sizeof(int)*companyCnt);
    companyAssignedToProduct=(int*)malloc(sizeof(int)*companyCnt);
    minArr=(int*)malloc(sizeof(int)*companyCnt);

    assignStart(companyCnt);

    free(visitedProduct);
    free(companyAssignedToProduct);
    free(minArr);
    return 0;
}
void selectProduct(char* pName){
    for(int i=0;i<PRODUCT_COMPANY_NUM;i++){
        if(!strcmp(pName,productName[i])){
            if(costArr[0][i+1]==1){
                printf("해당 제품은 이미 입력하셨습니다.\n");
                return;
            }
            costArr[0][i+1]=1;
            companyCnt++;
            return;
        }
    }
    for(int i=0;i<PRODUCT_COMPANY_NUM;i++){
        printf("%s ",productName[i]);
    }
    printf("만 입력 가능합니다.\n");
}
void selectCompany(char c){
    for(int i=0;i<PRODUCT_COMPANY_NUM;i++){
        if(c==companyName[i]){
            if(costArr[i+1][0]==1){
                printf("해당 업체는 이미 입력하셨습니다.\n");
                return;
            }
            costArr[i+1][0]=1;
            return;
        }
    }
    for(int i=0;i<PRODUCT_COMPANY_NUM;i++){
        printf("업체%c ",companyName[i]);
    }
    printf("만 입력 가능합니다.\n");
}
int** getArr(int size){
    int** arr=(int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++){
        arr[i]=(int*)malloc(sizeof(int)*size);
    }
    int m=0,n=0;
    for(int i=1;i<PRODUCT_COMPANY_NUM+1;i++){
        if(costArr[0][i]==1){
            for(int j=1;j<PRODUCT_COMPANY_NUM+1;j++){
                if(costArr[j][0]==1){
                    arr[n][m]=costArr[j][i];
                    n++;
                }
            }
            n=0;
            m++;
        }
    }
    return arr;
}

void assignStart(int size){
    int** arr=getArr(size);
    char** newProName=(char**)malloc(sizeof(char*)*size);
    for(int i=0;i<size;i++){
        newProName[i]=(char*)malloc(sizeof(char)*10);
    }
    int* newComName=(int*)malloc(sizeof(int)*size);
    int m=0,n=0;
    for(int i=0;i<PRODUCT_COMPANY_NUM;i++){
        if(costArr[0][i+1]==1)strcpy(newProName[m++],productName[i]);
        if(costArr[i+1][0]==1)newComName[n++]=companyName[i];
    }
    assign(-1,0,arr,size);
    printf("업체 추천 조합 : ");
    for(int i=0;i<size;i++){
        printf("(%s- 업체%c) ",newProName[minArr[i]],newComName[i]);
    }

    for(int i=0;i<size;i++){
        free(arr[i]);
    }
    free(arr);
    for(int i=0;i<size;i++){
        free(newProName[i]);
    }
    free(newProName);
    free(newComName);
}
void assign(int company, int product, int** arr,int size){
    if(company==-1){
        for(int i=0;i<size;i++){
            if(visitedProduct[i]==0)assign(company+1,i,arr,size);
        }
        return;
    }
    if(company<size){
        visitedProduct[product]=1;
        companyAssignedToProduct[product]=company;
        if(checkFullAssigned(size)){
            checkMin(arr,size);
            visitedProduct[product]=0;
            companyAssignedToProduct[product]=-1;
            return;
        }
        for(int i=0;i<size;i++){
            if(visitedProduct[i]==0)assign(company+1,i,arr,size);
        }
        visitedProduct[product]=0;
        companyAssignedToProduct[product]=-1;
    }
}
int checkFullAssigned(int size){
    for(int i=0;i<size;i++){
        if(visitedProduct[i]==0)return 0;
    }
    return 1;
}
void checkMin(int** arr,int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[companyAssignedToProduct[i]][i];
    }
    if(minCost==-1){
        minCost=sum;
        memcpy(minArr,companyAssignedToProduct,sizeof(int)*size);
        return;
    }
    if(minCost>sum){
        minCost=sum;
        memcpy(minArr,companyAssignedToProduct,sizeof(int)*size);
    }
}