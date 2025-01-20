#pragma once
//顺序表

typedef char ElemType;

#define  LIST_INIT_SIZE  100 //存储空间的初始分配量
#define  LISTINCREMENT  10 //存储空间的分配增量

typedef  struct SeqList {
    ElemType* elem; //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
} SeqList;



Status Seq_InitList(SeqList& L)
{
    L.elem = (ElemType*)malloc(
        LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status Seq_CreateList(SeqList& L, ElemType a[], int n)
{
    if (!L.elem) exit(ERROR);
    for (int i = 0; i <= n; i++)L.elem[i] = a[i];
    L.length = n;
    L.listsize = LIST_INIT_SIZE;

    return OK;
}