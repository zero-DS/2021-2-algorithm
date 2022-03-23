#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    int position;
    struct person *next;
}person;

void Josephus(int total, int steps) {
    int i, cnt;
    person *p, *q, *r;

    p = (person*) malloc(sizeof(person));
    p->position = 1;
    p->next = p;
    q = p;

    for(i=2; i<=total; i++) {
        r = (person*) malloc(sizeof(person));   
        r->position = i;
        r->next = p;
        q->next = r;
        q = r;
    }

    while(p->next != p) {
        q = p;
        r = q;
        for(cnt = 1; cnt < steps; cnt++) {
            r = q;
            q = q->next;
        }
        
        printf("%d\t", r->next->position);
		

        r->next = q->next;
        p = r->next;
        q->next = NULL;
        free(q);
        q = NULL;

    }
    printf("%d\t", r->position);
    // return p->position;
}

int main() {

    int n, m, a, b;

    printf("\nEnter 0 or minus(-) value to quit");

    printf("\n\n=================Weekday=================\n");
    printf("\nEnter Total_Number and Constant_Factor : ");

    scanf("%d %d", &n, &m);
    
    if (n <= 0 || m <= 0)
        return 1;

    
    Josephus(n, m);

    printf("\n\n=================Weekend=================\n");
    printf("\nEnter Total_Number and Constant_Factor : ");

    scanf("%d %d", &a, &b);
    
    if (a <= 0 || b <= 0)
        return 1;

    Josephus(a, b);

    return 0;
}

