//
// Created by small on 2025/4/21.
//
#include"../../DataStructure/LinearList/SeqList.h"

void Func()
{
    SeqList va;
    InitList(va);
    ElemType a[] = { '1','3','5','7','9' };
    int lengthA = sizeof(a) / sizeof(ElemType);
    CreateList(va, a, lengthA);
    cout << "递增有序的顺序表：";
    DisplayList(va);

    ElemType x;
    cout << "请输入要插入的元素x：";
    cin >> x;

    for (int i = 0; i < lengthA; i++)
    {
        //if (va.elem[i] > x && ListInsert(va, i + 1, x))break;
        if (va.elem[i] > x)
        {
            ListInsert(va, i + 1, x);
            break;
        }
    }
    cout << "插入后的顺序表：";
    DisplayList(va);
    //只能处理一位数，因为ElemType是char类型
}