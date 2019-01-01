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

//初始化队列

Void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
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
    if(q->rear==MaxSize-1)
    {
        return false;
    }
    q->rear++;
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
    q->front++;
    e=q->data[q->front];
    return true;
}


//求解迷宫路径问题

//设置数组表示迷宫
const int M=8,N=8;
int mg[M+2][N+2]=
{
    {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};

//类型声明

typedef struct
{
    int i,j;
    int pre;
}Box;

typedef struct
{
    Box data[MaxSize];
    int front,rear;
}QuType;

//

bool mgpathl(int xi,int yi,int xe,int ye)
{
    Box e;
    int i,j,di,i1,j1;
    QuType *qu;
    InitQueue(qu);
    e.i=xi;
    e.j=yi;
    e.pre=-1;
    enQueue(qu,e);
    mg[xi][yi]=-1;
    while(!QueueEmpty(qu))
    {
        deQueue(qu,e);
        i=e.i;
        j=e.j;
        if(i==xe&&j==ye)
        {
            print(qu,qu->front);
            DestroyQueue(qu);
            return true;
        }
        for(di=0;di<4;di++)
        {
            switch(di)
            {
                case 0:i1=i-1;ji=j;break;
                case 1:i1=i;j1=j+1;break;
                case 2:i1=i+1;j1=j;break;
                case 3:i1=i;j1=j-1;break;
            }
            if(mg[i1][j1]==0)
            {
                e.i=i1;
                e.j=j1;
                e->pre=qu->front;
                enQueue(qu,e);
                mg[i1][j1]=-1;
            }
        }
    }
    DestroyQueue(qu);
    return false;
}

void print(QuType *qu,int front)
{
    int k=front,j,ns=0;
    cout<<endl;
    do{
        j=k;
        k=qu->data[k].pre;
        qu->data[j].pre=-1;
    }while(k!=0);
    cout<<"一条迷宫路径如下: "<<endl;
    k=0;
    while(k<MaxSize)
    {
        if(qu->data[k].pre==-1)
        {
            ns++;
            cout<<"("<<qu->data[k].i<<","<<qu->data[k].j<<")";
            if(ns%5==0)
            {
                cout<<endl;
            }
        }
        k++;
    }
    cout<<endl;
}