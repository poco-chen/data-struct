//
// Created by 陈宇轩 on 2024/7/27.
//

#include "linklist.h"
#include<stdlib.h>
#include "stdio.h"
head * Create_list(void)
{
    head *t= calloc(1,sizeof(*t));
    if(!t)
    {
        printf("内存分配失败！！！");
        return NULL;
    }
    else
    {
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
node * find_sub(head *m,head *n)
{//返回子串第一个节点
    if(!m||!n||!m->front||!n->front)
    {
        printf("NULL!!NO FIND!!!");
        return NULL;
    }
    node *p=(m->len>n->len?m->front:n->front);
    node *q=(m->len<n->len?m->front:n->front);
    node *first=NULL;
    node *t=q;
    int index=1;
    while(p)
    {
        if(p->data==t->data)//第一个匹配上了
        {

            first=p;//保留第一个节点位置
            do {
                p=p->next;
                t=t->next;
            }while(t&&p->data==t->data);//只要短的串存在且两个元素相等就往后走
            //循环结束有两种情况一种是t为空即子串匹配
            if(!t)
            {
                printf("子串第一个元素的index(从0开始计算)：%d\n",index);
                return first;
            }
            //另外一种就是中途子串不匹配则需要回溯
            else
            {
                p=first->next;
                t=q;
            }
        }
        else
        {
            p=p->next;
            index++;
        }
    }
    //循环结束没找到就是没匹配上
    printf("NO match！！！");
    return NULL;
}
//node *find_sub(head *m, head *n) {
//    if (!m || !n || !m->front || !n->front || m->len < n->len) {
//        printf("NULL!!NO FIND!!!\n");
//        return NULL;
//    }
//
//    node *p = m->front;
//    node *q = n->front;
//    node *first = NULL;
//    node *t = q;
//    int index = 0;
//
//    while (p) {
//        if (p->data == t->data) {
//            first = p;  // 保留第一个匹配节点位置
//            node *tempP = p;
//            node *tempT = t;
//            while (tempT && tempP && tempP->data == tempT->data) {
//                tempP = tempP->next;
//                tempT = tempT->next;
//            }
//            if (!tempT) {  // 如果 t 到达末尾，则匹配成功
//                printf("子串第一个元素的index(从0开始计算)：%d\n", index);
//                return first;
//            }
//            // 如果不匹配，重置 p 和 t
//            p = first->next;
//            t = q;
//        } else {
//            p = p->next;
//            index++;
//        }
//    }
//
//    printf("NO match!!!\n");
//    return NULL;
//}