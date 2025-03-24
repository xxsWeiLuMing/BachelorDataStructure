#pragma once

#include"SinglyLinkedList.h"

LinkList Link(LinkList ha, LinkList hb) {
    LinkList hc;

    hc = ha->next;
    while (hc->next)hc = hc->next;
    hc->next = hb->next;
    hc = ha;

    return hc;
}

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

    hc = Link(ha, hb);

    cout << "ha:"; TraverseList(ha);
    cout << "hb:"; TraverseList(hb);
    cout << "hc:"; TraverseList(hc);
}