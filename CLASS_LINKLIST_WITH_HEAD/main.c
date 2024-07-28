#include "head_list.h"
#include<stdio.h>
#include <stdlib.h>
int main()
{
    head_p H=Create_Head();

    int x,d;
    scanf("%d",&x);
    while(x)
    {
        Add_Node(H,x);
        scanf("%d",&x);
    }
//    output_LINK_LIST(H);
//    Delete_x(H,2);
    output_LINK_LIST(H);
    printf("请输入要删除哪一个节点");
    fflush(stdout);
    scanf("%d",&d);
    Delette_All_x(H,d);
    output_LINK_LIST(H);
    disstroy_linklist(H);
    return 0;
}
