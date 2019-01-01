#include<iostream>
#define MaxSize 50

typedef char ElemType;
typedef double Elem;
using namespace std;

//链队中数据结点的声明

typedef struct qnode
{
    ElemType data;
    struct qnode *next;
}DataNode;

//链队头结点类型声明

typedef struct
{
    DataNode *front;
    DataNode *rear;
}LinkQuNode;

//初始化队列

void InitQueue(LinkQuNode *&q)
{
    q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL;
}

//销毁队列

void DestroyQueue(LinkQuNode *&q)
{
    DataNode *pre=q->front,*p;
    if(pre!=NULL)
    {
        p=pre->next;
        while(p!=NULL)
        {
            free(pre);
            pre=p;
            p=p->next;
        }
        free(pre);
    }
    free(q);
}

//判断队列是否为空

bool QueueEmpty(LinkQuNode *q)
{
    return (q->rear==NULL);
}

//进队

void enQueue(LinkQuNode *&q,ElemType e)
{
    DataNode *p;
    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL)
    {
        q->front=q->rear=p;
    }
    else
    {
        q->rear->next=p;
        q->rear=p;
    }
}

//出队

bool deQueue(LinkQuNode *&q,ElemType &e)
{
    DataNode *t;
    if(q->rear==NULL)
    {
        return false;
    }
    t=q->front;
    if(q->front==q->rear)
    {
        q->front=q->rear=NULL;
    }
    else
    {
        q->front=q->front->next;
    }
    e=t->data;
    free(t);
    return true;
}

//采用一个不带头结点只有一个尾节点指针rear的循环单链表存储队列

//结点类型声明

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkNode;

//初始化

void initQueue(LinkNode *& rear)
{
    rear=NULL;
}

//进队

void enQueue(LinkNode *&rear,ElemType e)
{
    LinkNode *p;
    p=(LinkNode *)malloc(sizeof(LinkNode));
    p->data=e;
    if(rear==NULL)
    {
        p->next=p;
        rear=p;
    }
    else
    {
        p->next=rear->next;
        rear->next=p;
        rear=p;
    }
}

//出队

bool deQueue(LinkNode *&rear,ElemType &e)
{
    LinkNode *t;
    if(rear==NULL)
    {
        return false;
    }
    else if(rear->next==rear)
    {
        e=rear->data;
        free(rear);
        rear=NULL;
    }
    else
    {
        t=rear->next;
        e=t->data;
        rear->next=t->next;
        free(t);
    }
    return true;
}

//判断队空

bool queueEmpty(LinkNode *rear)
{
    return (rear==NULL);
}

