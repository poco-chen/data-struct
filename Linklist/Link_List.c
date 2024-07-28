#include "Link_List.h"
#include<time.h>
#include <stdio.h>
#include<stdlib.h>
void Creat_Linklist (Linklist *L,int n)//创建链表
/*
 * Creat_Linklist：创建链表函数
 * @Linklist L：传入头指针
 * @int n：链表元素个数
 */
{
    int i;
    Linklist p;
    srand(time(0));
    *L=(Linklist)malloc(sizeof (LNode));
    (*L)->next=NULL;
    (*L)->val=-1;
    for(i=0;i<n;i++)
    {
        p= (Linklist)malloc(sizeof(Linklist));
        p->val=rand()%10+1;
        p->next=(*L)->next;
        (*L)->next=p;
    }
}

void visit_linklist(Linklist *L,int n)//访问链表
/*函数功能：访问链表中的每一个元素
 * @传入链表头节点指针
 */
{
    Linklist p=(*L)->next;
    int i=1;
    while(i<=n)
    {
        printf("%3d ",p->val);
        p=p->next;
        i++;
    }
    printf("\n");
}

void Insert_linklist(Linklist *L,int i,int val)//在指定位置插入元素
/*链表插入元素
*
*/
{
    int num=1;
    Linklist s=(Linklist)malloc(sizeof(Linklist)),p=(*L)->next;
    s->val=val;
    s->next=NULL;
    while(num<i-1)
    {
        p=p->next;
        num++;
    }
    s->next=p->next;
    p->next=s;
}

void rivise_linkllist(Linklist * L ,int i,int val )//修改链表元素
{
    Linklist p=(*L)->next;
    int n=1;
    while(n<i)
    {
        p=p->next;
        n++;
    }
    p->val=val;
}

void delete_linklist(Linklist * L ,int i)
{
    Linklist p=(*L)->next,tep;
    int n=1;
    while(n<i-1)
    {
        p=p->next;
        n++;
    }
    tep=p->next;
    p->next=p->next->next;
    free(tep);
}

int find_index(Linklist *L,int elem)
{
    Linklist p=(*L)->next;
    int num=1,flag=0;
    while(p)
    {
        if(p->val==elem)
        {
            flag=1;
            return num;

        }
        num++;
        p=p->next;
    }
    if(flag==0)
    {
        printf("没有找到该元素！！");
        return 0;
    }
}

void clear_Linklist(Linklist * L)
{
    Linklist p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
}
