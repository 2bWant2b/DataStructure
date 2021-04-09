#include <cstdio>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkNode;

void creatListF(LinkNode *&L,ElemType a[],int n){
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    for(int i=0;i<n;i++){
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

void creatListR(LinkNode *&L,ElemType a[],int n){
    LinkNode *s,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    r=L;
    for (int i = 0; i < n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

void initList(LinkNode *&L){
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}

void destroyList(LinkNode *&L){
    LinkNode *pre=L,*cur=pre->next;
    while (cur!=NULL)
    {
        free(pre);
        pre=cur;
        cur=pre->next;
    }
    free(pre);
}

bool isEmpty(LinkNode *L){
    return(L->next==NULL);    
}

int getListLength(LinkNode *L){
    int i=0;
    LinkNode *p=L;
    while (p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return(i);
}

void dispList(LinkNode *L){
    LinkNode *p=L->next;
    while (p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

void dispList2(LinkNode *L){
    LinkNode *p=L;
    while (p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

bool getElemValue(LinkNode *L,int i,ElemType &e){
    int j=0;
    LinkNode *p=L;
    if (i<0)return false;
    while (j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    }else{
        e=p->data;
        return true;
    }
}

int getElemNumber(LinkNode *L,ElemType e){
    int i=1;
    LinkNode *p=L->next;
    while (p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL){
        return 0;
    }else{
        return(i);
    }
}

bool insertElem(LinkNode *&L,int i,ElemType e){
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)return false;
    while (j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    }else{
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

bool deleteElem(LinkNode *&L,int i,ElemType &e){
    int j=0;
    LinkNode *p=L,*q;
    if(i<=0)return false;
    while (j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    }else{
        q=p->next;
        if(q==NULL){
            return false;
        }else{
            e=q->data;
            p->next=q->next;
            free(q);
            return true;
        }
    }
    
}

LinkNode* devideList(LinkNode *&L){
    LinkNode *linkptr,*moveptr,*evenhead;
    linkptr=L->next;
    moveptr=L->next->next;
    evenhead=moveptr;
    while (moveptr!=NULL)
    {
        linkptr->next=linkptr->next->next;
        linkptr=moveptr;
        moveptr=moveptr->next;
    }
    return evenhead;
}

int main() {
    LinkNode *list;
    ElemType e;
    initList(list);
    insertElem(list,1,'a');
    insertElem(list,2,'b');
    insertElem(list,3,'c');
    insertElem(list,4,'d');
    insertElem(list,5,'e');
    dispList(list);
    printf("the length of list : %d\n",getListLength(list));
    printf("list %s\n",(isEmpty(list)?"is empty":"is not empty"));
    getElemValue(list,3,e);
    printf("the third elem in list is : %c\n",e);
    printf("a locates :%d\n",getElemNumber(list,'a'));
    insertElem(list,4,'f');
    dispList(list);
    destroyList(list);
    printf("-------------附加题1--------------\n"); 
    LinkNode *Flist;
    char a[5]={'q','w','e','r','t'};
    LinkNode *Rlist;
    creatListF(Flist,a,5);
    dispList(Flist);
    creatListR(Rlist,a,5);
    dispList(Rlist);
    printf("-------------附加题2--------------\n");
    dispList2(devideList(Rlist));
    dispList(Rlist);
}




















