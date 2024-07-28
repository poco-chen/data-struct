
#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"



node_p creat_linklist(void)
{
  elemtype n;
  scanf("%d",&n);
  node_p F =NULL;
  while(n!=0)
  {

      node_p t=calloc(1,sizeof(*t));
      t->data=n;
      t->next=NULL;
      if(!F)
      {
          F=t;
      }
      else
        F=insert_link_list(F,t);
      scanf("%d",&n);
  }
  return F;
}
node_p insert_link_list(node_p F,node_p t)
{
    int flag=0;//插入位置在中间的标志
    node_p ret=F;
    if(t->data < F->data)//插入在第一个节点
    {
        t->next=F;
        F=t;
        ret=F;
    }
    else
    {
        while(F->next!=NULL)//中间找到插入位置
        {
            if(t->data < F->next->data)
            {
                flag=1;
                t->next=F->next;
                F->next=t;
                break;
            }
            F=F->next;
        }
        if(flag==0)
        {
            F->next=t;
        }
    }

    return ret;
}

void visit_linklist(node_p H)
{
    node_p t=H;
    if(!t)
    {
        printf("NULL");
    }
    while(t)
    {
        printf("%3d",t->data);
        t=t->next;
    }
    printf("\n");
}
node_p delete_repeat_x(node_p L,elemtype x)
{
    node_p p,pr,q;//pr指向p->next;
    if(!L)
    {
        printf("链表为空");
        return NULL;
    }
    p=L;pr=L->next;

    while(p->next)
    {
        pr=p->next;
        if(p==L&&p->data==x)//删除第一个节点
        {
            L=L->next;
            free(p);
            p=L;
            pr=p->next;
            continue;
        }
        if(pr->data==x)
        {
            p->next=pr->next;
            free(pr);
        }
        else
            p=p->next;
    }
    return L;
}
node_p find_last(node_p L)
{
    node_p p=L;
    while(p->next)
    {
        p=p->next;
    }
    return p;
}
int count_node(node_p L)
{
    node_p p=L;
    int count=1;
    while(p->next)
    {
        p=p->next;
        count++;
    }
    return count;
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
//    node_p head=L,rear,stop;
//    while(head->next)
//    {
//        head = head->next;
//    }//找到尾指针
//
//    rear=head;//rear指向链表尾部
//    head=L;//head指向链表头部
//
//    while(head!=rear)
//    {
//        L=L->next;
//        head->next=rear->next;
//        rear->next=head;
//        head=L;
//    }
//    return L;
//}
node_p meger_linklist(node_p des,node_p sor)
{
    node_p t=sor;
    node_p p;
    while(t)
    {
        p=t;
        t=t->next;
        p->next=NULL;
        des=insert_link_list(des,p);

    }
    return des;
}
//1 3 5 7 9 0
//2 4 6 8 10 0