#include <stdio.h>
#include"linklist.h"
int main(void)
{
    elemtype x;
    head * H=Create_list();
    scanf("%d",&x);
    while(x)
    {
        Add_node(H,x);
        scanf("%d",&x);
    }
   output(H);
    elemtype y;
    head * L=Create_list();
    scanf("%d",&y);
    while(y)
    {
        Add_node(L,y);
        scanf("%d",&y);
    }
    output(L);

    node * first=find_sub(H,L);
    if(first==NULL)
        printf("NO Match!!!!");
    else
        printf("%d",first->data);
}
