#include<iostream>
typedef int ElemType;

//单链表

//声明
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkNode;

//创建单链表

//头插法:从链表头节点插入，单链表中的数据节点的顺序与数组a中的元素顺序相反

void CreateListF(LinkNode *&L,ElemType a[],int n)
{
    LinkNode *S;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

//尾插法：从链表尾节点插入，单链表中的数据节点的顺序与数组a中的元素顺序相同

void CreateListR(LinkNode *&L,ElemType a[],int n)
{
    LinkNode *s,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    r=L;
    for(int i=0;i<n;i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

//初始化线性表

void InitList(LinkNode *&L)
{
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}

//销毁线性表

void DestroyList(LinkNode *&L)
{
    LinkNode *pre=L,*p=L->next;
    while(P!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

//判断线性表是否为空表

bool ListEmpty(LinkNode *L)
{
    return (L->next==NULL);
}

//求线性表的长度

int ListLength(LinkNode *L)
{
    int n=0;
    LinkNode *p=L;
    while(P->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}

//输出线性表

void DispList(LinkNode *L)
{
    LinkNode *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

//求线性表中的某个数据元素值

bool GetElem(LinkNode *L,int i,ElemType &e)
{
    int j=0;
    LinkNode *p=L;
    if(i<=0)
    {
        return false;
    }
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        e=p->data;
        return true;
    }
}

//按元素值查找位置

int LocateElem(LinkNode *L,ElemType e)
{
    int i=1;
    LinkNode *p=L->next;

    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return i；
    }
}

//插入数据元素

bool ListInsert(LinkNode *&L,int i,ElemType e)
{
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)
    {
        return false;
    }
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

//删除数据元素

bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
    int j=0;
    LinkNode *p=L,*q;
    if(i<=0)
    {
        return false;
    }
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        q=p->next;
        if(q==NULL)
        {
            return false;
        }
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}

//单链表算法
//算法1：将一个链表拆分为两个链表L=(a1,b1,a2,b2...),
//L1=(a1,a2,a3...),L2=(bn,bn-1,bn-2...)

//L1中结点顺序与L相同，用尾插法；L2中结点顺序与L相反，用头插法

void split(LinkNode *&L,LinkNode *&L1,LinkNode *&L2)
{
    LinkNode *p=L->next,*q,*r1;
    L1=L;
    r1=L1;
    L2=(LinkNode *)malloc(sizeof(LinkNode));
    L2->next=NULL;
    while(p!=NULL)
    {
        r1->next=p;
        r1=p;
        p=p->next;
        q=p->next;
        p->next=L2->next;
        L2->next=p;
        q=p;
    }
    r1->next=NULL;
}

//算法2：删除一个单链表L中元素值最大的结点（假设这样的结点唯一）

void delmaxnode(LinkNode *&L)
{
    LinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
    while(p!=NULL)
    {
        if(maxp->data<p->data)
        {
            maxp=p;
            maxpre=pre;
        }
        pre=p;
        p=p->next;
    }
    maxpre->next=maxp->next;
    free(maxp);
}

//算法3:使单链表元素递增有序排列
//思路：新建一个有序链表，扫描原链表，跟有序链表的值比较插入（插入排序）

void sort(LinkNode *&L)
{
    LinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)
        {
            pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=q;
    }
}

//双链表

//声明双链表

typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkNode;

//建立双链表

//头插法

void CreateListF(DLinkNode *&L,ElemType a[],int n)
{
    DLinkNode *s;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior=L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        s->next=L->next;
        if(L->next!=NULL)
        {
            L->next->prior=s;
        }
        L->next=s;
        s->prior=L;
    }
}

//尾插法

void CreateListR(DLinkNode *&L,ElemType a[],int n)
{
    DLinkNode *s,*r;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    r=L;
    for(int i=0;i<n;i++)
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=NULL;
}

//双链表插入

bool ListInsert(DLinkNode *&L,int i,ElemType e)
{
    int j=0;
    DLinkNode *p=L,*s;
    if(i<=0)
    {
        return false;
    }
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=e;
        s->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prior=s;
        }
        s->prior=p;
        p->next=s;
        return true;
    }
}

//双链表删除

bool ListDelete(DLinkNode *&L,int i,ElemType &e)
{
    int j=0;
    DLinkNode *p=L,*q;
    if(i<=0)
    {
        return false;
    }
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        q=p->next;
        if(q==NULL)
        {
            return false;
        }
        e=q->data;
        p->next=q->next;
        if(p->next!=NULL)
        {
            p->next->prior=p;
        }
        free(q);
        return true;
    }
}

//双链表算法

//算法1：将算法中的所有元素逆置
//思路:使用头插法重建一个链表即可，因为头插法后的结果是倒序的

void reverse(DLinkNode *&L)
{
    DLinkNode *p=L->next,*q;
    L->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        p->next=L->next;
        if(L->next!=NULL)
        {
            L->next->prior=p;
        }
        L->next=p;
        p->prior=L;
        p=q;
    }
}

//算法2:使链表元素递增有序排列

void sort(DLinkNode *&L)
{
    DLinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)
        {
            pre=pre->next;
        }
        p->next=pre->next;
        if(pre->next!=NULL)
        {
            pre->next->prior=p;
        }
        pre->next=p;
        p->prior=pre;
        p=q;
    }
}

//循环链表

//循环链表算法

//算法1：设计算法统计循环单链表中x值的个数

int count(LinkNode *L.ElemType x)
{
    int i=0;
    LinkNode *p=L->next;
    while(p!=L)
    {
        if(p->data==x)
        {
            i++;
        }
        p=p->next;
    }
    return i;
}

//算法2:循环双链表，删除第一个data阈值为x的结点

bool delelem(DLinkNode *&L.ElemType x)
{
    DLinkNode *p=L->next;
    while(p!=L&&p->data!=x)
    {
        p=p->next;
    }
    if(p!=L)
    {
        p->next->prior=p->prior;
        p->prior->next=p->next;
        free(p);
        return true;
    }
    else
    {
        return false;
    }
}

//算法3:判断循环双链表中数据是否对称
//思路:用p从左向右扫描L，q从右向左扫描L，然后循环，若p,q值不相等，退出循环，返回False，
//否则继续比较，知道p==q或p==q->prior返回true

bool Symm(DLinkNode *L)
{
    bool same=true;
    DLinkNode *p=L->next;
    DLinkNode *q=L->prior;
    while(same)
    {
        if(p->data!=q->data)
        {
            same=false;
        }
        else
        {
            if(p==q||p==q->prior)
            {
                break;
            }
            q=q->prior;
            p=p->next;
        }
    }
    return same;
}