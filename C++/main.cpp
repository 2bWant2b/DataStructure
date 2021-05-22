#include <cstdio>
#include <malloc.h>
#include <string.h>
#define MaxSize 1000
typedef int ElemType;
typedef char ElemType2;
typedef struct 
{
    ElemType data[MaxSize];
    int top;
} SqStack;
typedef struct 
{
    ElemType2 data[MaxSize];
    int top;
} SqStack2;


void initStack(SqStack*&s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

void initStack2(SqStack2 *&s) {
	s = (SqStack2 *)malloc(sizeof(SqStack2));
	s->top = -1;
}

void destoryStack(SqStack*&s) {
	free(s);
}

bool isEmpty(SqStack*s){
	return(s->top == -1);
}

bool isEmpty2(SqStack2 *s){
    return(s->top == -1);
}

bool push(SqStack*&s, ElemType e) {
	if (s->top==MaxSize-1)
        return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool push2(SqStack2 *&s, ElemType2 e) {
	if (s->top==MaxSize-1)
        return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool pop(SqStack*&s, ElemType &e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool popeasy(SqStack *&s){
    if (s->top == -1)
            return false;
    s->top--;
    return true;
}

bool pop2(SqStack2 *&s, ElemType2 &e){
    if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

char popElem(SqStack2 *&s){
    if (s->top == -1)
		return false;
	return s->data[s->top];
	s->top--;
}

int peek(SqStack *s) {
	if (s->top == -1)
		return false;
	return s->data[s->top];
}

char peek2(SqStack2 *s){
    if (s->top == -1)
		return false;
	return s->data[s->top];
}

bool judgeBrackets(char str[]){
    char *p=str;
    SqStack2 *s;
    ElemType2 e;
    s = (SqStack2 *)malloc(sizeof(SqStack2));
	s->top = -1;
    for(int i=0;i<strlen(str);i++){
        if(p[i]!=')'&&p[i]!=']'&&p[i]!='}'&&p[i]!='('&&p[i]!='['&&p[i]!='{'){
            continue;
        }
        else if(p[i]=='('){
            push2(s,')');
        }
        else if(p[i]=='['){
            push2(s,']');
        }
        else if(p[i]=='{'){
            push2(s,'}');
        }
        else if(p[i]==peek2(s)){
            pop2(s,e);
        }
        else if(isEmpty2(s)||p[i]!=peek2(s)){
            return false;
        }
    }
    if(isEmpty2(s)){
        return true;
    }
    return false;
}

// TODO 栈实现队列有点问题，只能连续出队不能进队后再出队，否则会打印一个0
void enQueue(SqStack *&S1,SqStack *&S2,ElemType e){
    push(S1,e);
}

void deQueue(SqStack *&S1,SqStack *&S2,ElemType &e){
    if(isEmpty(S2)){
        if(isEmpty(S1)){
            return;
        }
        while (!isEmpty(S1))
        {
            popeasy(S1);
            push(S2,peek(S1));
        }
    }
    popeasy(S2);
    e=peek(S2);
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
    printf("---------------判断括号合法性-----------------\n");
    char str1[]="a*{b*[1/(2-c)+1/(1+d)]-3}";
    char str2[]="a*{b*1/(2-c)+1/(1+d)]-3";
    printf("%s\n",(judgeBrackets(str1)?"valid brackets":"invalid brackets"));
    printf("%s\n",(judgeBrackets(str2)?"valid brackets":"invalid brackets"));
    printf("---------------栈实现队列-----------------\n");
    ElemType e2;
    SqStack *S1,*S2;
    S1 = (SqStack*)malloc(sizeof(SqStack));
    S2 = (SqStack*)malloc(sizeof(SqStack));
    initStack(S1);
    initStack(S2);
    enQueue(S1,S2,1);
    enQueue(S1,S2,2);
    enQueue(S1,S2,3);
    enQueue(S1,S2,4);
    deQueue(S1,S2,e2);
    printf("%d\n",e2);
    deQueue(S1,S2,e2);
    printf("%d\n",e2);
    deQueue(S1,S2,e2);
    printf("%d\n",e2);
    deQueue(S1,S2,e2);
    printf("%d\n",e2);
}