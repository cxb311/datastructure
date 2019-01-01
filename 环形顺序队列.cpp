#include<iostream>
#define MaxSize 50

typedef int ElemType;
typedef double Elem;
using namespace std;

//顺序队类型声明

typedef struct
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

//初始化循环队列

void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

//销毁队列

void DestroyQueue(SqQueue *&q)
{
    free(q);
}

//判断队列是否为空

bool QueueEmpty(SqQueue *q)
{
    return (q->front==q->rear);
}

//进队列

bool enQueue(SqQueue *&q,ElemType e)
{
    if((q->rear+1)%MaxSize==q->front)
    {
        return false;
    }
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}

//出队列

bool deQueue(SqQueue *&q,ElemType &e)
{
    if(q->front==q->rear)
    {
        return false;
    }
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}

//用队列中的元素个数代替队尾指针

//环形队列声明

typedef struct
{
    ElemType data[MaxSize];
    int front;
    int count;
}QuType;

//初始化

void InitQueue(QuType *&qu)
{
    qu=(QuType *)malloc(sizeof(QuType));
    qu->front=0;
    qu->count=0;
}

//进队

bool EnQueue(QuType *&qu,ElemType x)
{
    int rear;
    if(qu->count==MaxSize)
    {
        return false;
    }
    else
    {
        rear=(qu->front+qu->count)%MaxSize;
        rear=(rear+1)%MaxSize;
        qu->data[rear]=x;
        qu->count++;
        return true;
    }
}

//出队

bool DeQueue(QuType *&qu,ElemType &x)
{
    if(qu->count==0)
    {
        return false;
    }
    else
    {
        qu->front=(qu->front+1)%MaxSize;
        x=qu->data[qu->front];
        qu->count--;
        return true;
    }
}

//判断队空

bool QueueEmpty(QuType *qu)
{
    return (qu->count==0);
}

//求解报数问题

//思路：先出队一个元素，输出其编号，然后再出队一个元素，并将刚出队的元素进队，知道
//队为空

void number(int n)
{
    int i;
    ElemType e;
    SqQueue *q;
    InitQueue(q);
    for(i=1;i<n;i++)
    {
        enQueue(q,i);
    }
    cout<<"报出出列顺序: "<<endl;
    while(!QueueEmpty(q))
    {
        deQueue(q,e);
        cout<<e<<",";
        if(!QueueEmpty(q))
        {
            deQueue(q,e);
            enQueue(q,e);
        }
    }
    cout<<endl;
    DestroyQueue(q);
}