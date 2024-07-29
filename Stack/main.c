#include <stdio.h>
#include "stack.h"
int main(void)
{
    elemtype x,d,t;
    stack *S= InitStack();
    if(StackIsEmpty(S))
        printf("栈为空\n");
    scanf("%d",&x);
    while(x)
    {
        push(S,x);
        scanf("%d",&x);
    }
    printf("栈的长度为：%d\n",StachLength(S));
    Get_top(S,&d);
    printf("%d\n",d);
    pop(S,&t);
    printf("%d\n",t);
    clearStack(S);
    distroy_Stack(S);
    return 0;
}
