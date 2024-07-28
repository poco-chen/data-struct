#include <stdio.h>
#include "LINKLIST.h"
#include "stdlib.h"
#include "time.h"
int main(void)
{
    int a,b,i=0;
    srand(time(0));
    a=rand()%1000;
    b=rand()%100-50;

    //随机生成两个-1000~1000范围内的整数
    head *m=storage_int(a);
    head *n=storage_int(b);
    print_LINK_LIST(m->front);
    printf(" ");
    print_LINK_LIST(n->front);
    printf("\n");
    printf("两个整数为%d %d",a,b);
    printf("\n");
    printf("两个整数相加结果为：%d",Add_int(m,n));
}
