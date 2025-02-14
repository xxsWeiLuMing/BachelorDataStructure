#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;



#define   MAXQSIZE    100

typedef char QElemType;

typedef  struct {
    QElemType* base;
    int         front;
    int         rear;
} SqQueue;

//初始化

//销毁

//清空队列

//判断空

//求长度

//得到队首元素

//入队列

//出队列

//遍历输出