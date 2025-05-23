//
// Created by small on 2025/4/20.
//
#include"../SinglyLinkedList.h"

void test()//ElemType必须为char.This Func need ElemType must be char.
{
    LinkList L = NULL;
    cout << "IsListEmpty:" << IsListEmpty(L) << endl;

    cout << "InitList Status:" << InitList(L) << endl;

    cout << "IsListEmpty:" << IsListEmpty(L) << endl;

    cout << "CreateList Status:" << CreateList(L, 5) << endl;

    cout << "DisplayList:";
    DisplayList(L);

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
    DisplayList(L);

    ListDelete(L, 1, e);
    cout << "ListDelete:";
    DisplayList(L);
    cout << "ListDelete e:" << e << endl;

    DestroyList(L);
    cout << "DestroyList IsListEmpty:" << IsListEmpty(L) << endl;
}