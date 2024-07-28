#include "link_list.h"
#include "stdlib.h"
#include <stdio.h>

int main()
{
    node_p l = creat_linklist();
//    node_p last;
    visit_linklist(l);
//    l=delete_repeat_x(l,1);
//    visit_linklist(l);
//    last=find_last(l);
//    printf("最后一个元素为：%d",last->data);
//    printf("\n链表节点个数为：%d\n",count_node(l));
    l=inverted_linklist(l);
    visit_linklist(l);
//    node_p j = creat_linklist();
//    visit_linklist(l);
//    node_p N = creat_linklist();
//    visit_linklist(N);
//    j=meger_linklist(j,N);
//    visit_linklist(l);
//    free(j);
//    free(N);
}
