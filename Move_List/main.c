#include <stdio.h>
#include "List.h"

int main(void) {

    int x;
    head * H=Create_list();
    scanf("%d",&x);
    while(x)
    {
        Add_node(H,x);
        scanf("%d",&x);
    }
    output(H);
    move_node(H);
    output(H);
    return 0;
}
