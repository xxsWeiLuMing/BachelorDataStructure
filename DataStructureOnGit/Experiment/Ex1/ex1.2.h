#pragma once
// 试写一算法，
// 实现顺序表的就地逆置，
// 即利用原表的存储空间将线性表(a1,a2,…,an)逆置为(an,an-1,…,a1)

#include"SeqList.h"

void Func()
{
    SeqList va;
    InitList(va);
    ElemType a[] = { '1','3','5','7','9' };//只能处理一位数，因为ElemType是char类型
    int lengthA = sizeof(a) / sizeof(ElemType);
    CreateList(va, a, lengthA);
    cout << "原来的顺序表：";
    TraverseList(va);

    for (int i = 0; i < lengthA / 2; i++)
    {
        ElemType temp = va.elem[i];
        va.elem[i] = va.elem[lengthA - 1 - i];
        va.elem[lengthA - 1 - i] = temp;
    }
    cout << "逆置后的顺序表：";
    TraverseList(va);
}