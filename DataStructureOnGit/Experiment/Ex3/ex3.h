#pragma once
#include"..\..\Data Structure\Queue\SeqQueue.h"

Status EnQueue(QElemType e,SeqQueue& Q){
    if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; // 队列满

    if (Q.front == Q.rear) {// 队列空
        Q.base[Q.rear] = e;
        Q.rear = (Q.rear + 1) % MAXQSIZE;
        Q.front = (Q.front - 1 + MAXQSIZE) % MAXQSIZE;//同时移动Q.rear和Q.front
    }
    else {
        QElemType ave = Q.base[(Q.front + 1) % MAXQSIZE] + Q.base[(Q.rear - 1 + MAXQSIZE) % MAXQSIZE];
        //Q.rear-1才是队尾元素，Q.rear为空
        ave /= 2;
        if (e < ave) {
            Q.base[Q.front] = e;
            Q.front = (Q.front - 1+ MAXQSIZE) % MAXQSIZE;
        }
        else{
            Q.base[Q.rear] = e;
            Q.rear = (Q.rear + 1) % MAXQSIZE;
        }
    }

    return OK;
}

Status Traverse(SeqQueue Q) {
    int i = (Q.front + 1) % MAXQSIZE;//Q.front + 1可能超过MAXQSIZE
    while (i != Q.rear) {
        cout << Q.base[i] << " ";
        i = (i + 1) % MAXQSIZE;
    }
    cout << endl;
    return OK;
}

void Func() {
    SeqQueue Q;
    InitQueue(Q);

    QElemType e;
    cout << "输入作业时间：";
    while (cin.peek() != '\n') {
        cin >> e;
        EnQueue(e, Q);
    }

    cout << "队列：";
    Traverse(Q);
}