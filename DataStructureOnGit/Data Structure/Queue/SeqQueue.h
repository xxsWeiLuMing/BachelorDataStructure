#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

#define   MAXQSIZE    100

//typedef char QElemType;
typedef int QElemType;

typedef  struct {
    QElemType* base;
    int         front;
    int         rear;
} SeqQueue;

//初始化
Status InitQueue(SeqQueue& Q) {
    Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}

//销毁
Status DestroyQueue(SeqQueue& Q) {
    if (Q.base) {
        free(Q.base);
        Q.base = nullptr;
    }
    Q.front = Q.rear = 0;
    return OK;
}

//清空队列
Status ClearQueue(SeqQueue& Q) {
    Q.front = Q.rear = 0;
    return OK;
}

//判断空
Status QueueEmpty(SeqQueue Q) {
    return Q.front == Q.rear ? TRUE : FALSE;
}

//求长度
int QueueLength(SeqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//得到队首元素
Status GetHead(SeqQueue Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    return OK;
}

//入队列
Status EnQueue(SeqQueue& Q, QElemType e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; // 队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

//出队列
QElemType DeQueue(SeqQueue& Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR; // 队列空
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return e;
}

//遍历输出
Status QueueTraverse(SeqQueue Q, void (*visit)(QElemType)) {
    int i = Q.front;
    while (i != Q.rear) {
        visit(Q.base[i]);
        i = (i + 1) % MAXQSIZE;
    }
    return OK;
}

Status QueueTraverse(SeqQueue Q) {
    int i = Q.front;
    while (i != Q.rear) {
        cout << Q.base[i] << " ";
        i = (i + 1) % MAXQSIZE;
    }
    cout << endl;
    return OK;
}
