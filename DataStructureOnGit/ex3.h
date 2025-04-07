#pragma once
#include"SeqQueue.h"

void Func() {
    SeqQueue Q;
    InitQueue(Q);

    QElemType e;

    while (getchar()) {
        cout << "输入作业时间：";
        cin >> e;
    }

    //QueueTraverse(Q);
}