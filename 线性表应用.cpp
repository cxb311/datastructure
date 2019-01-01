//两个表的自然连接问题

//由于每个表中的行数不确定，因此采用单链表作为表的存储结构，每行作为一个数据结点
//称为行结点，另外，每行中的元素个数也是不确定的，但由于需要提供随机查找行中的数据元素，
//所以每行的数据元素采用顺序存储结构

//单链表中数据结点的结构声明

#include<iostream>
#define MaxCol 10
typedef int ElemType;
using namespace std;
typedef struct Node1
{
    ElemType data[MaxCol];
    struct Node1 *next;
}DList;

//单链表头结点类型声明

typedef struct Node2
{
    int Row,Col;
    DList *next;
}HList;

//采用交互方式建立单链表的算法
//采用尾插法创建单链表，用户先输入表的行数和列数，然后输入各行的数据

void CreateTable(HList *&h)
{
    int i,j;
    DList *r,*s;
    h=(HList *)malloc(sizeof(HList));
    cout<<"表的行数，列数："<<endl;
    cin>>h->Row;
    cin>>h->Col;

    for(i=0;i<h->Row;i++)
    {
        cout<<"第"<<i+1<<"行："<<endl;
        s=(DList *)malloc(sizeof(DList));
        for(j=0;j<h->Col;j++)
        {
            cin>>s->data[j];
        }
        if(h->next==NULL)
        {
            h->next=s;
        }
        else
        {
            r->next=s;
        }
        r=s;
    }
    r->next=NULL;
}

//销毁单链表的算法

void DestroyTable(HList *&h)
{
    DList *pre=h->next,*p=pre->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
    free(h);
}

//输出单链表算法

void DispTable(HList *h)
{
    int j;
    DList *p=h->next;
    while(p!=NULL)
    {
        for(j=0;j<h->Col;j++)
        {
            cout<<p->data[j]<<" ";
        }
        cout<<endl;
        p=p->next;
    }
}

//表连接运算算法

void LinkTable(HList *h1,HList *h2,HList *&h)
{
    int i,j,k;
    DList *p=h1->next,*q,*s,*r;
    cout<<"连接字段是：第1个序列号，第2个序列号：";
    std::cin>>i;
    std::cin>>j;
    h=(HList *)malloc(sizeof(HList));
    h->Row=0;
    h->Col=h1->Col+h2->Col;
    h->next=NULL;

    while(p!=NULL)
    {
        q=h2->next;
        while(q!=NULL)
        {
            if(p->data[i-1]==q->data[j-1])
            {
                s=(DList *)malloc(sizeof(DList));
                for(k=0;k<h1->Col;k++)
                {
                    s->data[k]=p->data[k];
                }
                for(k=0;k<h2->Col;k++)
                {
                    s->data[h1->Col+k]=q->data[k];
                }
                if(h->next==NULL)
                {
                    h->next=s;
                }
                else
                {
                    r->next=s;
                }
                r=s;
                h->Row++;
            }
            q=q->next;
        }
        p=p->next;
    }
    r->next=NULL;
}


//求解程序

int main()
{
    HList *h1,*h2,*h;
    cout<<"表1:\n";
    CreateTable(h1);
    cout<<"表2:\n";
    CreateTable(h2);
    LinkTable(h1,h2,h);
    cout<<"连接结果表:\n";
    DispTable(h);
    DestroyTable(h1);
    DestroyTable(h2);
    DestroyTable(h);
    return 0;
}


//能用的版本
#include<stdio.h>
#include<stdlib.h>
 
 
/************************************************************************/
/* 问题： 假设有两个表A和B，分别是m1行、n1列和m2行、n2列，它们简        *
 * 单自然连接结果C=AxB（i=j)，其中i表示表A中列号，j表示表B中的列号，    *
 * C为A和B的笛卡儿积中满足指定连接条件的所有记录组，该连接条件为表A     *
 * 的第i列与表B的第j列相等。                                            */
/************************************************************************/
 
#define M1 3        //A表的行数
#define N1 3		//A表的列数
 
#define M2 3		//B表的行数
#define N2 2		//B表的列数
 
#define MaxRow 10
typedef int ElemType;
typedef struct Node1       //数据节点结构体，也就是表的一行
{
	ElemType data[MaxRow];
	struct Node1 *next;     //指向后继数据节点，也就是当前行的下一行
}DList;
 
typedef struct Node2	//定义头节点类型
{
	int Row, Col;		//表示的表行数和列数
	DList *next;        //头节点指向的下一个当然就是数据节点了
}HList;
 
 
 
/* CreateTable:创建单链表A */
void CreateTableA(HList * &h, ElemType (*array)[N1],int n)
{
	int i = 0;
	int j = 0;
	DList *r, *s;          // r将作为尾节点，s作为每轮当前插入的节点
	r = NULL;
	h = (HList *)malloc(sizeof(HList));   //头节点
	h->Col = N1;			//头节点存储表的行数
	h->Row = n;				//头节点存储表的列数
	h->next = NULL;
	for (i = 0; i < h->Row; ++i)
	{
		s = (DList *)malloc(sizeof(DList));    //为临时存储当前插入节点开辟空间
		for (j = 0; j < h->Col; ++j)			//赋值到s中
		{
			//DL->data[j] = *(*(array+i) + j);
			s->data[j] = array[i][j];
		}                                //s的数据data赋值完成
		if (h->next == NULL)             //尾插法插入数据 s
			h->next = s;
		else
			r->next = s;
		r = s;
	}
	r->next = NULL;
}
 
/* CreateTable:创建单链表B,只能根据第二维是N2的数组来创建 */
void CreateTableB(HList * &h, ElemType(*array)[N2], int n)
{
	int i = 0;
	int j = 0;
	DList *r, *s;
	r = NULL;
	h = (HList *)malloc(sizeof(HList));
	h->Col = N2;
	h->Row = n;
	h->next = NULL;
	//DList *DL = (DList *)malloc(sizeof(DList));
	for (i = 0; i < h->Row; ++i)
	{
		s = (DList *)malloc(sizeof(DList));
		for (j = 0; j < h->Col; ++j)
		{
			//DL->data[j] = *(*(array+i) + j);
			s->data[j] = array[i][j];
		}
		if (h->next == NULL)
			h->next = s;
		else
			r->next = s;
		r = s;
	}
	r->next = NULL;
}
 
/* DistroyTable:销毁表 */
void DistroyTable(HList *&h)    
{
	DList *pre = h->next, *p = pre->next;
	while (p != NULL)  //逐个往后销毁节点
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);		//销毁最后一个节点
	free(h);		//销毁头节点
}
 
/* DispList: 输出链表 */
void DispTable(HList *h)
{
	DList *p;
	int j = 0;
	p = h->next;
	while (p != NULL)    //节点往后移 
	{
		for (j = 0; j < h->Col; ++j)   //节点里面数组每个元素逐个打印出来
		{
			printf(" %-5d", p->data[j]);  
		}
		p = p->next;
		printf("\n");
	}
	printf("\n\n");
}
 
 
/* LinkTable:实现两个表简单自然连接 h3作为连接产生的表 */
void LinkTable(HList *h1, HList *h2, HList *&h3,int i1, int i2)
{
	int i;
	DList *p = h1->next, *q, *s, *r; //p作为表h1往后移动的节点 q作为h2往后移动的节点， s,r是尾插法所需
	r = NULL;
	h3 = (HList *)malloc(sizeof(HList));   //建立头节点
	h3->Row = 0;
	h3->Col = h1->Col + h2->Col;
	h3->next = NULL;
	while (p != NULL)
	{
		q = h2->next;        //这个表达式放在这里是因为q要在h2中循环遍历多次
		while (q != NULL)    
		{
			if (p->data[i1 - 1] == q->data[i2 - 1])       //比较条件，也就是过滤笛卡尔积的条件
			{
				s = (DList *)malloc(sizeof(DList));   //下面就是开始尾插法插入
				for (i = 0; i < h1->Col; ++i)         //表A的一行中每个元素赋值个表C当前行元素
				{
					s->data[i] = p->data[i];
				}
				for (; i < h3->Col; ++i)           //表B元素增加到表C当前行（也就是刚才表A的
				{                                  //元素后面）
					s->data[i] = q->data[i - h1->Col];
				}
				if (h3->next == NULL)              //尾插法插入
					h3->next = s;
				else
					r->next = s;
				r = s;
				h3->Row++;
			}
			q = q->next;
		}
		p = p->next;
	}
	r->next = NULL;        //最后一个节点的后置节点要设为NULL
}
 
 
int main()
{
	ElemType A[M1][N1] = {        //数组形式的表A
		{ 1, 2, 3 },
		{ 2, 3, 3 },
		{ 1, 1, 1 }
	};
 
	ElemType B[M2][N2] = {         //数组形式的表B
		{ 3, 5 },
		{ 1, 6 },
		{ 3, 4 }
	};
	HList *h_A;		//链表形式的表A
	HList *h_B;     //链表形式的表B
	HList *h_C;		//链表形式的表C
	CreateTableA(h_A, A, M1);   //将数组形式表A变为链表形式表A
	CreateTableB(h_B, B, M2);   
 
	DispTable(h_A);     
	DispTable(h_B);
 
	LinkTable(h_A, h_B, h_C, 3, 1);
	DispTable(h_C);
 
	DistroyTable(h_A);
	DistroyTable(h_B);
	DistroyTable(h_C);
	system("pause");
	return 0;
}