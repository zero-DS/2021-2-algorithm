#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    int size;
    int lineCount=0;
    int letterCount=0;
    int coincideCount=0;
    char key[14]="어린 왕자";
    clock_t start1 = clock();
    FILE *fp = fopen("TheLittlePrince.txt", "r");  
    while(1){
        if(feof(fp)!=0)break;
        letterCount=0;
        char buffer[1200]={0};
        fgets(buffer,1200,fp);
        int len = strlen(buffer);
        for(int i=0;i<len;i++){
            for(int j=0;j<13;j++){
                if(i+j<len&&buffer[i+j]!=key[j])break;
                if(j==12){
                    coincideCount++;
                    printf("%d번째 일치 : line%d, index%d\n",coincideCount,lineCount,letterCount);
                }
            }
            letterCount++;
        }
        lineCount++;
    }
    printf("%s가 총 %d번 존재합니다.\n",key,coincideCount);
    fclose(fp);
    clock_t end1 = clock();
    printf("string matching time : %lf\n",(double)(end1-start1)/CLOCKS_PER_SEC);
    return 0;
}