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
    t->next=NULL;
    if(h->len==0)
    {
        h->front=h->rear=t;
        h->len++;
    }
    node *p=h->front;
    node *q=NULL;
    while(p)
    {
        if(t->data<p->data)
        {
            if(p==h->front)
            //头插法
            {
                t->next=h->front;
                h->front=t;
                h->len++;
                return;
            }
            else
            {
                t->next=p;
                q->next=t;
                h->len++;
                return;
            }
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    h->rear=t;
    h->rear=t;
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