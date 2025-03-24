#pragma once

#include"SinglyLinkedList.h"

void Func() {
    LinkList ha, hb, hc;
    InitList(ha);
    InitList(hb);
    InitList(hc);

    int m, n;

    cout << "输入ha的长度m：";
    cin >> m;
    cout << "输入ha：";
    CreateList(ha, m);

    cout << "输入hb的长度n：";
    cin >> n;
    cout << "输入hb：";
    CreateList(hb, n);


}