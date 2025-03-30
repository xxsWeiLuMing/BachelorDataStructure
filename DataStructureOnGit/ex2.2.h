#pragma once

#include"SinglyLinkedList.h"

Status Delete(LinkList& L,ElemType mink, ElemType maxk) {
    LinkList p = L->next;
    LinkList q = L;

    while (p->data <= mink) {
        if (!p->next)
        {
            cout << "错误：所有结点小于mink" << endl;
            return ERROR;
        }
        p = p->next;
        q = q->next;
    }

    while (p->data < maxk)
    {
        q->next = p->next;
        free(p);
        if(q->next)p = q->next;
    }
    if (p == L->next)
    {
        cout << "错误：所有结点大于maxk" << endl;
        return ERROR;
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

    if (Delete(L, mink, maxk))TraverseList(L);
    else return ERROR;
}