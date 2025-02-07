#pragma once
#include"CircularLinkedList.h"

void testCircularLinkedList()
{
    LinkList H = NULL;
    cout << "IsEmpty:" << IsEmpty(H) << endl;

    cout << "Init Status:" << Init(H) << endl;

    cout << "IsEmpty:" << IsEmpty(H) << endl;

    Create(H, 5);
    cout << "Create,Traverse:";
    Traverse(H);

    cout << "IsEmpty:" << IsEmpty(H) << endl;

    cout << "Length:" << Length(H) << endl;

    char e;
    int i = 5;
    if (GetElem(H, i, e))cout << "GetElem " << "第" << i << "位：" << e << endl;
    else cout << "GetElem " << "第" << i << "位不存在" << endl;

    e = 'g';
    if (!LocateElem(H, e))cout << "LocateElem:" << e << "不存在" << endl;
    else cout << "LocateElem:" << e << "在第" << LocateElem(H, e) << "位" << endl;

    i = 6;
    e = '1';
    Insert(H, i, e);
    cout << "Insert 第" << i << "位插入" << e << ":";
    Traverse(H);

    i = 1;
    Delete(H, i, e);
    cout << "Delete 第" << i << "位" << e << " :";
    Traverse(H);

    Destroy(H);
    cout << "Destroy IsEmpty:" << IsEmpty(H) << endl;
}