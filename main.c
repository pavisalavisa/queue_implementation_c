#include <stdio.h>
#include <stdlib.h>

struct _element;
typedef struct _element* Position;

typedef struct _element{
    int br;
    Position next;

}_ELEMENT;

int push(Position, int);
int pop(Position);
Position findLast(Position);
int deleteByNumber(Position,int);
void userMenu();
Position createNode();
Position findPrevious(Position,int);

int main()
{
        userMenu();
    return 0;
}

Position createNode()
{
    Position p=NULL;
    p=(Position)malloc(sizeof(_ELEMENT));
    if(p==NULL)return p;
    p->next=NULL;
    p->br=0;
    return p;
}

int push(Position head, int x)
{
    if(head==NULL)return -1;
    Position q=createNode();
    q->br=x;
    q->next=head->next;
    head->next=q;


    return 0;
}


int pop(Position head)
{
    Position previous=findPrevious(head,findLast(head)->br);
    Position last=findLast(head);
    int br=findLast(head)->br;
    previous->next=NULL;
    free(last);
    return br;

}

Position findLast(Position head)
{
    Position tmp=head;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    return tmp;

}

Position findPrevious(Position head,int x)
{
    if(head==NULL)return NULL;
    Position i=head;

    while(i->next!=NULL&&i->next->br!=x)
        i=i->next;
    return i;
}

void userMenu()
{
    printf("Program koji simulira rad reda (eng. Queue)\n");
    printf("Unesite neke brojeve!");
    int i=0,br;
    Position head=createNode();
    for(i=0;i<5;i++)
    {
            scanf("%d",&br);
            push(head,br);

    }
    for(i=0;i<5;i++)
    {
            printf("*%d. broj koji je izasao je : %d\n",i+1,pop(head));

    }
    return ;
}
