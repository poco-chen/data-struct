//
// Created by 陈宇轩 on 2024/7/25.
//

#ifndef CLASS_DOUBLY_LIST_DOUBLY_LIST_H
#define CLASS_DOUBLY_LIST_DOUBLY_LIST_H
typedef  int elemtype;

typedef struct DOUBLE_NODE//节点类型
{
    elemtype data;
    struct DOUBLE_NODE *next;
    struct DOUBLE_NODE *pre;
}D_node;

typedef struct head_node
{
    int len;
    D_node * front;
    D_node *rear;
}H_node;

typedef D_node * node_p;
typedef H_node * head_p;

head_p Create_list(void);
void Add_Node(head_p ,elemtype );
void delete_x(head_p,elemtype );
void delete_All_x(head_p,elemtype);
void output(head_p L);
void distroy_list(head_p L);






#endif //CLASS_DOUBLY_LIST_DOUBLY_LIST_H
