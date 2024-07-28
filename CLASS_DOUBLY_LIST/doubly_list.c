//
// Created by 陈宇轩 on 2024/7/25.
//
#include "doubly_list.h"
#include<stdlib.h>
#include "stdio.h"
head_p Create_list(void)
{
    head_p H=calloc(1,sizeof (*H));
    if(!H)
    {
        printf("内存分配失败");
        return NULL;
    }
    H->len=0;H->rear=NULL;
    H->front=NULL;
    return H;
}


void Add_Node(head_p L,elemtype x )
{
    node_p t= calloc(1,sizeof(*t));
    t->data=x;t->next=t->pre=NULL;//创建插入元素节点

    node_p p=L->front;
    if(L->len==0)//插入的元素为第一个
    {
        L->front=L->rear=t;
        L->len++;
        return;
    }
    while(p)//遍历查找位置
    {
        if(t->data < p->data)
        {
            if(!p->pre)//第一个位置
            {
                t->next=p;
                t->pre=p->pre;
                p->pre=t;
                L->front=t;
                L->len++;
                return;
            }
            else//中间位置
            {
                t->next=p;
                t->pre=p->pre;
                p->pre->next=t;
                p->pre=t;
                L->len++;
                return;
            }
        }
        p=p->next;//没找到就往后移动
    }
    //循环结束意味着t->data大于整链表中的所有元素data
    //即插入到最末尾端
    t->next=L->rear->next;
    L->rear->next=t;
    t->pre=L->rear;
    L->rear=t;
    L->len++;
    return;
}

void delete_x(head_p L,elemtype x)
{
    if(!L||!L->front)
    {
        printf("链表不存在或链表为空删除失败");
        return;
    }

    node_p l=L->front,n;
    if(L->len==1&&L->front->data==x)
    {
        n=L->front;
        L->front=L->rear=NULL;
        free(n);
        return;
    }
    while(l)
    {
        if(l->data==x)
        {
            if(!l->pre)
            {
                L->front=L->front->next;
                free(l);
                l=L->front;
                L->len--;
                return ;
            }
            else if(!l->next)
            {
                L->rear=l->pre;
                l->pre->next=l->next;
                free(l);
                L->len--;
                return;
            }
            else
            {
                n=l;l=l->next;
                n->pre->next=n->next;
                n->next->pre=n->pre;
                free(n);
                return;
            }
        }
        l=l->next;
    }
}
void delete_All_x(head_p L,elemtype x)
{
    if(!L||!L->front)
    {
        printf("链表为空或链表不存在，删除失败");
        return;
    }
    node_p l=L->front,n;
    if(L->len==1&&L->front->data==x)
    {
        n=L->front;
        L->front=L->rear=NULL;
        free(n);
        printf("删除成功但链表为空\n");
        return;
    }
    while(l)
    {
        if(l->data==x)//找到要删除的位置
        {
            if(!l->pre)//找到了但是位置是第一个(bug)
            {
                n=l;
                l=l->next;
                L->front=l;
                l->pre=NULL;
                L->len--;
                free(n);
                continue;
            }
            else if(!l->next)//找到了但是位置在最后一个
            {
                L->rear=l->pre;
                l->pre->next=l->next;
                free(l);
                L->len--;
                return;
            }
            else//删除位置在中间
            {
                n=l;l=l->next;
                n->pre->next=n->next;
                n->next->pre=n->pre;
                free(n);
                L->len--;
                continue;
            }
        }
        else//没找到就需要移动l
        {
            l=l->next;
        }
    }
}
void distroy_list(head_p L)
{

    if(!L)
    {
        free(L);
        return;
    }
    node_p l=L->front,n;
    while(l->next!=NULL)
    {
        n=l;
        l=l->next;
        L->front=l;
        l->pre=NULL;
        free(n);
        L->len--;
    }
    n=L->front;
    free(n);
    L->len--;
    L->front=L->rear=NULL;
    free(L);
}
void output(head_p L)
{
    if(!L||!L->front)
    {
        printf("链表为空或链表不存在，请检查传递参数！！！\n");
        return;
    }
    node_p t=L->front;
    printf("链表长度为%d\n",L->len);
    printf("链表元素为：");
    while(t)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
node_p inverted_linklist(node_p L)//逆置一个单链表
{
    if (!L->next)
    {
        return L;
    }
    node_p f = inverted_linklist(L->next);
    L->next->next = L;
    L->next = NULL;
    return f;
}


