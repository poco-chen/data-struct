#include <stdio.h>
#include "doubly_list.h"
#include "stdlib.h"

int main(void)
{
    elemtype x,d;
    scanf("%d",&x);
    head_p H=Create_list();
    while(x)
    {
        Add_Node(H,x);
        scanf("%d",&x);
    }
    output(H);
    printf("请输入你要删除的元素：");
    fflush(stdout);
    scanf("%d",&d);
//    delete_x(H,d);
    delete_All_x(H,d);
    output(H);
    distroy_list(H);
//    free(H);

}
