#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int arr[7][7] = {
	0, 1, 1, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 1, 0,
	0, 0, 1, 0, 0, 1, 1,
	0, 0, 0, 1, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0};
void warshall(int);
int main(void){
    int size=sqrt(sizeof(arr)/sizeof(int));
    printf("Adjacency Matrix ->\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    warshall(size);
    printf("Transitive Closure ->\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void warshall(int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                if(i==j || i==k)continue;
                if(arr[i][j]==1&&arr[k][i]==1)arr[k][j]=1;
            }
        }
    }
}