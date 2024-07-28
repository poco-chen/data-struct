//
// Created by 陈宇轩 on 2024/7/18.
//
#include "Link_List.h"
#include "stdlib.h"
#include<stdio.h>
int main(int argc,int **argv )
{
    int elem;
    Linklist *A=(Linklist *)malloc(sizeof(Linklist *));
    Creat_Linklist(A,5);
    visit_linklist(A,5);
    Insert_linklist(A,3,100);
    visit_linklist(A,6);
    rivise_linkllist(A,3,-10);
    visit_linklist(A,6);
    delete_linklist(A ,3);
    visit_linklist(A,5);
    fflush(stdout);
    scanf("%d",&elem);
    printf("%d",find_index(A,elem));
    clear_Linklist(A);
    printf("\n%d",(*A)->val);
    free(A);
    return 0;


}
