//
// Created by 陈宇轩 on 2024/7/27.
//

#ifndef FIND_SUB_LINKLIST_H
#define FIND_SUB_LINKLIST_H
typedef int elemtype;

typedef struct node
{
    elemtype data;
    struct  node *next;
}node;

typedef struct head
{
    node *front;
    int len ;
    node *rear;
}head;

head * Create_list(void);
void Add_node(head * h,elemtype x);
void output(head * h);
node * find_sub(head *m,head *n);

#endif //FIND_SUB_LINKLIST_H
