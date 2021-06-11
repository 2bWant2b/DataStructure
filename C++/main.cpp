#include <cstdio>
#include <malloc.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType;
typedef struct
{
    KeyType key;
    InfoType data;
}RecType;

void swap(RecType &x,RecType &y){
    RecType tmp = x;
    x = y;
    y = tmp;
}

void createList(RecType R[],KeyType keys[],int n){
    for(int i=0;i<n;i++){
        R[i].key=keys[i];
    }
}

void dispList(RecType R[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",R[i].key);
    }
    printf("\n");
}

// *插入排序
void insertSort(RecType R[],int n){
    int i,j;
    RecType tmp;
    for(i=1;i<n;i++){
        printf("i = %d,插入 %d,插入结果：",i,R[i].key);
        if(R[i].key<R[i-1].key){
            tmp=R[i];
            j=i-1;
            do{
                R[j+1]=R[j];
                j--;
            }while(j>=0&&R[j].key>tmp.key);
            R[j+1]=tmp;
        }
        dispList(R,n);
    }
}

//* 冒泡排序
void BubbleSort(RecType R[],int n){
    int i,j;
    bool exchange;
    for(i=0;i<n-1;i++){
        exchange = false;
        for(j=n-1;j>i;j--){
            if(R[j].key<R[j-1].key){
                swap(R[j],R[j-1]);
                exchange = true;
            }
        }
        printf("i=%d:归位元素%d,排序结果：",i,R[i].key);
            dispList(R,n);
            if(!exchange){
                return;
            }
    }
}

//* 快速排序显示一趟划分后结果
void disppart(RecType R[],int s,int t){
    static int i = 1;
    int j;
    printf("第%d次划分：",i);
    for(j=0;j<s;j++){
        printf("   ");
    }
    for(j=s;j<=t;j++){
        printf("%3d",R[j].key);
    }
    printf("\n");
    i++;
}

//* 快速排序一趟划分
int partition(RecType R[],int s,int t){
    int i=s,j=t;
    RecType base=R[i];
    while(i<j){
        while(j>i&&R[j].key>=base.key){j--;}
        R[i]=R[j];
        while(i<j&&R[i].key<=base.key){i++;}
        R[j]=R[i];
    }
    R[i]=base;
    disppart(R,s,t);
    return i;
}

//* 快速排序算法
void quickSort(RecType R[],int s,int t){
    int i;
    if(s<t){
        i=partition(R,s,t);
        quickSort(R,s,i-1);
        quickSort(R,i+1,t);
    }
}

int main(){
    int n=10;
    printf("------------------插入排序--------------------\n");
    KeyType a[]={9,8,7,6,5,4,3,2,1,0};
    RecType R[MAXL];
    createList(R,a,n);
    dispList(R,n);
    insertSort(R,n);
    dispList(R,n);
    printf("------------------冒泡排序--------------------\n");
    KeyType a2[]={6,8,7,9,0,1,3,2,4,5};
    RecType R2[MAXL];
    createList(R2,a2,n);
    dispList(R2,n);
    BubbleSort(R2,n);
    dispList(R2,n);
    printf("------------------冒泡排序--------------------\n");
    KeyType a3[]={6,8,7,9,0,1,3,2,4,5};
    RecType R3[MAXL];
    createList(R3,a3,n);
    dispList(R3,n);
    quickSort(R3,0,n-1);
    dispList(R3,n);
}