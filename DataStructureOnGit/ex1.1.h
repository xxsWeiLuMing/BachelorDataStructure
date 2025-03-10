#pragma once
// 设顺序表va中的数据元素递增有序。
// 试写一算法，将x插入到顺序表的适当位置上，
// 以保持该表的有序性。

#include"SeqList.h"

void Func()
{
    SeqList va;
    InitList(va);
    ElemType a[] = { '1','3','5','7','9' };
    int lengthA = sizeof(a) / sizeof(ElemType);
    CreateList(va, a, lengthA);
    cout << "递增有序的顺序表：";
    TraverseList(va);

    ElemType x;
    cout << "请输入要插入的元素x：";
    cin >> x;

    for (int i = 0; i < lengthA; i++)
    {
        //if (va.elem[i] > x && ListInsert(va, i + 1, x))break;
        if (va.elem[i] > x)
        {
            x&& ListInsert(va, i + 1, x);
            break;
        }
    }
    cout << "插入后的顺序表：";
    TraverseList(va);
    //无法插入一位以上数字，一位ElemType是char类型
}