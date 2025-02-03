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
    cout << "GetElem:" << e << endl;

    cout << "LocateElem:" << LocateElem(L, 'g');

    Insert(L, 5, '1');
    cout << "Insert:";
    Traverse(L);

    Delete(L, 1, e);
    cout << "Delete:";
    Traverse(L);
    cout << "e:" << e << endl;
}