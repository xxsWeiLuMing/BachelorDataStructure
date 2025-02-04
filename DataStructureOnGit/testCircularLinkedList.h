#pragma once
#include"CircularLinkedList.h"

void testCircularLinkedList()
{
    LinkList H = NULL;
    cout << "IsEmpty:" << IsEmpty(H) << endl;

    cout << "Init Status:" << Init(H) << endl;

    cout << "IsEmpty:" << IsEmpty(H) << endl;

    cout << "Create Status:" << Create(H, 5) << endl;

    cout << "Traverse:";
    Traverse(H);

    cout << "IsEmpty:" << IsEmpty(H) << endl;

    cout << "Length:" << Length(H) << endl;

    /*char e;
    int i = 4;
    GetElem(H, i, e);
    cout << "GetElem " << "第" << i << "位：" << e << endl;

    char e1 = 'g';
    if (!LocateElem(H, e1))cout << "LocateElem:" << e1 << "不存在" << endl;
    else cout << "LocateElem:" << e1 << "在第" << LocateElem(H, e1) << "位" << endl;

    Insert(H, 5, '1');
    cout << "Insert:";
    Traverse(H);

    Delete(H, 1, e);
    cout << "Delete:";
    Traverse(H);
    cout << "Delete e:" << e << endl;*/

    Destroy(H);
    cout << "Destroy IsEmpty:" << IsEmpty(H) << endl;
}