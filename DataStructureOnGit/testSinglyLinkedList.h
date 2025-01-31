#pragma once
#include"SinglyLinkedList.h"

void testSinglyLinkedList()
{
    LinkList L;
    //int i = Init(L);
    cout << Init(L) << endl;
    cout << Create(L, 5) << endl;
    Traverse(L);
}