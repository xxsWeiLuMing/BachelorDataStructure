#pragma once
#include"SeqList.h"

void testSeqList()
{
    SeqList L;
    Init(L);//顺序表：初始化
    cout << "初始化、判断空：" << IsEmpty(L) << endl;//顺序表：判断空

    char a[] = { 'a','b','c','d','e',
        'f','g','h','i','j' };
    Create(L, a, 10);//顺序表：创建
    cout << "初始化、创建、遍历：";
    Traverse(L);//顺序表：遍历

    cout << "判断空：" << IsEmpty(L) << endl;//顺序表：判断空

    cout << "求长度:" << Length(L) << endl;//顺序表：求长度

    ElemType e;
    int i = 2;
    GetElem(L, i, e);
    cout << "求第" << i << "个的值：" << e << endl;//顺序表：求第i个的值

    e = 'g';
    cout << "求" << e << "在表中的位置：" << LocateElem(L, e) << endl;//顺序表：求值e在表中是第几个

    i = 11;
    e = '5';
    Insert(L, i, e);//顺序表：把值e插入到表L的第i个处
    cout << "把值" << e << "插入到第" << i << "个处：";
    Traverse(L);

    Destroy(L);//顺序表：销毁表
    cout << "Destroy：" << IsEmpty(L) << endl;
}