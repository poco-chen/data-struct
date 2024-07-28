#ifndef CLASS_LINKLIST_WITH_HEAD_HEAD_LIST_H
#define CLASS_LINKLIST_WITH_HEAD_HEAD_LIST_H
typedef int elemtype;
typedef struct Node
{
    elemtype data;
    struct Node * next;
}node;
typedef node* node_p;

typedef struct head_NODE
{
    node * frist;
    node *rear;
    int len;
}head;
typedef head* head_p;//定义一种类型头节点指针类型

head_p Create_Head(void);

void Add_Node(head_p L,elemtype x);

void output_LINK_LIST(head_p L);
void Delete_x(head_p H,elemtype x);
void Delette_All_x(head_p l,elemtype x);
void disstroy_linklist(head_p );

#endif //CLASS_LINKLIST_WITH_HEAD_HEAD_LIST_H
