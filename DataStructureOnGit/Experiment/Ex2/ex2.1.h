#pragma once

#include"..\..\Data Structure\Linear List\SinglyLinkedList.h"

int m, n;

LinkList Link(LinkList ha, LinkList hb) {
    LinkList hc;

    if (m < n) {
        hc = ha->next;
        while (hc->next)hc = hc->next;
        hc->next = hb->next;
        hc = ha;
    }
    else
    {
        hc = hb->next;
        while (hc->next)hc = hc->next;
        hc->next = ha->next;
        hc = hb;
    }

    return hc;
}

void Func() {
    LinkList ha, hb, hc;
    InitList(ha);
    InitList(hb);
    InitList(hc);

    cout << "输入ha的长度m：";
    cin >> m;
    cout << "输入ha：";
    CreateList(ha, m);

    cout << "输入hb的长度n：";
    cin >> n;
    cout << "输入hb：";
    CreateList(hb, n);

    cout << "ha:"; TraverseList(ha);
    cout << "hb:"; TraverseList(hb);

    hc = Link(ha, hb);

    cout << "hc:"; TraverseList(hc);
}