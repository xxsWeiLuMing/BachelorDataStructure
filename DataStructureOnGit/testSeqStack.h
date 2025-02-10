#pragma once
#include"SeqStack.h"

void CreateStack(SeqStack &S)
{
    char ch[5] = { 'a','b','c','d','e' };
    char str[3][4] = { "abc","123","qwe" };

    for (int i = 0; i < 5; i++)
    {
        if (Push(S, ch[i]))
        {
            cout << "Push Success:" << ch[i] << endl;
        }
        else
        {
            cout << "Push Failed:" << ch[i] << endl;
        }
    }
}

void test()
{
    SeqStack S{};
    cout << "IsStackEmpty:" << IsStackEmpty(S) << endl;
    cout << "InitStack Status:" << InitStack(S) << endl;
    cout << "IsStackEmpty:" << IsStackEmpty(S) << endl;

    CreateStack(S);

    cout << "TraverseStack:";
    TraverseStack(S);

    cout << "StackLength:" << StackLength(S) << endl;

    SElemType e;
    GetTop(S, e);
    cout << "GetTop:" << e << endl;

    cout << "Pop:";
    while (!IsStackEmpty(S))
    {
        Pop(S, e);
        cout << e << " ";
    }
    cout << endl;

    cout << "ClearStack:" << ClearStack(S) << endl;
}


