#include<iostream>
#define MaxSize 50

typedef char ElemType;
typedef double Elem;
using namespace std;

//顺序栈声明,利用栈指针s(不同于栈顶指针)来创建使用栈

typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;

typedef struct
{
    Elem data[MaxSize];
    int top;
}SqStackl;

//初始化栈

void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

//初始化栈

void InitStackl(SqStackl *&s)
{
    s=(SqStackl *)malloc(sizeof(SqStackl));
    s->top=-1;
}

//销毁栈

void DestroyStack(SqStack *&s)
{
    free(s);
}

void DestroyStackl(SqStackl *&s)
{
    free(s);
}

//判断栈是否为空

bool StackEmpty(SqStack *s)
{
    return (s->top==-1);
}


//判断栈是否为空

bool StackEmptyl(SqStackl *s)
{
    return (s->top==-1);
}

//进栈

bool Push(SqStack *&s,ElemType e)
{
    if(s->top==MaxSize-1)
    {
        return false;
    }
    s->top++;
    s->data[s->top]=e;
    return true;
}

//进栈

bool Pushl(SqStackl *&s,Elem e)
{
    if(s->top==MaxSize-1)
    {
        return false;
    }
    s->top++;
    s->data[s->top]=e;
    return true;
}

//出栈

bool Pop(SqStack *&s,ElemType &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    s->top--;
    return true;
}

//出栈

bool Popl(SqStackl *&s,Elem &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    s->top--;
    return true;
}

//取栈顶元素

bool GetTop(SqStack *s,ElemType &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    return true;
}

//取栈顶元素

bool GetTopl(SqStackl *s,Elem &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    return true;
}

//利用顺序栈判断一个字符串是否为对称串

//利用n个元素连续进栈，产生的连续出栈序列和输入序列正好相反，若出栈序列与进栈序列相同，
//则说明是对称串

bool symmetry(ElemType str[])
{
    int i;ElemType e;
    SqStack *st;
    InitStack(st);
    for(i=0;str[i]!='\0';i++)
    {
        Push(st,str[i]);
    }
    for(i=0;str[i]!='\0';i++)
    {
        Pop(st,e);
        if(str[i]!=e)
        {
            DestroyStack(st);
            return false;
        }
    }
    DestroyStack(st);
    return true;
}


//栈的应用

//简单表达式求值(顺序栈)

//将中缀表达式转换成后缀表达式

void trans(char *exp,char postexp[])
{
    char e;
    SqStack *Optr;
    InitStack(Optr);
    int i=0;
    while(*exp!='\0')
    {
        switch(*exp)
        {
            case '(':
                Push(Optr,'(');
                exp++;
                break;
            case ')':
                Pop(Optr,e);
                while(e!='(')
                {
                    postexp[i++]=e;
                    Pop(Optr,e);
                }
                exp++;
                break;
            case '+':
            case '-':
                while(!StackEmpty(Optr))
                {
                    GetTop(Optr,e);
                    if(e!='(')
                    {
                        postexp[i++]=e;
                        Pop(Optr,e);
                    }
                    else
                    {
                        break;
                    }
                }
                Push(Optr,*exp);
                exp++;
                break;
            case '*':
            case '/':
                while(!StackEmpty(Optr))
                {
                    GetTop(Optr,e);
                    if(e=='*'||e=='/')
                    {
                        postexp[i++]=e;
                        Pop(Optr,e);
                    }
                    else
                    {
                        break;
                    }
                }
                Push(Optr,*exp);
                exp++;
                break;
            default:
                while(*exp>='0'&&*exp<='9')
                {
                    postexp[i++]=*exp;
                    exp++;
                }
                postexp[i++]='#';
        }
    }

    while(!StackEmpty(Optr))
    {
        Pop(Optr,e);
        postexp[i++]=e;
    }
    postexp[i]='\0';
    DestroyStack(Optr);
}

//后缀表达式求值

double compvalue(char * postexp)
{
    double d,a,b,c,e;
    SqStackl *Opnd;
    InitStackl(Opnd);
    while(*postexp!='\0')
    {
        switch(*postexp)
        {
            case '+':
                Popl(Opnd,a);
                Popl(Opnd,b);
                c=b+a;
                Pushl(Opnd,c);
                break;
            case '-':
                Popl(Opnd,a);
                Popl(Opnd,b);
                c=b-a;
                Pushl(Opnd,c);
                break;
            case '*':
                Popl(Opnd,a);
                Popl(Opnd,b);
                c=b*a;
                Pushl(Opnd,c);
                break;
            case '/':
                Popl(Opnd,a);
                Popl(Opnd,b);
                if(a!=0)
                {
                    c=b/a;
                    Pushl(Opnd,c);
                    break;
                }
                else
                {
                    cout<<"\n除零错误\n";
                    exit(0);
                }
                break;
            default:
                d=0;
                while(*postexp>='0'&&*postexp<='9')
                {
                    d=10*d+*postexp-'0';
                    postexp++;
                }
                Pushl(Opnd,d);
                break;
        }
        postexp++;
    }
    GetTopl(Opnd,e);
    DestroyStackl(Opnd);
    return e;
}

//调用算法

int main()
{
    char exp[]="(56-20)/(4+2)";
    char postexp[MaxSize];
    trans(exp,postexp);
    cout<<"中缀表达式: "<<exp<<endl;
    cout<<"中缀表达式: "<<postexp<<endl;
    cout<<"表达式的值: "<<compvalue(postexp)<<endl;
    return 0;
}

//求解迷宫问题

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

//迷宫栈声明

typedef struct
{
    int i;
    int j;
    int di;
}Box;

typedef struct
{
    Box data[MaxSize];
    int top;
}StType

//迷宫算法

bool mgpath(int xi,int yi,int xe,int ye)
{
    Box path[MaxSize],e;
    int i,j,di,i1,j1,k;
    bool find;
    StType *st;
    InitStack(st);
    e.i=xi;
    e.j=yi;
    e.di=-1;
    Push(st,e);
    mg[xi][yi]=-1;

    while(!StackEmpty(st))
    {
        GetTop(st,e);
        i=e.i;
        j=e.j;
        di=e.di;
        if(i==xe&&j==ye)
        {
            cout<<"一条迷宫路径如下: "<<endl;
            k=0;
            while(!StackEmpty(st))
            {
                Pop(st,e);
                path[k++]=e;
            }
            while(k>=1)
            {
                k--;
                cout<<path[k].i<<" , "<<path[k].j;
                if((k+2)%5==0)
                {
                    cout<<endl;
                }

            }
            cout<<endl;
            DestroyStack(st);
            return true;
        }
        find=false;
        while(di<4&&!find)
        {
            di++
            switch(di)
            {
                case 0:i1=i-1;j1=j;break;
                case 1:i1=i;j1=j+1;break;
                case 2:i1=i+1;j1=j;break;
                case 3:i1=i;j1=j-1;break;
            }
            if(mg[i1][j1]==0)
            {
                find=true;
            }
        }
        if(find)
        {
            st->data[st->top].di=di;
            e.i=i1;
            e.j=j1;
            e.di=-1;
            Push(st,e);
            mg[i1][j1]=-1;
        }
        else
        {
            Pop(st,e);
            mg[e.i][e.j]=0;
        }
    }
    DestroyStack(st);
    return false;
}