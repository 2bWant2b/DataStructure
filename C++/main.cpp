#include <cstdio>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int top;
} SqStack;

void initStack(SqStack*&s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

void destoryStack(SqStack*&s) {
	free(s);
}

bool isEmpty(SqStack*s){
	return(s->top == -1);
}

bool push(SqStack*&s, ElemType e) {
	if (s->top==MaxSize-1)
        return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool pop(SqStack*&s, ElemType&e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

int peek(SqStack*s) {
	if (s->top == -1)
		return false;
	return s->data[s->top];
}

int main() {
    ElemType e;
    SqStack *s;
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




















