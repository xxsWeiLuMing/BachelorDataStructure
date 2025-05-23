//
// Created by small on 2025/4/20.
//
#include "../DoubleLinkedList.h"
void test()
{
    DoubleLinkList D = NULL;
    cout << "IsListEmpty:" << IsListEmpty(D) << endl;
    cout << "InitList Status:" << InitList(D) << endl;
    cout << "IsListEmpty:" << IsListEmpty(D) << endl;

    cout << "ListLength:" << ListLength(D) << endl;

    CreateList(D, 5);
    cout << "CreateList,DisplayList:";
    DisplayList(D);

    cout << "IsListEmpty:" << IsListEmpty(D) << endl;
    cout << "ListLength:" << ListLength(D) << endl;

    char e;
    int i = 5;
    if (GetElem(D, i, e))cout << "GetElem " << "第" << i << "位：" << e << endl;
    else cout << "GetElem " << "第" << i << "位不存在" << endl;

    e = 'g';
    if (!LocateElem(D, e))cout << "LocateElem:" << e << "不存在" << endl;
    else cout << "LocateElem:" << e << "在第" << LocateElem(D, e) << "位" << endl;

    i = 0;
    e = '1';
    if (ListInsert(D, i, e))cout << "ListInsert 第" << i << "位插入" << e << ":";
    else cout << "ListInsert 第" << i << "位插入" << e << "失败:";
    DisplayList(D);

    i = 0;
    if (ListDelete(D, i, e))cout << "ListDelete 删除第" << i << "位" << e << " :";
    else cout << "ListDelete 删除第" << i << "位失败:";
    DisplayList(D);

    DestroyList(D);
    cout << "DestroyList IsListEmpty:" << IsListEmpty(D) << endl;
}