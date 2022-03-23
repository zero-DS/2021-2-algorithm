#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTEX 100
int visited[MAX_VERTEX]={0};
int queue[MAX_VERTEX]={0};
int front=-1,rear=-1,q_size=0;
int found=0;
typedef struct list{
    int data;
    struct list* link;
}List;
typedef struct graph{
    int graphnum;
    List* linklist[MAX_VERTEX];
}Graph;
Graph* init_Graph();
void add_Vertex(Graph*,int);
void add_Edge(Graph*,int,int);
void print_Graph(Graph*);
void DFS(Graph*,int,int);
void push(int);
int pop();
void BFS(Graph*,int,int);
int main(void){
    int vertexNum,edgeNum;
    int startVertex,targetVertex;
    int a,b;
    Graph* graph=init_Graph();
    
    printf("그래프의 정점 개수 입력 : ");
    scanf("%d",&vertexNum);
    printf("그래프의 간선 개수 입력 : ");
    scanf("%d",&edgeNum);
    for(int i=0;i<vertexNum;i++){
        add_Vertex(graph,i);
    }
    for(int i=0;i<edgeNum;i++){
        printf("연결된 두 정점 입력 : ");
        scanf("%d %d",&a,&b);
        add_Edge(graph,a-1,b-1);
    }
    printf("탐색 시작 지점 입력 : ");
    scanf("%d",&startVertex);
    printf("탐색 대상 입력 : ");
    scanf("%d",&targetVertex);
    printf("Depth First Search : ");
    DFS(graph,startVertex-1,targetVertex-1);
    found=0;
    memset(visited,0,MAX_VERTEX);
    printf("\nBreadth First Search : ");
    BFS(graph,startVertex-1,targetVertex-1);

    free(graph);
    return 0;
}
Graph* init_Graph(){
    Graph* new=(Graph*)malloc(sizeof(Graph));
    new->graphnum=0;
    for(int i=0;i<MAX_VERTEX;i++){
        new->linklist[i]=NULL;
    }
    return new;
}
void add_Vertex(Graph* g, int input){
    g->linklist[g->graphnum]=(List*)malloc(sizeof(List));
    g->linklist[g->graphnum]->link=NULL;
    g->linklist[g->graphnum]->data=input;
    g->graphnum++;
}
void add_Edge(Graph* g, int a, int b){
    List* temp1=(List*)malloc(sizeof(List));
    temp1->data=b;
    List* temp2=(List*)malloc(sizeof(List));
    temp2->data=a;

    temp1->link=g->linklist[a]->link;
    g->linklist[a]->link=temp1;
    temp2->link=g->linklist[b]->link;
    g->linklist[b]->link=temp2;
}
void print_Graph(Graph* g){
    for(int i=0;i<g->graphnum;i++){
        printf("%d : ",g->linklist[i]->data);
        List* curr=g->linklist[i]->link;
        while(curr!=NULL){
            printf("%d ",curr->data);
            curr=curr->link;
        }
        printf("\n");
    }
}
void DFS(Graph* g, int start, int target){
    if(visited[start]==1 || found==1)return;
    visited[start]=1;
    printf("%d ",g->linklist[start]->data+1);
    if(g->linklist[start]->data==target){
        found=1;
        return;
    }
    List* curr=g->linklist[start]->link;
    while(curr!=NULL){
        DFS(g,curr->data,target);
        curr=curr->link;
    }
}
void push(int data){
    if(q_size==0){
        front++;
    }
    rear++;
    queue[rear]=data;
    q_size++;
}
int pop(){
    if(q_size==0)return -1;
    int temp=queue[front];
    front++;
    if(q_size==1){
        front=-1;
        rear=-1;
    }
    q_size--;
    return temp;
}
void BFS(Graph* g, int start, int target){
    if(visited[start]==1 || found==1)return;
    visited[start]=1;
    printf("%d ",g->linklist[start]->data+1);
    if(g->linklist[start]->data==target){
        found=1;
        return;
    }
    List* curr=g->linklist[start]->link;
    while(curr!=NULL){
        if(visited[curr->data]==0)push(curr->data);
        curr=curr->link;
    }
    int popped=pop();
    while(popped!=-1){
        BFS(g,popped,target);
        popped=pop();
    }
    visited[start]=0;
}