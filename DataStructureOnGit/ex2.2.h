#pragma once

#include"SinglyLinkedList.h"

void Func() {
    LinkList L;
    InitList(L);

    int n;
    cout << "输入表长n：";
    cin >> n;

    cout << "输入值递增的表：";
    CreateList(L, n);

    ElemType mink, maxk;
    cout << "输入mink：";
    cin >> mink;
    cout << "输入maxk：";
    cin >> maxk;
}