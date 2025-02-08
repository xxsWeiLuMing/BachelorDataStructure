#pragma once
#include"SinglyLinkedList.h"

void testSinglyLinkedList()
{
    LinkList L = NULL;
    cout << "IsListEmpty:" << IsListEmpty(L) << endl;

    cout << "InitList Status:" << InitList(L) << endl;

    cout << "IsListEmpty:" << IsListEmpty(L) << endl;

    cout << "CreateList Status:" << CreateList(L, 5) << endl;

    cout << "TraverseList:";
    TraverseList(L);

    cout << "IsListEmpty:" << IsListEmpty(L) << endl;

    cout << "ListLength:" << ListLength(L) << endl;

    char e;
    int i = 4;
    GetElem(L, i, e);
    cout << "GetElem " << "第" << i << "位：" << e << endl;

    char e1 = 'g';
    if (!LocateElem(L, e1))cout << "LocateElem:" << e1 << "不存在" << endl;
    else cout << "LocateElem:" << e1 << "在第" << LocateElem(L, e1) << "位" << endl;

    ListInsert(L, 5, '1');
    cout << "ListInsert:";
    TraverseList(L);

    ListDelete(L, 1, e);
    cout << "ListDelete:";
    TraverseList(L);
    cout << "ListDelete e:" << e << endl;

    DestroyList(L);
    cout << "DestroyList IsListEmpty:" << IsListEmpty(L) << endl;
}