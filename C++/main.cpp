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

int peek(LinkStNode *s) {
	if (s->next == NULL)
		return false;
	return s->next->data;
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
}




















