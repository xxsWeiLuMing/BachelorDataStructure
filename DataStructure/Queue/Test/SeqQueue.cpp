//
// Created by small on 2025/4/20.
//
#include"../SeqQueue.h"
//ElemType必须为char.This Func need ElemType must be char.

void CreateQueue(SeqQueue& Q)
{
    char ch[5] = { 'a','b','c','d','e' };

    for (int i = 0; i < 5; i++)
    {
        if (EnQueue(Q, ch[i]))
        {
            cout << "EnQueue Success:" << ch[i] << endl;
        }
        else
        {
            cout << "EnQueue Failed:" << ch[i] << endl;
        }
    }
}

void test()
{
    SeqQueue Q{};
    cout << "QueueEmpty:" << QueueEmpty(Q) << endl;
    cout << "InitQueue Status:" << InitQueue(Q) << endl;
    cout << "QueueEmpty:" << QueueEmpty(Q) << endl;

    CreateQueue(Q);

    cout << "QueueTraverse:";
    QueueTraverse(Q);
    cout << "QueueEmpty:" << QueueEmpty(Q) << endl;

    cout << "QueueLength:" << QueueLength(Q) << endl;

    QElemType e;
    GetHead(Q, e);
    cout << "GetHead:" << e << endl;

    cout << "Pop:";
    while (!QueueEmpty(Q))
    {
        DeQueue(Q, e);
        cout << e << " ";
    }
    cout << endl;

    cout << "ClearStack:" << ClearQueue(Q) << endl;
}