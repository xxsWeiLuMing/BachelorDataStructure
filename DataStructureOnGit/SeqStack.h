#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

#define  STACK_INIT_SIZE   100 
#define  STACKINCREMENT  10 

typedef char SElemType;

typedef  struct {
    SElemType* base;
    SElemType* top;
    int   stacksize;
} SqStack;//顺序栈

//初始化
Status InitStack(SqStack& S)
{
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

//销毁
Status DestroyStack(SqStack& S)
{
    free(S.base);
    S.base = S.top = NULL;
    S.stacksize = 0;
    return OK;
}

//遍历输出
Status TraverseStack(SqStack S)
{
    if (!S.base) return ERROR;
    if (S.top == S.base) return ERROR;
    SElemType* p = S.base;
    while (p < S.top)
    {
        cout << *p << " ";
        p++;
    }
    return OK;
}

//判断空
Status IsStackEmpty(SqStack S)
{
    if (!S.base) return ERROR;
    return S.top == S.base;
}

//求长度
int StackLength(SqStack S)
{
    if (!S.base) return ERROR;
    return S.top - S.base;
}

//得到栈首元素
Status GetTop(SqStack S, SElemType& e)
{
    if (!S.base) return ERROR;
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

//入栈
Status Push(SqStack& S, SElemType e)
{
    if (!S.base) return ERROR;
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}

//出栈
Status Pop(SqStack& S, SElemType& e)
{
    if (!S.base) return ERROR;
    if (S.top == S.base) return ERROR;
    e = *(--S.top);
    return OK;
}

//清空栈
Status ClearStack(SqStack& S)
{
    if (!S.base) return ERROR;
    S.top = S.base;
    return OK;
}
