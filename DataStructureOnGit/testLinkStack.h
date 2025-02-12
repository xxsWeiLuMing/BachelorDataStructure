#pragma once
#include"LinkStack.h"

void test() {
    SLinkList S;
    cout << "InitStack Status:" << InitStack(S) << endl;
    cout << "Stack Empty:" << StackEmpty(S) << endl;
    cout << "Stack Length:" << StackLength(S) << endl;
}