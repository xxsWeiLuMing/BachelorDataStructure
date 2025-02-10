#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

#define  STACK_INIT_SIZE   100 
#define  STACKINCREMENT  10 

typedef char SElemType;

typedef  struct  SLNode {
    SElemType   data;
    struct SLNode* next;
} SLNode, * SLinkList;

//初始化

//销毁

//遍历输出

//判断空

//求长度

//得到栈首元素

//入栈

//出栈

//清空栈
