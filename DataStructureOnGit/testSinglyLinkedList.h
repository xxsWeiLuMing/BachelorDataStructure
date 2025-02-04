#pragma once
#include"SinglyLinkedList.h"

void testSinglyLinkedList()
{
    LinkList L;
    cout << "Init Status:" << Init(L) << endl;

    cout << "IsEmpty:" << IsEmpty(L) << endl;

    cout << "Create Status:" << Create(L, 5) << endl;

    cout << "Traverse:";
    Traverse(L);

    cout << "IsEmpty:" << IsEmpty(L) << endl;

    cout << "Length:" << Length(L) << endl;

    char e;
    int i = 4;
    GetElem(L, i, e);
    cout << "GetElem " << "第" << i << "位：" << e << endl;

    char e1 = 'g';
    if (!LocateElem(L, e1))cout << "LocateElem:" << e1 << "不存在" << endl;
    else cout << "LocateElem:" << e1 << "在第" << LocateElem(L, e1) << "位" << endl;

    Insert(L, 5, '1');
    cout << "Insert:";
    Traverse(L);

    Delete(L, 1, e);
    cout << "Delete:";
    Traverse(L);
    cout << "e:" << e << endl;

    Destroy(L);
    cout << "Destroy:" << IsEmpty(L) << endl;
}