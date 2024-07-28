#ifndef LINKLIST_LINK_LIST_H
#define LINKLIST_LINK_LIST_H

typedef struct Node
{
    int val;
    struct Node * next;
}LNode;
typedef  struct Node* Linklist;//定义链表指针类型叫做Linklist
void Creat_Linklist(Linklist *L,int n);//创建链表
void visit_linklist(Linklist *L,int n);//访问链表
void Insert_linklist(Linklist *L,int i,int val);//在指定位置插入元素
void rivise_linkllist(Linklist * L ,int i,int val );//修改了链表中指定位置元素
void delete_linklist(Linklist * L ,int i);//删除链表中指定位置元素
int find_index(Linklist *L,int elem);//查找指定元素并返回该元素的下标索引
void clear_Linklist(Linklist * L);

#endif //LINKLIST_LINK_LIST_H
