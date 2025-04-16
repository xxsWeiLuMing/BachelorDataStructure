#pragma once
#include"..\SeqList.h"

void test()
{
    SeqList L;
    InitList(L);//顺序表：初始化
    cout << "初始化、判断空：" << IsListEmpty(L) << endl;//顺序表：判断空

    char a[] = { 'a','b','c','d','e',
        'f','g','h','i','j' };
    CreateList(L, a, 10);//顺序表：创建
    cout << "初始化、创建、遍历：";
    TraverseList(L);//顺序表：遍历

    cout << "判断空：" << IsListEmpty(L) << endl;//顺序表：判断空

    cout << "求长度:" << ListLength(L) << endl;//顺序表：求长度

    ElemType e;
    int i = 2;
    GetElem(L, i, e);
    cout << "求第" << i << "个的值：" << e << endl;//顺序表：求第i个的值

    e = 'g';
    cout << "求" << e << "在表中的位置：" << LocateElem(L, e) << endl;//顺序表：求值e在表中是第几个

    i = 11;
    e = '5';
    ListInsert(L, i, e);//顺序表：把值e插入到表L的第i个处
    cout << "把值" << e << "插入到第" << i << "个处：";
    TraverseList(L);

    i = 5;
    ListDelete(L, i, e);//顺序表：删除表L的第i个处的值
    cout << "删除第" << i << "个处的值：" << e << endl;

    DestroyList(L);//顺序表：销毁表
    cout << "Destroy：" << IsListEmpty(L) << endl;
}