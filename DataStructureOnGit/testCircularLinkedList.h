#pragma once
#include"CircularLinkedList.h"

void test()
{
    CirLinkList H = NULL;
    cout << "IsListEmpty:" << IsListEmpty(H) << endl;

    cout << "InitList Status:" << InitList(H) << endl;

    cout << "IsListEmpty:" << IsListEmpty(H) << endl;

    CreateList(H, 5);
    cout << "CreateList,TraverseList:";
    TraverseList(H);

    cout << "IsListEmpty:" << IsListEmpty(H) << endl;

    cout << "ListLength:" << ListLength(H) << endl;

    char e;
    int i = 5;
    if (GetElem(H, i, e))cout << "GetElem " << "第" << i << "位：" << e << endl;
    else cout << "GetElem " << "第" << i << "位不存在" << endl;

    e = 'g';
    if (!LocateElem(H, e))cout << "LocateElem:" << e << "不存在" << endl;
    else cout << "LocateElem:" << e << "在第" << LocateElem(H, e) << "位" << endl;

    i = 6;
    e = '1';
    if (ListInsert(H, i, e))cout << "ListInsert 第" << i << "位插入" << e << ":";
    else cout << "ListInsert 第" << i << "位插入" << e << "失败:";
    TraverseList(H);

    i = 7;
    if (ListDelete(H, i, e))cout << "ListDelete 第" << i << "位" << e << " :";
    else cout << "ListDelete 删除第" << i << "位失败:";
    TraverseList(H);

    DestroyList(H);
    cout << "DestroyList IsListEmpty:" << IsListEmpty(H) << endl;
}