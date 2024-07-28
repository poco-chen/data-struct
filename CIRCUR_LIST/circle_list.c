//
// Created by 陈宇轩 on 2024/7/26.
//

#include "circle_list.h"
#include "stdio.h"
#include "stdlib.h"

head_p Create_CIR_LIST(void)
{
    head_p H= calloc(1,sizeof(*H));
    H->rear=H->front=NULL;
    H->len=0;
    return H;
}
void Add_node(head_p l,elemtype x)
{
    node_p t= calloc(1,sizeof (*t));
    t->data=x;t->pre=t->next=NULL;//创建一个带插入元素的节点类型

    if(l->len==0)//插入的元素是第一
    {
        l->front=l->rear=t;
        t->pre=t;
        t->next=t;
        l->len++;
        return ;
    }

    node_p p=l->front;
    int flag=0;

    while(p->next!=l->front)//找插入位置
    {
        flag=1;
        if(p->data>t->data)//找到插入位置
        {
            if(p==l->front)//插入在前面//头插法
            {
               l->front->pre=t;
                t->next=l->front;
                t->pre=l->rear;
                l->front=t;
                l->rear->next=l->front;
                l->len++;
                return;
            }
            else//插入在中间位置//中间插入
            {
                t->next=p;t->pre=p->pre;
                t->pre->next=t;
                t->next->pre=t;
                l->len++;
                return;
            }
        }
          //p不符合插入要求//p需要移动
          p=p->next;
    }
    if((flag==0&&l->front->data<t->data)||flag==1)
    {//循环结束就代表插入位置在最后//实现尾插法if(flag=1)
        l->rear=t;
        p->next=t;
        t->pre=p;
        t->next=l->front;
        l->front->pre=t;
        l->rear=t;
        l->len++;
        return;
    }
    if(flag==0&&l->front->data>t->data)//flag=0//头插法
    {
        l->front->pre=t;
        t->next=l->front;
        t->pre=l->rear;
        l->front=t;
        l->rear->next=l->front;
        l->len++;
        return;
    }
}
void Delete_x(head_p l,elemtype x)
{
    node_p n;


    if(!l||!l->front)
    {
        printf("链表不存在或者链表元素为空");
        return;
    }
    node_p p=l->front;
    if(l->len==1)
    {
        n=l->front;
        n->next=n->pre=NULL;
        l->front=l->rear=NULL;
        free(n);
        return;
    }

    int count=0;
    while(p->next!=l->front)
    {
        count++;
        if(p->data==x)//找到要删除的元素
        {
            if(p==l->front)//要删除第一个元素
            {
                l->front=l->front->next;
                l->front->pre=l->rear;
                l->rear->next=l->front;
                free(p);
                l->len--;
                return;
            }
            else//删除中间元素
            {
                n=p;
                p->pre->next=p->next;
                p->next->pre=p->pre;
                p=p->next;
                free(n);
                l->len--;
                return;
            }
        }
        else//移动p
        {
            p=p->next;
        }
    }
    if(l->rear->data==x)
    {
        n=l->rear;
        l->rear=l->rear->pre;
        l->rear->next=l->front;
        l->front->pre=l->rear;
        l->len--;
        free(n);
        return;
    }
    printf("没有找到该元素");
    return;
}
void Delete_All_x(head_p l,elemtype x)
{}
void distroy_list(head_p l)
{}
void print_list(head_p H)
{
    if(!H||!H->front)
    {
        printf("链表为空或链表不存在");
        return ;
    }
    node_p p=H->front;
    printf("链表节点个数为%d\n",H->len);
    do {
            printf("%d ",p->data);
            p=p->next;
        }while(p!=H->front);
    printf("\n");
    p=H->rear;
    do {
        printf("%d ",p->data);
        p=p->pre;
    }while(p!=H->rear);
    printf("\n");
}