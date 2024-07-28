//
// Created by 陈宇轩 on 2024/7/27.
//

#include "List.h"
#include "stdlib.h"
#include "stdio.h"
head * Create_list(void) {
    head *t = calloc(1, sizeof(*t));
    if (!t) {
        printf("内存分配失败！！！");
        return NULL;
    } else {
        return t;
    }
}
void Add_node(head * h,elemtype x)//尾插法
{
    if(!h)
    {
        printf("链表不存在！！！");
        return;
    }
    node *t= calloc(1,sizeof(*t));
    t->data=x;
    if(h->len==0)
    {
        h->front=h->rear=t;
        h->len++;
    }
    else//尾插法
    {
        h->rear->next=t;
        h->rear=t;
        h->len++;
        return;
    }
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
void move_node(head *h)
{
    node *temp_h=h->front->next;
    h->rear=h->front;
     node *p=NULL;
    while(temp_h)
    {
        p=temp_h;
        temp_h=temp_h->next;
        if(p->data<0)//小于0用头插法
        {
            p->next=NULL;
            p->next=h->front;
            h->front=p;
        }
        else//小于0用尾插法
        {
            p->next=NULL;
            h->rear->next=p;
            h->rear=p;
        }
    }
}