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

//销毁

//遍历输出

//判断空

//求长度

//得到栈首元素

//入栈

//出栈

//遍历输出

