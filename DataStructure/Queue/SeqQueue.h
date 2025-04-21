//
// Created by small on 2025/4/20.
//

#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include "../general.h"
#define MAXQSIZE 100

//typedef int QElemType;
typedef char QElemType;
typedef  struct {
    QElemType* base;
    int         front;
    int         rear;
} SeqQueue;

//初始化
inline Status InitQueue(SeqQueue& Q) {
    Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}

//销毁
inline Status DestroyQueue(SeqQueue& Q) {
    if (Q.base) {
        free(Q.base);
        Q.base = nullptr;
    }
    Q.front = Q.rear = 0;
    return OK;
}

//清空队列
inline Status ClearQueue(SeqQueue& Q) {
    Q.front = Q.rear = 0;
    return OK;
}

//判断空
inline Status QueueEmpty(SeqQueue Q) {
    return Q.front == Q.rear ? TRUE : FALSE;
}

//求长度
inline int QueueLength(SeqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//得到队首元素
inline Status GetHead(SeqQueue Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    return OK;
}

//入队列
inline Status EnQueue(SeqQueue& Q, QElemType e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; // 队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

//出队列
inline QElemType DeQueue(SeqQueue& Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR; // 队列空
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return e;
}

//遍历输出
inline Status QueueTraverse(SeqQueue Q, void (*visit)(QElemType)) {
    int i = Q.front;
    while (i != Q.rear) {
        visit(Q.base[i]);
        i = (i + 1) % MAXQSIZE;
    }
    return OK;
}

inline Status QueueTraverse(SeqQueue Q) {
    int i = Q.front;
    while (i != Q.rear) {
        cout << Q.base[i] << " ";
        i = (i + 1) % MAXQSIZE;
    }
    cout << endl;
    return OK;
}

#endif //SEQQUEUE_H
