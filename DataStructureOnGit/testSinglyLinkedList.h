#pragma once
#include"SinglyLinkedList.h"

void testSinglyLinkedList()
{
    LinkList L;
    //int i = Init(L);
    cout << "Init:" << Init(L) << endl;
    cout << "Create:" << Create(L, 5) << endl;

    cout << "Traverse:";
    Traverse(L);

    char e;
    GetElem(L, 4, e);

    cout << "IsEmpty:" << IsEmpty(L) << endl;

    cout << "Length:" << Length(L) << endl;

    cout << "GetElem:" << e << endl;

    cout << "LocateElem:" << LocateElem(L, 'g') << endl;

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