#include <stdio.h>
#include "Link_List.h"
int main(void)
{
    int x;
    head * H=Create_list();
    scanf("%d",&x);
    while(x)
    {
        Add_node(H,x);
        scanf("%d",&x);
    }
    output(H);
}
