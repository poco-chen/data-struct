//
// Created by 陈宇轩 on 2024/7/27.
//

#ifndef MOVE_LIST_LIST_H
#define MOVE_LIST_LIST_H

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
void move_node(head *h);
#endif //MOVE_LIST_LIST_H
