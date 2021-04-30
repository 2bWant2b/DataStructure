#include <cstdio>
#include <malloc.h>
#define MaxSize 6
typedef char ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

void initQueue(SqQueue *&q){
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

void destroyQueue(SqQueue *&q){
    free(q);
}

bool isEmpty(SqQueue *q){
    return(q->front==q->rear);
}

bool enQueue(SqQueue*&q,ElemType e){
    if((q->rear+1)%MaxSize==q->front) return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *&q,ElemType &e){
    if(q->front==q->rear) return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}

int main(){
    ElemType e;
    SqQueue *q;
    initQueue(q);
    if(!enQueue(q,'a')) printf("\t the queue is full\n"); else printf("enQueue a\n");
    if(!enQueue(q,'b')) printf("\t the queue is full\n"); else printf("enQueue b\n");
    if(!enQueue(q,'c')) printf("\t the queue is full\n"); else printf("enQueue c\n");
    if(!enQueue(q,'d')) printf("\t the queue is full\n"); else printf("enQueue d\n");
    if(!enQueue(q,'e')) printf("\t the queue is full\n"); else printf("enQueue e\n");
    printf("the queue is %s\n",(isEmpty(q)?"empty":"not empty"));
    while (!isEmpty(q))
    {
        deQueue(q,e);
        printf("%c",e);
    }
    destroyQueue(q);
}

















