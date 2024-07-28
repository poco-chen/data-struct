#ifndef _LIBRARY_H
#define _LIBRARY_H
typedef int elemtype;

typedef struct LNode
{
    elemtype data;
    struct LNode * next;
}Node;
typedef Node* node_p;
node_p insert_link_list(node_p F,node_p N);
node_p creat_linklist(void);

void visit_linklist(node_p H);
node_p delete_repeat_x(node_p L,elemtype x);
node_p find_last(node_p L);
int count_node(node_p L);
node_p inverted_linklist(node_p L);
node_p meger_linklist(node_p des,node_p sor);

#endif //_LIBRARY_H
