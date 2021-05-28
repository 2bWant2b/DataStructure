#include <cstdio>
#include <malloc.h>
#define MaxSize 11
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

int length(SqQueue *q){
    return (q->rear-q->front+MaxSize)%MaxSize;
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

int deQueueeasy(SqQueue *&q){
    if(q->front==q->rear){
        return NULL;
    }
    q->front=(q->front+1)%MaxSize;
    return q->data[q->front];
}

// TODO 递归不能实现因为不能保存返回值
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

void queueSort(SqQueue *&q){
    int count = 0;
    for (int i = 0; i < length(q); i++)
    {
        if (count == 0){
            enQueue(q,deQueueeasy(q));
            count++;
            continue;
        }
        // TODO 队首元素怎么取？
        // 保存队首
        char target = q->data[(q->front+1)%MaxSize];
        // 把count区搬到队首等待
        for (int j = 0 ; j < length(q) - count ; j++){
            enQueue(q,deQueueeasy(q));
        }
        //对count区和target的操作
        int flag = 0;
        for (int k = 0 ; k < count + 1; k++){
            if (q->data[(q->front+1)%MaxSize]<target || flag == 1){
                enQueue(q,deQueueeasy(q));
            }else{
                enQueue(q,target);
                flag = 1;
            }
        }
        deQueueeasy(q);
    }
}

int main(){
    ElemType e;
    SqQueue *q;
    initQueue(q);
    enQueue(q,'c'); printf("enQueue a\n");
    enQueue(q,'f'); printf("enQueue b\n");
    enQueue(q,'b'); printf("enQueue c\n");
    enQueue(q,'f'); printf("enQueue d\n");
    enQueue(q,'f'); printf("enQueue e\n");
    printf("the queue is %s\n",(isEmpty(q)?"empty":"not empty"));
    // q=enQueueSort(q);
    while (!isEmpty(q))
    {
        deQueue(q,e);
        printf("deQueue %c\n",e);
    }
    destroyQueue(q);
    printf("-----------------队列排序------------------\n");
    SqQueue *queue;
    initQueue(queue);
    enQueue(queue,'c');
    enQueue(queue,'f');
    enQueue(queue,'b');
    enQueue(queue,'f');
    enQueue(queue,'f');
    enQueue(queue,'e');
    enQueue(queue,'a');
    enQueue(queue,'b');
    enQueue(queue,'d');
    queueSort(queue);
    while (!isEmpty(queue))
    {
        deQueue(queue,e);
        printf("deQueue %c\n",e);
    }
}

















