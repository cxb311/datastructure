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

//3个带头结点的单链表LA,LB,LC，元素递增排列，(假设每个单链表不存在数据值相同的结点，
//但3个链表中可能存在在数据值相同的结点)，设计算法对LA操作，使操作后的链表LA中仅留
//下3个表中均包含的数据元素的结点，且没有数据值相同的结点，并释放LA中所有的无用结点


void Commnode(LinkNode *&LA,LinkNode *&LB,LinkNode *&LC)
{
    LinkNode *pa=LA->next,*pb=LB->next,*pc=LC->next,*q,*r;
    LA->next=NULL;
    r=LA;
    while(pa!=NULL)
    {
        while(pb!=NULL&&pa->data>pb->data)
        {
            pb=pb->next;
        }
        while(pc!=NULL&&pa->data>pc->data)
        {
            pc=pc->next;
        }
        if(pb!=NULL&&pc!=NULL&&pa->data==pb->data&&pa->data==pc->data)
        {
            r->next=pa;
            r=pa;
            pa=pa->next;
        }
        else
        {
            q=pa;
            pa=pa->next;
            free(q);
        }
    }
    r->next=NULL;
}

//有序单链表，设计一个算法删除删除至于重复的结点
//由于是有序单链表，所以相同值域的点是相邻的，用p扫描单链表，
//若p所指结点的值等于其后继结点的值，就将其删除

void dels(LinkNode *&L)
{
    LinkNode *p=L->next,*q;
    while(p->next!=NULL)
    {
        if(p->data==p->next->data)
        {
            q=p->next;
            p->next=q->next;
            free(q);
        }
        else
        {
            p=p->next;
        }
    }
}

//求两个序列A和B的中位数，序列采用顺序表存储

ElemType M_Search(SqList *A,SqList *B)
{
    int i=0,j=0,k=0;
    while(i<A->length&&j<B->length)
    {
        k++;
        if(A->data[i]<B->data[j])
        {
            if(k==A->length)
            {
                return A->data[i];
            }
            i++;
        }
        else
        {
            if(k==B->length)
            {
                return B->data[j];
            }
            j++;
        }
    }
}