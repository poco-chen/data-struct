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
    int d;
    head * L=Create_list();
    scanf("%d",&d);
    while(d)
    {
        Add_node(L,d);
        scanf("%d",&d);
    }
    output(H);
    output(L);
    head *ans=find_intersection(H,L);
    if(!ans )
        printf("这两个链表没有交交集");
    else
        output(ans);
}
