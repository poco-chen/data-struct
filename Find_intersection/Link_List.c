//
// Created by 陈宇轩 on 2024/7/27.
//

#include "Link_List.h"
#include "stdio.h"
#include "stdlib.h"
head * Create_list(void) {
    head *t = calloc(1, sizeof(*t));
    if (!t) {
        printf("内存分配失败！！！");
        return NULL;
    } else {
        t->len=0;
        return t;
    }
}
void Add_node(head * h,elemtype x)
{

    if(!h)
    {
        printf("链表不存在！！！");
        return;
    }
    node *t= calloc(1,sizeof(*t));
    t->data=x;
    t->next=NULL;

    if(h->len==0)
    {
        h->front=h->rear=t;
        h->len++;
        return;
    }

    node *p=h->front;
    node *q=NULL;

    while(p)
    {
        if(p->data > t->data)//找到位置了
        {
            if(p==h->front)//需要插入在第一个位置
            {
                t->next=p;
                h->front=t;
                h->len++;
                return;
            }
            else//插入在中间位置
            {
                q->next=t;
                t->next=p;
                h->len++;
                return;
            }
        }
        else//没找到位置就要向后移动
        {
            q=p;
            p=p->next;
        }
    }//没有找到合适位置就使用尾插法
    h->rear->next=t;
    h->rear=t;
    h->len++;
}
void output(head * h)
{
    if(!h||!h->front)
    {
        printf("NULL");
        return;
    }
    node *p=h->front;
    printf("链表长度为%d\n",h->len);
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
head *find_intersection(head *a,head *b)
{
    head *h= Create_list();

    if(!a||!b)
    {
        return h;
    }
    node *p=a->front,*q=b->front;
    while(q&&p)
    {
        if(p->data==q->data)
        {
            Add_node(h,p->data);
            p=p->next;
            q=q->next;
        }
        else if(p->data<q->data)//谁小谁移动
        {
            p=p->next;
        }
        else
        {
            q=q->next;
        }
    }
    return h;
}