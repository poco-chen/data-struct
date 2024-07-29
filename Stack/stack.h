//
// Created by 陈宇轩 on 2024/7/29.
//
#include "stdbool.h"
#ifndef STACK_STACK_H
#define STACK_STACK_H
typedef int elemtype;

typedef struct stack
{
    elemtype *data;
    int top;
    int bottom;
    int len;
}stack;
stack * InitStack(void);//1
void clearStack(stack *);
bool StackIsEmpty(stack *);//2
int StachLength(stack *);//3
int  Get_top(stack *,elemtype *x);//
int pop(stack *s,elemtype *x);//
int push(stack *,elemtype );//4
void distroy_Stack(stack *s);
#endif //STACK_STACK_H
