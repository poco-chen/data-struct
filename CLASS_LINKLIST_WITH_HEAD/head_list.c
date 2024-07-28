//
// Created by 陈宇轩 on 2024/7/25.
//
#include<stdio.h>
#include "head_list.h"
#include<stdlib.h>
head_p Create_Head(void)//创建链表
{
    head_p H=calloc(1,sizeof(*H));
    H->rear=NULL;
    H->frist=NULL;
    H->len=0;
    return H;
}

void Add_Node(head_p L,elemtype x)//在链表中增加元素
{
    node_p t=NULL;
    node_p p,pr;
    t=calloc(1,sizeof(*t));
    t->data=x;
    t->next=NULL;
    if(!L->frist)//链表中没有元素
    {
        L->frist=t;
        L->rear=t;
        L->len++;
        return;
    }
    else//链表中有元素
    {
        if(t->data < L->frist->data)//插入在第一个位置
        {
            t->next=L->frist;
            L->frist=t;
            L->len++;
            return;
        }
        p=L->frist;
        pr=p->next;
        while(pr)
        {
            if(pr->data > t->data)//中间插入
            {
                t->next=pr;
                p->next=t;
                L->len++;
                return;
            }
            p=p->next;
            pr=p->next;
        }
        p->next=t;
        L->rear=t;
        L->len++;
        return;

    }

}

void output_LINK_LIST(head_p L)
{
    node_p x=L->frist;
    if(!x)
    {
        printf("链表为空\n");
        printf("链表长度：%d\n",L->len);
        return;
    }
    printf("链表长度：%d\n",L->len);
    while(x)
    {
        printf("%3d",x->data);

        x=x->next;
    }
    printf("\n");
}


void Delete_x(head_p H,elemtype x)
{
    node_p pr=NULL,p=NULL;
    if(!H||!H->frist)
    {
        printf("链表为空不需要删除");
        return;
    }
    pr=H->frist;
    while(pr->next)
    {
        if(pr->data==x)
        {
            break;
        }
        p=pr;
        pr=pr->next;
    }

   if(p==NULL)//第一个节点等待删除
   {
       H->frist=pr->next;
       H->len--;
       free(pr);
   }
   else if(pr==H->rear)
   {
       return;
   }
   else
   {
       p->next=pr->next;
       free(pr);
       return;
   }



}


void Delette_All_x(head_p l,elemtype x)
{
    if(!l||!l->frist)
    {
        return;
    }
    node_p pr=l->frist;
    node_p p=NULL;
    if(l->len==1)
    {
        free(pr);
        l->frist=l->rear=NULL;
        l->len=0;
    }
    else{
    while(pr)
    {

        if(pr->data==x)
        {
            if(pr==l->frist)//第一个节点
            {
                l->frist=l->frist->next;
                free(pr);
                pr=l->frist;
                l->len--;
                continue;
            }
            else if(pr==l->rear)
            {
                if(l->len==1)
                {
                    l->frist=l->rear=NULL;
                    free(pr);
                    l->len=0;
                }
                else
                {
                    p->next=NULL;
                    l->rear=p;
                    free(pr);
                    l->len--;
                }
                return;
            }
            else
            {
                p->next=pr->next;
                free(pr);
                pr=p->next;
                l->len--;
                continue;
            }
        }
        p=pr;
        pr=pr->next;
    }
}
}


void disstroy_linklist(head_p l)
{
    node_p pr=l->frist;
    while(l->frist)
    {
        l->frist=l->frist->next;
        free(pr);
        pr=l->frist;
        l->len--;
        if(pr==l->rear)
        {
            l->frist=l->rear=NULL;
            free(pr);
            l->len--;
            break;
        }
    }
    if(!l->frist)
        printf("distroied!");
    free(l);




}