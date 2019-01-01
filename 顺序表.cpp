#include<iostream>
#define MaxSize 50

typedef int ElemType;
//线性表结构体
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;
//建立顺序表
void CreateList(SqList *&L,ElemType a[],int n)
{
    int i=0,k=0;
    L=(SqList *)malloc(sizeof(SqList));
    while(i>n)
    {
        L->data[i]=a[i];
        k++;
        i++;
    }
    L->length=k;
}
//初始化线性表
void InitList(SqList *&L)
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}
//销毁线性表
void DestroyList(SqList *&L)
{
    free(L);
}
//判断线性表是否为空表
bool ListEmpty(SqList *L)
{
    return(L->length==0);
}
//求线性表长度
int ListLength(SqList *L)
{
    return (L->length);
}
//输出线性表
void DispList(SqList *L)
{
    for(int i=0;i<l->length;i++)
    {
        printf("%d",L->data[i]);
    }
    printf("\n");
}
//求线性表中的某个数据元素值
bool GetElem(SqList *L,int i,ElemType &e)
{
    if(i<1||i>L->length)
    {
        return false;
    }
    e=L->data[i-1];
    return true;
}
//按元素值查找位置
int LocateElem(SqList *L,ElemType e)
{
    int i=0;
    while(i<L->length&&L->data[i]!=e)
    {
        i++;
    }
    if(i>=L->length)
    {
        return 0;
    }
    else
    {
        return i+1;
    }
}
//插入数据元素
bool ListInsert(SqList *&L,int i,ElemType e)
{
    int j;
    if(i<1||i>L->length+1)
    {
        return false;
    }
    i--;
    for(j=L->length;j>i;j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
    return true;
}
//删除数据元素
bool ListDelete(SqList *&L,int i,ElemType &e)
{
    int j;
     if(i<1||i>L->length+1)
    {
        return false;
    }
    i--;
    e=L->data[i];
    for(j=i;j<L->length-1;j++)
    {
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}
//交换数据元素
void swap(ElemType &a,ElemType &b)
{
    ElemType temp;
    temp=a;
    a=b;
    b=temp;
}


//顺序表算法1
//删除顺序表中所有值为x的元素  要求时间复杂度O(n)
//解法1：重建L只包含不等于x的元素,问题：K之后的元素没有处理？
void delnodel(SqList *&L,ElemType x)
{
    int k=0,i;
    for(i=0;i<L->length;i++)
    {
        if(L->data[i]!=x)
        {
            L->data[k]=L->data[i];
            k++;
        }
    }
    L->length=k;
}

//解法2：从左到右扫描所有元素，k为L中当前等于x的元素个数，当i指向的元素为x值时k增1；
//否则将不为x的元素前移k个位置

void delnode2(SqList *&L,ElemType x)
{
    int k=0,i=0;
    while(i<L->length)
    {
        if(L->data[i]==x)
        {
            k++;
        }
        else
        {
            L->data[i-k]=L->data[i];
        }
        i++;
    }
}


//顺序表算法2
//以第一个元素为分界线，将所有小于等于它的元素移到该基准的前面，
//将所有大于它的元素移到它后面
//基本思路：从右向左找一个小于等于基准的元素x，从右向左找一个大于基准的元素y,将两者交换，直至全部找完

//解法1：

void partitiona1(SqList *&L)
{
    int i=0,j=L->length-1;
    ElemType pivot=L->data[0];//基准点
    while(i<j)         //从区间两端交替向中间扫描，直到i=j为止
    {
        while(i<j&&L->data[j]>pivot)
        {
            j--;              //从右向左扫描，找一个小于等于pivot的元素
        }
        while(i<j&&L->data[i]<=pivot)
        {
            i++;                //从左向右扫描，找一个大于pivot的元素
        }
        if(i<j)
        {
            swap(L->data[i],L->data[j]);   //将左边大于基准点和右边小于基准点的元素交换
        }
    }
    swap(L->data[0],L->data[i]);     //将基准点和i交换
}

//解法2：

void partitiona2(SqList *&L)
{
    int i=0,j=L->length-1;
    ElemType pivot=L->data[0];
    while(i<j)
    {
        while(j>i&&L->data[j]>pivot)
        {
            j--;
        }
        L->data[i]=L->data[j];
        while(i<j&&L->data[i]<=pivot)
        {
            i++;
        }
        L->data[j]=L->data[i];
    }
    L->data[i]=pivot;                                                                                           
}


//顺序表算法3
//将所有奇数移到偶数的前面

//解法1：i从左向右找偶数元素，j从右向左找奇数元素，交换

void move1(SqList *&L)
{
    int i=0,j=L->length-1;
    while(i<j)
    {
        while(i<j&&L->data[j]%2==0)
        {
            j--;
        }
        while(i<j&&L->data[i]%2==1)
        {
            i++;
        }
        if(i<j)
        {
            swap(L->data[i],L->data[j]);
        }
    }
}

//解法2:

void move2(SqList *&L)
{
    int i=-1,j;
    for(i=0;j<L->length;j++)
    {
        if(L->data[j]%2==1)   //若元素为奇数
        {
            i++;
            if(i!=j)
            {
                swap(L->data[i],L->data[j]);
            }
        }
    }
}