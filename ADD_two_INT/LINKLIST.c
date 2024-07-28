//
// Created by 陈宇轩 on 2024/7/26.
//
#include<stdio.h>
#include "stdlib.h"
#include "LINKLIST.h"
#include "math.h"
void Add_node(head *h,int x )//使用尾插法插入节点元素
{
    if(!h)
    {
        printf("链表不存在");
        return;
    }
    node *t=calloc(1,sizeof(*h));
    t->data=x;
    t->next=NULL;
    //插入
    if(h->len==0)//插入的是第一个元素
    {
        h->front=h->rear=t;
        h->len++;
    }
    else
    {
        h->rear->next=t;
        h->rear=t;
    }
}

void print_LINK_LIST(node * l)//递归逆序打印
{
    if(!l)
        return;
    print_LINK_LIST(l->next);
    printf("%d",l->data);
}

/*函数功能：将一个整型数据一位位存储在带头节点的链表中
 * 函数参数 ：@ int x需要存储的整数
 * 函数返回值：返回存储该整数的链表的头节点
 */
//其中存储分为两个步骤step1从整数中取出它的每一位
//step2把他的每一位存储到链表中去（使用头插法）

head* storage_int(int x)//存储
{
    //判断符号位

    int t;//定义一个整型来接受该整数的每一位
    head *h= calloc(1,sizeof(*h));//定义一个头结点然后创建单链表
    if(x<0)
        h->sign='-';
    x=abs(x);
    while(x)
    {
        t=x%10;
        Add_node(h,t);
        x/=10;
    }
    return h;
}

int Add_int(head *a,head *b)//相加
{
    int p=obtain_list( a);
    int q=obtain_list(b);
    return p+q;
}
int obtain_list(head *l)//取数
{
    int num=1,ans=0;;
    node *p=l->front;
    while(p)
    {
        ans=ans+(p->data)*(num);
        num=num*10;
        p=p->next;
    }
    if(l->sign=='-')
    {
        return -ans;
    }
    else
    {
        return ans;
    }
}