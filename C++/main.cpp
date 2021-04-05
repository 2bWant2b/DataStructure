#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void createList(SqList *&L,ElemType a[],int n){
    L=(SqList * )malloc(sizeof (SqList));
    for (int i=0;i<n;i++){
        L->data[i]=a[i];
    }
    L->length=n;
}

void initList(SqList *&L){
    L=(SqList*)malloc(sizeof(SqList));
    L->length=0;
}

void destroyList(SqList *&L){
    free(L);
}

bool isEmpty(SqList *L){
    return (L->length==0);
}

int  getListLength(SqList *L){
    return (L->length);
}

void dispList(SqList *L){
    for (int i=0;i<L->length;i++){
        printf("%c",L->data[i]);
    }
    printf("\n");
}

bool getElem(SqList *L,int i,ElemType &e){
    if (i<1 || i>L->length){
        return false;
    }
    e=L->data[i-1];
    return true;
}

int getLocateElem(SqList *L,ElemType e){
    int i=0;
    while (i<L->length&&L->data[i]!=e){
        i++;
    }
    if (i>=L->length){
        return 0;
    } else{
        return i+1;
    }
}

bool insertElem(SqList *L,int i,ElemType e){
    int j;
    if(i<1 || i>L->length+1){
        return false;
    }
    i--;
    for (j=L->length;j>i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
    return true;
}

bool deleteElem(SqList *&L,int i,ElemType &e){
    int j;
    if (i<1 || i>L->length){
        return false;
    }
    i--;
    e=L->data[i];
    for (j=i; j < L->length-1; j++) {
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}

int main() {
    SqList *L;
    ElemType e;
    initList(L);
    printf("%s\n",(isEmpty(L)?"yes":"no"));
    insertElem(L,1,'a');
    insertElem(L,2,'b');
    insertElem(L,3,'c');
    insertElem(L,4,'d');
    insertElem(L,5,'e');
    dispList(L);
    printf("%d\n",getListLength(L));
    getElem(L,3,e);
    printf("%c\n",e);
    printf("%d\n",getLocateElem(L,'a'));
    insertElem(L,4,'f');
    dispList(L);
    deleteElem(L,3,e);
    dispList(L);
    printf("%s\n",(isEmpty(L)?"yes":"no"));
    destroyList(L);
    printf("%d\n",getListLength(L));
    printf("%s\n",(isEmpty(L)?"yes":"no"));
}
