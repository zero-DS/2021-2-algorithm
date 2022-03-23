#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char name[15];
    int student_ID;
    int idx;
    struct node* p_next;
}Node;
typedef struct queue{
    Node* front;
    Node* rear;
    int size;
    int Limit_top;
}Queue;
void print_interface();
Queue* Open_class();
int is_full(Queue*);
int is_empty(Queue*);
void Register_class(Queue*, int, char*);
void Drop_class(Queue*, int);
int Check_register(Queue*, int);
int Check_register02(Queue*, int);
void Class_register_list01(Queue*);//대기자까지 전부확인
void Class_register_list02(Queue*);//대기자 제외하고 전부확인
void modify_index(Queue*);
int main(void){
    int cmd;
    int flag=1;
    int tempID;
    int tempTO;
    char tempName[15]={0};
    Queue* algorithm = Open_class();
    while(flag){
        print_interface();
        scanf("%d",&cmd);
        switch (cmd)
        {
        case 1:{
            printf("\n수강신청을 진행합니다.");
            printf("\n학번을 입력해주세요 : ");
            scanf("%d",&tempID);
            printf("\n이름을 입력해주세요 : ");
            scanf("%s",tempName);
            Register_class(algorithm,tempID,tempName);
        }break;
        case 2:{
            printf("\n수강철회를 진행합니다.");
            printf("\n학번을 입력해주세요 : ");
            scanf("%d",&tempID);
            Drop_class(algorithm,tempID);
        }break;
        case 3:{
            printf("\n티오 수정을 진행합니다.");
            printf("\n재설정할 티오를 입력해주세요 :");
            scanf("%d",&tempTO);
            algorithm->Limit_top=tempTO;
        }break;
        case 4:{
            printf("\n수강신청 여부를 확인합니다.");
            printf("\n확인할 학번을 입력해주세요 :");
            scanf("%d",&tempID);
            if(Check_register(algorithm,tempID)==0){
                printf("신청되지 않았습니다.\n");
            }
        }break;
        case 5: Class_register_list01(algorithm);
            break;
        case 6: Class_register_list02(algorithm);
            break;
        case 7: 
            printf("프로그램을 종료합니다.\n");
            flag=0;
            break;
        default: printf("올바르지 못한 입력입니다.\n");
            break;
        }
    }
    return 0;
}
void print_interface(){
    printf("====== 알고리즘 수강 신청 ======\n");
    printf("= 1. 수강 신청                 =\n");
    printf("= 2. 수강 철회                 =\n");
    printf("= 3. 티오 수정                 =\n");
    printf("= 4. 수강 신청 여부 확인       =\n");
    printf("= 5. 수강 신청 인원 전체 확인  =\n");
    printf("= 6. 최종 명단 확인            =\n");
    printf("= 7. 프로그램 종료             =\n");
    printf("================================\n");
    printf("원하시는 기능의 번호를 입력해주세요 : ");
}
Queue* Open_class(){
    int num;
    Queue* class_list = (Queue*)malloc(sizeof(Queue));
    class_list->front=NULL;
    class_list->rear=NULL;
    class_list->size=0;
    printf("알고리즘 수업을 개설합니다.\n");
    printf("수강 가능 인원을 설정해주세요 : ");
    scanf("%d",&num);
    class_list->Limit_top=num;
    return class_list;
}
int is_full(Queue* q){
    if(q->size==q->Limit_top)return 1;
    else return 0;
}
int is_empty(Queue* q){
    if(q->size==0)return 1;
    else return 0;
}
void Register_class(Queue* q,int ID, char* name){
    if(is_full(q)==1){
        printf("수강 가능 인원이 가득찼습니다. 대기 인원으로 등록합니다.\n");
    }
    q->size++;
    Node* new = (Node*)malloc(sizeof(Node));
    new->idx=q->size;
    strcpy(new->name,name);
    new->p_next=NULL;
    new->student_ID=ID;
    if(q->size==1){
        q->front=new;
        q->rear=new;
    }
    else{
        q->rear->p_next=new;
        q->rear=new;
    }

}
void Drop_class(Queue* q, int ID){
    if(is_empty(q)==1){
        printf("이미 수강인원이 아무도 없습니다.\n");
        return;
    }
    if(Check_register02(q,ID)==0){
        printf("삭제하시려는 학번의 학생은 수강신청 돼있지 않습니다.\n");
        return;
    }
    q->size--;
    if(q->size==0){
        q->front=NULL;
        q->rear=NULL;
    }
    else{
        int cnt=0;
        int deleteidx;
        Node* curr=q->front;
        Node* bfor=q->front;
        while(cnt<=q->size+1){
            if(curr->student_ID==ID){
                if(cnt==0)q->front=curr->p_next;
                else{
                    deleteidx=cnt-1;
                    while(deleteidx--){
                        bfor=bfor->p_next;
                    }
                    bfor->p_next=curr->p_next;
                }
                free(curr);
                break;
            }
            cnt++;
            curr=curr->p_next;
        }
    }
    modify_index(q);//수강철회로 인한 학생들의 신청 목록 순서를 재조정
    printf("%d 학생 철회 완료 됐습니다.\n",ID);
}
int Check_register(Queue* q, int ID){
    Node* curr = q->front;
    while(curr!=NULL){
        if(ID==curr->student_ID){
            if(curr->idx<=q->Limit_top)printf("수강확정된 학생입니다.\n");
            else printf("대기 순번 %d번째입니다.\n",abs((curr->idx)-(q->Limit_top)));
            return 1;
        }
        curr=curr->p_next;
    }
    return 0;
}
int Check_register02(Queue* q, int ID){
    Node* curr = q->front;
    while(curr!=NULL){
        if(ID==curr->student_ID){
            return 1;
        }
        curr=curr->p_next;
    }
    return 0;
}
void Class_register_list01(Queue* q){
    if(is_empty(q)){
        printf("수강 신청한 인원이 없습니다.\n");
        return;
    }
    int cnt=0;
    Node* curr = q->front;
    printf("수강 신청한 명단 : \n");
    while(curr!=NULL){
        if(cnt==q->Limit_top)printf("아래로는 수강 대기 명단입니다.\n");
        printf("%d : %d %s\n",curr->idx,curr->student_ID,curr->name);
        curr=curr->p_next;
        cnt++;
    }
}
void Class_register_list02(Queue* q){
    if(is_empty(q)){
        printf("수강 신청한 인원이 없습니다.\n");
        return;
    }
    Node* curr = q->front;
    int cnt=0;
    printf("수강 신청한 명단 : \n");
    while(cnt++!=q->Limit_top){
        printf("%d : %d %s\n",curr->idx,curr->student_ID,curr->name);
        curr=curr->p_next;
    }
}
void modify_index(Queue* q){
    int cnt=1;
    Node* curr = q->front;
    while(curr!=NULL){
        curr->idx=cnt;
        cnt++;
        curr=curr->p_next;
    }
}