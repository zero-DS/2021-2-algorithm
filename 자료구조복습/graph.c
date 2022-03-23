#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTEX 100
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTEX]={0};
int pathlist[100]={0};
int pathidx=0;
int min_pathlist[100]={0};
int min_path=-1;
int connectFlag=0;
typedef struct list{
    char station[15];
    struct list* link;
}List;
typedef struct graph{
    int graphnum;
    char stationlist[20][MAX_VERTEX];
    List* linklist[MAX_VERTEX];
}Graph;
Graph* Graph_init();
void print_interface();
void make_metro(Graph*);
void Add_vertex(Graph*,char*);
void Delete_vertex(Graph*,char*);
void Add_edge(Graph*,char*,char*);
void Delete_edge(Graph*,char*,char*);
void modify_linklist_stationlist(Graph*,int);
int Count_vertex(Graph*);
int Count_edge(Graph*);
void Shortest_distance(Graph*,char*,char*);
void Shortest_distance_through(Graph*,char*,char*,char*);
void DFS(Graph*,int,int,int);
void DFS_2(Graph*,int,int);
int isitconnected(Graph*,char*,char*);
void connected_vertex(Graph*,char*);
void print_all(Graph*);
int main(void){
    Graph* seoulmetro = Graph_init();
    make_metro(seoulmetro);
    int flag=1;
    int cmd;
    char a[20],b[20],c[20];
    while(flag){
        print_interface();
        scanf("%d",&cmd);
        switch (cmd)
        {
        case 1:{
            printf("\n추가하실 역의 이름을 입력하세요: ");
            scanf("%s",a);
            Add_vertex(seoulmetro,a);
        }break;
        case 2:{
            printf("\n삭제하실 역의 이름을 입력하세요: ");
            scanf("%s",a);
            Delete_vertex(seoulmetro,a);
        }break;
        case 3:{
            printf("\n연결을 추가할 두 역의 이름을 입력하세요: ");
            scanf("%s %s",a,b);
            Add_edge(seoulmetro,a,b);
        }break;
        case 4:{
            printf("\n연결을 삭제할 두 역의 이름을 입력하세요: ");
            scanf("%s %s",a,b);
            Delete_edge(seoulmetro,a,b);
        }break;
        case 5:{
            printf("\n전체 역의 개수는 %d개입니다.",Count_vertex(seoulmetro));
        }break;
        case 6:{
            printf("\n전체 연결의 개수는 %d개입니다.",Count_edge(seoulmetro));
        }break;
        case 7:{
            printf("\n최단경로를 확인할 출발지와 목적지를 차례대로 입력하세요: ");
            scanf("%s %s",a,b);
            Shortest_distance(seoulmetro,a,b);
        }break;
        case 8:{
            printf("\n최단경로를 확인할 출발지, 경유지, 목적지를 차례대로 입력하세요: ");
            scanf("%s %s %s",a,b,c);
            Shortest_distance_through(seoulmetro,a,b,c);
        }break;
        case 9:{
            printf("\n연결 여부를 확인할 두 역을 입력하세요: ");
            scanf("%s %s",a,b);
            int connected=isitconnected(seoulmetro,a,b);
            if(connected==TRUE)printf("\n연결돼있습니다.");
            else if(connected==FALSE) printf("\n연결되어있지 않습니다.");
        }break;
        case 10:{
            printf("\n연결돼있는 역들을 확인하고 싶은 대상을 입력하세요: ");
            scanf("%s",a);
            connected_vertex(seoulmetro,a);
        }break;
        case 11:{
            printf("\n전체 노선도를 출력합니다.\n");
            print_all(seoulmetro);
        }break;
        case 12:{
            flag=0;
            printf("\n프로그램을 종료합니다.");
        }break;
        default:{
            printf("\n유효하지 않은 명령어입니다.");
        }break;
        }
    }
    return 0;
}
Graph* Graph_init(){
    Graph* new = (Graph*)malloc(sizeof(Graph));
    new->graphnum=0;
    for(int i=0;i<MAX_VERTEX;i++){
        new->linklist[i]=NULL;
    }
    return new;
}
void print_interface(){
    printf("\n========= 지하철 노선도 =========\n");
    printf("= 1. 역 추가                    =\n");
    printf("= 2. 역 삭제                    =\n");
    printf("= 3. 역 사이 연결 추가          =\n");
    printf("= 4. 역 사이 연결 삭제          =\n");
    printf("= 5. 전체 역 개수 확인          =\n");
    printf("= 6. 전체 연결 개수 확인        =\n");
    printf("= 7. 두 역간 최단경로 확인      =\n");
    printf("= 8. 한 역을 들르는 최단경로    =\n");
    printf("= 9. 역 사이 연결 확인          =\n");
    printf("= 10. 대상과 연결된 역들 확인   =\n");
    printf("= 11. 노선도 전체 출력          =\n");
    printf("= 12. 프로그램 종료             =\n");
    printf("=================================\n");
    printf("원하시는 기능의 번호를 입력해주세요 : ");
}
void make_metro(Graph* seoulmetro){
    Add_vertex(seoulmetro,"시청");
    Add_vertex(seoulmetro,"종로3가");
    Add_vertex(seoulmetro,"회현");
    Add_vertex(seoulmetro,"명동");
    Add_vertex(seoulmetro,"종각");
    Add_vertex(seoulmetro,"종로5가");
    Add_vertex(seoulmetro,"을지로3가");
    Add_vertex(seoulmetro,"을지로4가");
    Add_vertex(seoulmetro,"을입구");
    Add_vertex(seoulmetro,"충무로");
    Add_vertex(seoulmetro,"동대문");
    Add_vertex(seoulmetro,"동역공");
    Add_vertex(seoulmetro,"서울역");
    
    Add_edge(seoulmetro,"시청","종각");
    Add_edge(seoulmetro,"을입구","시청");
    Add_edge(seoulmetro,"시청","서울역");
    Add_edge(seoulmetro,"서울역","회현");
    Add_edge(seoulmetro,"명동","회현");
    Add_edge(seoulmetro,"명동","충무로");
    Add_edge(seoulmetro,"동역공","충무로");
    Add_edge(seoulmetro,"을지로3가","충무로");
    Add_edge(seoulmetro,"을입구","을지로3가");
    Add_edge(seoulmetro,"을지로3가","을지로4가");
    Add_edge(seoulmetro,"종로3가","을지로4가");
    Add_edge(seoulmetro,"을지로4가","동역공");
    Add_edge(seoulmetro,"동역공","동대문");
    Add_edge(seoulmetro,"동대문","종로5가");
    Add_edge(seoulmetro,"종로5가","종로3가");
    Add_edge(seoulmetro,"종로3가","을지로3가");
    Add_edge(seoulmetro,"종로3가","종각");
    
}
void Add_vertex(Graph* g,char* name){
    g->linklist[g->graphnum] = (List*)malloc(sizeof(List));
    g->linklist[g->graphnum]->link=NULL;
    strcpy(g->stationlist[g->graphnum],name);
    g->graphnum++;
}
void Delete_vertex(Graph* g, char* name){
    int num=-1;
    for(int i=0;i<g->graphnum;i++){
        if(!strcmp(name,g->stationlist[i])){
            num=i;
            break;
        }
    }
    if(num==-1){
        printf("\n삭제하시려는 역이 존재하지 않습니다. 재시도하세요.");
        return;
    }
    List* curr = g->linklist[num]->link;
    while(curr!=NULL){
        List* temp = curr;
        curr=curr->link;
        free(temp);
    }
    g->linklist[num]=NULL;
    for(int i=0;i<MAX_VERTEX;i++){
        if(g->linklist[i]==NULL)continue;
        List* delete = g->linklist[i]->link;
        List* before = g->linklist[i];
        while(delete!=NULL){
            if(!strcmp(delete->station,name)){
                before->link=delete->link;
                free(delete);
                break;
            }
            delete=delete->link;
            before=before->link;
        }
    }
    g->graphnum--;
    modify_linklist_stationlist(g,num);
    printf("\n삭제완료됐습니다.");
}
void modify_linklist_stationlist(Graph* g, int num){
    for(int i=num;i<g->graphnum;i++){
        g->linklist[i]=g->linklist[i+1];
        strcpy(g->stationlist[i],g->stationlist[i+1]);
    }
}
void Add_edge(Graph* g, char* a, char* b){
    int num_a=-1,num_b=-1;
    for(int i=0;i<g->graphnum;i++){
        if(!strcmp(a,g->stationlist[i]))num_a=i;
        else if (!strcmp(b,g->stationlist[i]))num_b=i;
        if (num_a!=-1 && num_b!=-1)break;
    }
    if(num_a==-1 || num_b==-1){
        printf("\n연결을 추가하려는 역이 올바르지 않습니다. 재시도하세요.");
        return;
    }
    List* temp_a = (List*)malloc(sizeof(List));
    List* temp_b = (List*)malloc(sizeof(List));
    strcpy(temp_a->station,a);
    strcpy(temp_b->station,b);

    temp_a->link=g->linklist[num_b]->link;
    g->linklist[num_b]->link=temp_a;
    temp_b->link=g->linklist[num_a]->link;
    g->linklist[num_a]->link=temp_b;
}
void Delete_edge(Graph* g, char* a, char* b){
    int num_a=-1,num_b=-1;
    for(int i=0;i<g->graphnum;i++){
        if(!strcmp(a,g->stationlist[i]))num_a=i;
        else if (!strcmp(b,g->stationlist[i]))num_b=i;
        if (num_a!=-1 && num_b!=-1)break;
    }
    if(num_a==-1 || num_b==-1){
        printf("\n연결을 삭제하려는 역이 올바르지 않습니다. 재시도하세요.");
        return;
    }
    List* delete_a = g->linklist[num_a]->link;
    List* before_a = g->linklist[num_a];
    List* delete_b = g->linklist[num_b]->link;
    List* before_b = g->linklist[num_b];
    while(delete_a!=NULL){
        if(!strcmp(delete_a->station,b)){
            before_a->link=delete_a->link;
            free(delete_a);
            break;
        }
        delete_a=delete_a->link;
        before_a=before_a->link;
    }
    while(delete_b!=NULL){
        if(!strcmp(delete_b->station,a)){
            before_b->link=delete_b->link;
            free(delete_b);
            break;
        }
        delete_b=delete_b->link;
        before_b=before_b->link;
    }
    printf("\n삭제완료됐습니다.");
}
void print_all(Graph* g){
    for(int i=0;i<g->graphnum;i++){
        printf("%s와 연결된 역들 : ",g->stationlist[i]);
        List* curr = g->linklist[i]->link;
        while(curr!=NULL){
            printf("%s ",curr->station);
            curr=curr->link;
        }
        printf("\n");
    }
}
int Count_vertex(Graph* g){
    return g->graphnum;
}
int Count_edge(Graph* g){
    int cnt=0;
    for(int i=0;i<g->graphnum;i++){
        List* curr = g->linklist[i]->link;
        while(curr!=NULL){
            cnt++;
            curr=curr->link;
        }
    }
    return cnt/2;
}
void DFS(Graph* g, int start, int dest, int pathlen){
    if(visited[start]==0){
        pathidx=pathlen-1;
        visited[start]=1;
        pathlist[pathidx]=start;
        List* curr = g->linklist[start]->link;
        while(curr!=NULL){
            int num;
            for(int i=0;i<g->graphnum;i++){
                if(!strcmp(curr->station,g->stationlist[i]))num=i;
            }
            if (dest == num){
                if(min_path==-1){
                    min_path=pathlen;
                    for(int j=0;j<pathlen;j++){
                        min_pathlist[j]=pathlist[j];
                    }
                }
                else{
                    if(min_path > pathlen){
                        min_path=pathlen;
                        for(int j=0;j<pathlen;j++){
                            min_pathlist[j]=pathlist[j];
                        }
                    }
                }
                break;
            }
            else if(visited[num]==0){
                DFS(g,num,dest,pathlen+1);
            }
            curr=curr->link;
        }
        visited[start]=0;
    }
}
void DFS_2(Graph* g, int start, int dest){
    if(visited[start]==0 && connectFlag==0){
        visited[start]=1;
        List* curr=g->linklist[start]->link;
        while(curr!=NULL){
            int num;
            for(int i=0;i<g->graphnum;i++){
                if(!strcmp(curr->station,g->stationlist[i]))num=i;
            }
            if(dest == num){
                connectFlag=1;
                break;
            }
            else if(visited[num]==0){
                DFS_2(g,num,dest);
            }
            curr=curr->link;
        }
        visited[start]=0;
    }
}
void Shortest_distance(Graph* g, char* a, char* b){
    min_path=-1;
    int num_a=-1,num_b=-1;
    for(int i=0;i<g->graphnum;i++){
        if(!strcmp(a,g->stationlist[i]))num_a=i;
        else if (!strcmp(b,g->stationlist[i]))num_b=i;
        if (num_a!=-1 && num_b!=-1)break;
    }
    if(num_a==-1 || num_b==-1){
        printf("\n최단경로를 확인하려는 역이 올바르지 않습니다. 재시도하세요.");
        return;
    }
    DFS(g,num_a,num_b,0);
    printf("%s -> ",g->stationlist[num_a]);
    for(int i=0;i<min_path;i++){
        printf("%s -> ",g->stationlist[min_pathlist[i]]);
    }
    printf("%s\n",g->stationlist[num_b]);
}
void Shortest_distance_through(Graph* g, char* a, char* b, char* c){
    min_path=-1;
    int num_a=-1,num_b=-1,num_c=-1;
    for(int i=0;i<g->graphnum;i++){
        if(!strcmp(a,g->stationlist[i]))num_a=i;
        else if (!strcmp(b,g->stationlist[i]))num_b=i;
        else if (!strcmp(c,g->stationlist[i]))num_c=i;
        if (num_a!=-1 && num_b!=-1 && num_c!=-1)break;
    }
    if(num_a==-1 || num_b==-1 || num_c==-1){
        printf("\n최단경로를 확인하려는 역이 올바르지 않습니다. 재시도하세요.");
        return;
    }
    DFS(g,num_a,num_b,0);
    printf("%s -> ",g->stationlist[num_a]);
    for(int i=0;i<min_path;i++){
        printf("%s -> ",g->stationlist[min_pathlist[i]]);
    }
    printf("%s -> ",g->stationlist[num_b]);
    min_path=-1;
    DFS(g,num_b,num_c,0);
    for(int i=0;i<min_path;i++){
        printf("%s -> ",g->stationlist[min_pathlist[i]]);
    }
    printf("%s\n",g->stationlist[num_c]);
}
int isitconnected(Graph* g, char* a, char* b){
    int num_a=-1,num_b=-1;
    connectFlag=0;
    for(int i=0;i<g->graphnum;i++){
        if(!strcmp(a,g->stationlist[i]))num_a=i;
        else if (!strcmp(b,g->stationlist[i]))num_b=i;
        if (num_a!=-1 && num_b!=-1)break;
    }
    if(num_a==-1 || num_b==-1){
        printf("\n연결을 확인하려는 역이 올바르지 않습니다. 재시도하세요.");
        return 3;
    }
    DFS_2(g,num_a,num_b);
    if(connectFlag)return TRUE;
    else return FALSE;
}
void connected_vertex(Graph* g ,char* name){
    int num;
    for(int i=0;i<g->graphnum;i++){
        if(!strcmp(name,g->stationlist[i])){
            num=i;
            break;
        }
    }
    List* curr=g->linklist[num]->link;
    if(curr==NULL){
        printf("\n해당 역과 연결된 역이 없습니다.");
        return;
    }
    else printf("\n연결된 역들: ");
    while(curr!=NULL){
        printf("%s ",curr->station);
        curr=curr->link;
    }
}