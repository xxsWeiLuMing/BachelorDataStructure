#pragma once
#include"SeqQueue.h"

void Func() {
    SeqQueue Q;
    InitQueue(Q);

    QElemType e;
    cout << "输入作业时间：";
    while (cin.peek() != '\n') {
        cin >> e;
        
    }

    QueueTraverse(Q);
}