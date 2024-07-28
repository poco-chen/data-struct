//
// Created by 陈宇轩 on 2024/7/20.
//
#include<stdio.h>
#define maxsize 1000

typedef struct static_list
{
    int data;
    int cur;
}s_list;

void Initlist(s_list *A);

int Malloc_s_list(s_list *);

void s_list_insert(s_list *A,int i,int elemval);

void s_list_delete(s_list *A,int i);

int len_s_list(s_list *A);

void Free_s_list(s_list *A,int k);

int main()
{
    s_list a[maxsize];
    return 0;
}


void Initlist(s_list *A)
{
    int i;
    for(i=0;i<=maxsize-1;i++)
    {
        A[i].cur=i+1;
    }
    A[maxsize-1].cur=0;
}
int Malloc_s_list(s_list *A)
{
    int j=A[0].cur;
    if(A[0].cur)//如果空闲区还有//tip如果没有空闲区则A[0].cur==0
    {
        A[0].cur=A[j].cur;
    }
    return j;
}
void s_list_insert(s_list *A,int i,int elemval)
{
    int j,k=maxsize-1,l;
    if(i<1||i>maxsize-1)
    {
        printf("插入位置不合法");
        return ;
    }
    j= Malloc_s_list(A);
    if(j)//空闲区有位置
    {
        A[j].data=elemval;
        for(l=1;l<=i-1;l++)
            k=A[k].cur;
        A[j].cur=A[k].cur;
        A[k].cur=j;
    }
}

