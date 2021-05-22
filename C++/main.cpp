#include <cstdio>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct linknode
{
    ElemType data;
    struct linknode *next;
} LinkStNode;

void initStack(LinkStNode *&s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

void destoryStack(LinkStNode *&s) {
    LinkStNode *p=s->next;
    while (p!=NULL)
    {
        free(s);
        s=p;
        p=p->next;
    }
	free(s);
}

bool isEmpty(LinkStNode *s){
	return(s->next == NULL);
}

bool push(LinkStNode*&s, ElemType e) {
    LinkStNode *p;
	p=(LinkStNode*)malloc(sizeof(LinkStNode));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return true;
}

bool pop(LinkStNode *&s, ElemType &e) {
    LinkStNode *p;
	if (s->next == NULL)
		return false;
	p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
	return true;
}

bool popeasy(LinkStNode *&s){
    LinkStNode *p;
	if (s->next == NULL)
		return false;
	p=s->next;
    s->next=p->next;
    free(p);
	return true;
}

int peek(LinkStNode *s) {
	if (s->next == NULL)
		return false;
	return s->next->data;
}

void pushSort(LinkStNode *&s,ElemType e){
    LinkStNode *tempStack;
    initStack(tempStack);
    if(isEmpty(s)){
        push(s,e);
    }else{
        while (!isEmpty(s)&&e>peek(s))
        {
            push(tempStack,peek(s));
            popeasy(s);
        }
        push(s,e);
        while (!isEmpty(tempStack))
        {
            push(s,peek(tempStack));
            popeasy(tempStack);
        }
    }
}

int main() {
    ElemType e;
    LinkStNode *s;
    initStack(s);
    printf("Stack is %s\n",(isEmpty(s)?"empty":"not empty"));
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    printf("Stack is %s\n",(isEmpty(s)?"empty":"not empty"));
    printf("Stack top is %d\n",peek(s));
    while (!isEmpty(s))
    {
        pop(s,e);
        printf("%d",e);
    }
    printf("\n");
    printf("Stack is %s\n",(isEmpty(s)?"empty":"not empty"));
    destoryStack(s);
    printf("-----------------栈排序--------------------\n");
    LinkStNode *sortStack;
    ElemType e2;
    initStack(sortStack);
    pushSort(sortStack,1);
    pushSort(sortStack,3);
    pushSort(sortStack,4);
    pushSort(sortStack,2);
    while (!isEmpty(sortStack))
    {
       pop(sortStack,e2);
       printf("%d\n",e2);
    }
}




















