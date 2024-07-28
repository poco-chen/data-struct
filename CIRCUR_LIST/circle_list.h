//
// Created by 陈宇轩 on 2024/7/26.
//

#ifndef CIRCUR_LIST_CIRCLE_LIST_H
#define CIRCUR_LIST_CIRCLE_LIST_H
typedef int elemtype;

typedef struct C_node
{
    struct C_node *pre;
    elemtype data;
    struct C_node *next;
}C_node;

typedef struct head
{
    struct C_node *front;
    int len;
    struct  C_node *rear;
}head;

typedef C_node * node_p;
typedef head * head_p;

head_p Create_CIR_LIST(void);
void Add_node(head_p ,elemtype );
void Delete_x(head_p,elemtype );
void Delete_All_x(head_p,elemtype);
void distroy_list(head_p);
void print_list(head_p);



#endif //CIRCUR_LIST_CIRCLE_LIST_H
