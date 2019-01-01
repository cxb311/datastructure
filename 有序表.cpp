#include<iostream>
#define MaxSize 50

typedef int ElemType;
//线性表结构体
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;

//单链表

//声明
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkNode;


//以顺序表存储有序表

//插入算法，插入后有序表应依旧有序，故与一般顺序表插入不一样不能以固定元素位置插入

void ListInsert(SqList *&L,ElemType e)
{
    int i=0,j;
    while(i<L->length&&L->data[i]<e)
    {
        i++;
    }
    for(j=L->length;j>i;j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
}

//以单链表存储有序表
//插入算法

void ListInsert(LinkNode *&L,ElemType e)
{
    LinkNode *pre=L,*p;
    while(pre->next!=NULL&&pre->next->data<e)
    {
        pre=pre->next;
    }
    p=(LinkNode *)malloc(sizeof(LinkNode));
    p->data=e;
    p->next=pre->next;
    pre->next=p;
}

//有序表的归并算法
//将两个有序表LA和LB合并成一个有序表LC(假设每个有序表中和两个有序表间
//均不存在重复元素)

//思路：二路归并算法，分别扫描LA和LB两个有序表，当两个有序表都没有扫描完时循环：
//比较LA，LB当前元素，将其中较小的元素放入LC中，再从较小元素所在的有序表中取下
//一个元素，重复这个过程知道LA或LB比较完毕，最后将未比较完的有序表中余下的元素
//放入LC中


//采用顺序表存储时
void UnionList(SqList *LA,SqList *LB,SqList *&LC)
{
    int i=0,j=0,k=0;
    LC=(SqList *)malloc(sizeof(SqList));
    while(i<LA->length&&j<LB->length)
    {
        if(LA->data[i]<LB->data[j])
        {
            LC->data[k]=LA->data[i];
            i++;
            k++;
        }
        else
        {
            LC->data[k]=LB->data[j];
            j++;
            k++;
        }
    }
    while(i<LA->length)
    {
        LC->data[k]=LA->data[i];
        i++;
        k++;
    }
    while(j<LB->length)
    {
        LC->data[k]=LB->data[j];
        j++;
        k++;
    }
    LC->length=k;
}


//采用单链表存储

void UnionList1(LinkNode *LA,LinkNode *LB,LinkNode *&LC)
{
    LinkNode *pa=LA->next,*pb=LB->next,*r,*s;
    LC=(LinkNode *)malloc(sizeof(LinkNode));
    r=LC;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<pb->data)
        {
            s=(LinkNode *)malloc(sizeof(sizeof(LinkNode)));
            s->data=pa->data;
            r->next=s;
            r=s;
            pa=pb->next;
        }
    }
    while(pa!=NULL)
    {
        s=(LinkNode *)malloc(sizeof(sizeof(LinkNode)));
        s->data=pa->data;
        r->next=s;
        r=s;
        pa=pa->next;
    }
    while(pb!=NULL)
    {
        s=(LinkNode *)malloc(sizeof(sizeof(LinkNode)));
        s->data=pb->data;
        r->next=s;
        r=s;
        pb=pb->next;
    }
    r->next=NULL;
}