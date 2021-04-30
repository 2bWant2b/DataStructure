#include <cstdio>
#include <malloc.h>
typedef char ElemType;
typedef struct DataNode
{
    ElemType data;
    struct DataNode *next;
}DataNode;
typedef struct 
{
    DataNode *front;
    DataNode *rear;
}LinkQuNode;

void initQueue(LinkQuNode *&q){
    q=(LinkQuNode*)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL;
}

void destroyQueue(LinkQuNode *&q){
    DataNode *p=q->front,*r;
    if(p!=NULL){
        r=p->next;
        while (r!=NULL)
        {
            free(p);
            p=r;
            r=p->next;
        }
    }
    free(p);
    free(q);
}

bool isEmpty(LinkQuNode *q){
    return(q->rear==NULL);
}

void enQueue(LinkQuNode*&q,ElemType e){
    DataNode *p;
    p=(DataNode*)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL){
        q->front=q->rear=p;
    }else{
        q->rear->next=p;
        q->rear=p;
    }
}

bool deQueue(LinkQuNode *&q,ElemType &e){
    DataNode *t;
    if(q->rear==NULL) return false;
    t=q->front;
    if(q->front==q->rear){
        q->front=q->rear=NULL;
    }else{
        q->front=q->front->next;
    }
    e=t->data;
    free(t);
    return true;
}

int main(){
    ElemType e;
    LinkQuNode *q;
    initQueue(q);
    enQueue(q,'a'); printf("enQueue a\n");
    enQueue(q,'b'); printf("enQueue b\n");
    enQueue(q,'c'); printf("enQueue c\n");
    enQueue(q,'d'); printf("enQueue d\n");
    enQueue(q,'e'); printf("enQueue e\n");
    enQueue(q,'f'); printf("enQueue f\n");
    printf("the queue is %s\n",(isEmpty(q)?"empty":"not empty"));
    while (!isEmpty(q))
    {
        deQueue(q,e);
        printf("deQueue %c\n",e);
    }
    destroyQueue(q);
}

















