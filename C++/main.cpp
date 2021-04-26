#include <cstdio>
#include <malloc.h>
typedef char ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;

// 头插法创建循环双链表
void creatListF(DLinkNode *&L,ElemType a[],int n){
    DLinkNode *s;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    L->next=NULL;
    for(int i=0;i<n;i++){
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        s->next=L->next;
        if(L->next!=NULL){
            L->next->prior=s;
        }
        L->next=s;
        s->prior=L;
    }
    s = L->next;
    while (s->next!=NULL)
    {
        s = s->next;
    }
    s->next=L;
    L->prior=s;
}

// 尾插法创建循环双链表
void creatListR(DLinkNode *&L,ElemType a[],int n){
    DLinkNode *s,*r;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    L->next=NULL;
    r=L;
    for (int i = 0; i < n; i++)
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=L;
    L->prior=r;
}

void dispList(DLinkNode *L){
    DLinkNode *p=L->next;
    while (p!=L)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

void dispListRev(DLinkNode *L){
    DLinkNode *p = L->prior;
	while (p != L)
	{
		printf("%c", p->data);
		p = p->prior;
	}
	printf("\n");
}

int main() {
    DLinkNode *FList,*RList;
    FList=(DLinkNode*)malloc(sizeof(DLinkNode));
    RList=(DLinkNode*)malloc(sizeof(DLinkNode));
    FList->prior=FList->next=FList;
    RList->prior=RList->next=RList;
    ElemType a[]={'1','2','3','4','5','6','7','8'};
    creatListF(FList,a,8);
    creatListR(RList,a,8);
    printf("正序输出\n");
    dispList(FList);
    dispList(RList);
    printf("倒序输出\n");
    dispListRev(FList);
    dispListRev(RList);
}




















