#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

typedef char QElemType;

typedef  struct  QNode {
    QElemType data;
    struct  QNode* next;
} QNode, * QueuePtr;

typedef  struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

//初始化

//销毁

//清空队列

//判断空

//求长度

//得到队首元素

//入队列

//出队列

//遍历输出
