//
// Created by small on 2025/4/21.
//
#include"../../DataStructure/LinearList/SeqList.h"

void Func()
{
    SeqList va;
    InitList(va);
    ElemType a[] = { '1','3','5','7','9' };//只能处理一位数，因为ElemType是char类型
    int lengthA = sizeof(a) / sizeof(ElemType);
    CreateList(va, a, lengthA);
    cout << "原来的顺序表：";
    DisplayList(va);

    for (int i = 0; i < lengthA / 2; i++)
    {
        ElemType temp = va.elem[i];
        va.elem[i] = va.elem[lengthA - 1 - i];
        va.elem[lengthA - 1 - i] = temp;
    }
    cout << "逆置后的顺序表：";
    DisplayList(va);
}