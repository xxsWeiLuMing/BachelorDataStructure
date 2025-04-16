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
Status InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front) return ERROR;
    Q.front->next = nullptr;
    return OK;
}

//销毁
Status DestroyQueue(LinkQueue& Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

//清空队列
Status ClearQueue(LinkQueue& Q) {
    QueuePtr p, q;
    Q.rear = Q.front;
    p = Q.front->next;
    Q.front->next = nullptr;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

//判断空
Status QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) return TRUE;
    else return FALSE;
}

//求长度
int QueueLength(LinkQueue Q) {
    int length = 0;
    QueuePtr p = Q.front;
    while (p != Q.rear) {
        length++;
        p = p->next;
    }
    return length;
}

//得到队首元素
Status GetHead(LinkQueue Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR;
    e = Q.front->next->data;
    return OK;
}

//入队列
Status EnQueue(LinkQueue& Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW);
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

//出队列
Status DeQueue(LinkQueue& Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}

//遍历输出
Status QueueTraverse(LinkQueue Q, void (*visit)(QElemType)) {
    QueuePtr p = Q.front->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    return OK;
}

Status QueueTraverse(LinkQueue Q) {
    QueuePtr p = Q.front->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return OK;
}