#pragma once
#include"..\general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

//顺序表

typedef char ElemType;

#define  LIST_INIT_SIZE  100 //存储空间的初始分配量
#define  LISTINCREMENT  10 //存储空间的分配增量

typedef struct SeqList 
{
    ElemType* elem = NULL; //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
} SeqList;



Status InitList(SeqList& L)
{
    if (L.elem)return ERROR;//已经初始化的表不能被初始化

    L.elem = (ElemType*)malloc(
        LIST_INIT_SIZE * sizeof(ElemType));

    if (!L.elem) exit(OVERFLOW);

    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    return OK;
}

Status CreateList(SeqList& L, ElemType a[], int n)
{
    if (!L.elem) return ERROR;//未初始化的表不能被创建

    for (int i = 0; i <= n; i++)L.elem[i] = a[i];//TODO：当n大于listsize？

    L.length = n;
    L.listsize = LIST_INIT_SIZE;

    return OK;
}

Status TraverseList(SeqList L)
{
    if (L.length == 0)return ERROR;

    for (int i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";

    cout << endl;

    return OK;
}

void DestroyList(SeqList& L)
{
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
}

Status IsListEmpty(SeqList L)
{
    return (L.length == 0);
}

int ListLength(SeqList L)
{
    return(L.length);
}

Status GetElem(SeqList L, int i, ElemType& e)
{
    if (i<1 || i>L.length)return ERROR;

    e = L.elem[i - 1];//自然语言中没有“第0个”一说，故第i个的编号为i-1

    return OK;
}

int LocateElem(SeqList L,ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)return i + 1;
    }

    return ERROR;
}

Status ListInsert(SeqList& L,int i, ElemType e)
{
    if (i<1 || i>L.length + 1)return ERROR;

    if (L.length >= L.listsize)
    {
        ElemType* newbase = (ElemType*)realloc(L.elem,
            (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }

    ElemType* q = &(L.elem[i - 1]);
    for (ElemType* p = &(L.elem[L.length - 1]); p >= q; p--)
    {
        *(p + 1) = *p;
    }

    *q = e;
    L.length++;

    return OK;
}

//删除第i个元素
Status ListDelete(SeqList& L, int i, ElemType& e)
{
    if (i<1 || i>L.length)return ERROR;

    ElemType* p = &(L.elem[i - 1]);
    e = *p;

    for (ElemType* q = &(L.elem[L.length - 1]); p <= q; p++)
    {
        *p = *(p + 1);
    }

    L.length--;

    return OK;
}