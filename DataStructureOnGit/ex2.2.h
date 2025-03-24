#pragma once

#include"SinglyLinkedList.h"

void Delete(LinkList& L,ElemType mink, ElemType maxk) {
    LinkList p = L->next;
    LinkList q = L;

    while (p->data <= mink) {
        p = p->next;
        q = q->next;
    }

    while (p->data < maxk)
    {
        q->next = p->next;
        free(p);
        if(q->next)p = q->next;
    }
}

Status Func() {
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

    if (mink > maxk)return ERROR;

    Delete(L, mink, maxk);
    TraverseList(L);
}