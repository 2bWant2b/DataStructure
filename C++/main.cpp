#include <cstdio>
#include <malloc.h>
#define MaxSize 1000
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
    if((q->rear+1)%MaxSize==q->front){
        return false;
    }
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *&q,ElemType &e){
    if(q->front==q->rear){
        return false;
    }
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}

SqQueue* enQueueSort(SqQueue *&q){
    if(q->rear==q->front+1){
        return q;
    }
    ElemType e;
    ElemType a;
    deQueue(q,e);
    enQueueSort(q);
    while (e>q->data[q->front+1])
    {
        deQueue(q,a);
        enQueue(q,a);
    }
    enQueue(q,e);
    return q;
}

int main(){
    ElemType e;
    SqQueue *q;
    initQueue(q);
    enQueue(q,'c'); printf("enQueue c\n");
    enQueue(q,'f'); printf("enQueue f\n");
    enQueue(q,'b'); printf("enQueue b\n");
    enQueue(q,'f'); printf("enQueue f\n");
    enQueue(q,'f'); printf("enQueue f\n");
    enQueue(q,'e'); printf("enQueue e\n");
    enQueue(q,'a'); printf("enQueue a\n");
    enQueue(q,'b'); printf("enQueue b\n");
    enQueue(q,'d'); printf("enQueue d\n");
    printf("the queue is %s\n",(isEmpty(q)?"empty":"not empty"));
    q=enQueueSort(q);
    while (!isEmpty(q))
    {
        deQueue(q,e);
        printf("deQueue %c\n",e);
    }
    destroyQueue(q);
}

















