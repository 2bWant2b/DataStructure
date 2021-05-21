#include <cstdio>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *lchild;
    struct node *rchild;
}BTNode;


void createBTree(BTNode *&b,char *str){
    BTNode *St[MaxSize],*p;
    int top=-1,k,j=0;char ch;
    b=NULL;
    ch=str[j];
    while (ch!='\0')
    {
        switch (ch)
        {
        case '(':
            top++;St[top]=p;k=1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k=2;
            break;
        default:
            p=(BTNode*)malloc(sizeof(BTNode));
            p->data=ch;
            p->lchild=p->rchild=NULL;
            if(b==NULL){
                b=p;
            }else{
                switch (k)
                {
                case 1:
                    St[top]->lchild=p;
                    break;
                case 2:
                    St[top]->rchild=p;
                default:
                    break;
                }
            }
            break;
        }
        j++;
        ch=str[j];
    }
}

void destroyBTree(BTNode *&b){
    if(b!=NULL){
        destroyBTree(b->lchild);
        destroyBTree(b->rchild);
        free(b);
    }
}

BTNode* findNode(BTNode *b,ElemType x){
    BTNode *p;
    if(b==NULL){
        return NULL;
    }else if (b->data==x)
    {
        return b;
    }else{
        p=findNode(b->lchild,x);
        if(p!=NULL) return p;
        else return findNode(b->rchild,x);
    }
    
}

BTNode* lchildNode(BTNode *p){
    return p->lchild;
}

BTNode* rchildNode(BTNode *p){
    return p->rchild;
}

int getHeight(BTNode *b){
    int lchild_h,rchild_h;
    if(b==NULL) return 0;
    else{
        lchild_h=getHeight(b->lchild);
        rchild_h=getHeight(b->rchild);
        return (lchild_h>rchild_h)?(lchild_h+1):(rchild_h+1);
    }
}

void dispBTree(BTNode *b){
    if(b!=NULL){
        printf("%c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL){
            printf("(");
            dispBTree(b->lchild);
            if(b->rchild!=NULL) printf(",");
            dispBTree(b->rchild);
            printf(")");
        }
    }else{
        printf("Tree is NULL");
    }
}

void preOrder(BTNode *b) {
    if(b!=NULL){
        printf("%c",b->data);
        preOrder(b->lchild);
        preOrder(b->rchild);
    }
}

void inOrder(BTNode *b) {
    if(b!=NULL){
        inOrder(b->lchild);
        printf("%c",b->data);
        inOrder(b->rchild);
    }
}

void postOrder(BTNode *b){
    if(b!=NULL){
        postOrder(b->lchild);
        postOrder(b->rchild);
        printf("%c",b->data);
    }
}

void travLevel(BTNode *b) {
    BTNode *Qu[MaxSize];
    int front,rear;
    front=rear=0;
    if(b!=NULL) printf("%c",b->data);
    rear++;
    Qu[rear]=b;
    while(rear!=front){
        front=(front+1)%MaxSize;
        b=Qu[front];
        if (b->lchild!=NULL){
            printf("%c",b->lchild->data);
            rear=(rear+1)%MaxSize;
            Qu[rear]=b->lchild;
        }
        if (b->rchild!=NULL){
            printf("%c",b->rchild->data);
            rear=(rear+1)%MaxSize;
            Qu[rear]=b->rchild;
        }
    }
    printf("\n");
}

void dfs(BTNode *&b, char x){
    if (b == NULL) return;
    if (b->data == x){
        b->lchild = NULL;
        b->rchild = NULL;
        b->data = 'a';
    }
    dfs(b->lchild,x);
    dfs(b->rchild,x);
}

BTNode* remove(BTNode *&b, char x){
    if (!b) return NULL;
    b->lchild=remove(b->lchild,x);
    b->rchild=remove(b->rchild,x);
    if (!b->lchild && !b->rchild && b->data == x) return NULL;
    return b;
}

// TODO 附加题还没看，树的实现结构还没弄懂
int main(){
    BTNode *b,*p,*lp,*rp;
    char str[255]="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    createBTree(b,str);
    dispBTree(b);
    printf("\n");
    p=findNode(b,'H');
    if(p!=NULL){
        lp=lchildNode(p);
        if(lp!=NULL) printf("左孩子为%c",lp->data);
        else printf("无左孩子");
        rp=rchildNode(p);
        if(rp!=NULL) printf("右孩子为%c",rp->data);
        else printf("无右孩子");
    }
    printf("\n");
    printf("%d\n",getHeight(b));

    printf("---------------第八次实验-----------------\n");
    printf("前序遍历：\n");
    preOrder(b);
    printf("\n");
    printf("中序遍历：\n");
    inOrder(b);
    printf("\n");
    printf("后序遍历：\n");
    postOrder(b);
    printf("\n");
    printf("层次遍历：\n");
    travLevel(b);
    printf("删除子树：\n");
    dfs(b,'A');
    dispBTree(remove(b,'a'));
}
