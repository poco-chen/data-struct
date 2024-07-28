#include <stdio.h>
#include "circle_list.h"
int main(void)
{
    elemtype in;
    head_p L=Create_CIR_LIST();
    scanf("%d",&in);
    while(in) {
        Add_node(L, in);
        scanf("%d", &in);
    }
    print_list(L);
    printf("请输入你要删除的元素：");
    fflush(stdout);
    int d;
    scanf("%d",&d);
    Delete_x(L,d);
    print_list(L);
    return 0;
}
