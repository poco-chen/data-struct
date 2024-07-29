//
// Created by 陈宇轩 on 2024/7/29.
//
#include<stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "stack.h"
stack * InitStack(void)
{
    stack * S= calloc(1,sizeof(*S));
    S->data= calloc(1,sizeof(elemtype)*100);
    S->len=0;
    S->top=-1;
    S->bottom=0;
    return S;
}
void distroy_Stack(stack * s)
{
    if(!s)
    {
        printf("栈不存在！！！");
        return;
    }
    if(!s->data)
    {
        free(s);
    }
    else
    {
        free(s->data);
        free(s);
    }
}
void clearStack(stack *s)
{
    if(!s||!s->data||s->top==s->bottom)
    {
        printf("STACK NULL！！！");
        return;
    }
    s->top=s->bottom;
    s->len=0;
}
bool StackIsEmpty(stack *s)
{
    if(!s||!s->data||s->len==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int StachLength(stack *s)
{
    if(StackIsEmpty(s))
    {
        return 0;
    }
    else
    {
        return s->len;
    }

}
int  Get_top(stack *s,elemtype *x)
{
    if(StackIsEmpty(s))
    {
        return 0;
    }
    else
    {
        *x=s->data[s->top];
        return 1;
    }
}
int pop(stack *s,elemtype *x)
{
    if(StackIsEmpty(s))
    {
        return 0;
    }
    else
    {
        *x=s->data[(s->top)--];
        s->len--;
        return 1;
    }
}
int push(stack *s,elemtype x)
{
    if(!s)
    {
        return 0;
    }
    s->top++;
    s->data[s->top]=x;

    s->len++;
    return 1;
}
