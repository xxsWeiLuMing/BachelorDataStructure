#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

typedef char ElemType;
typedef  struct  DoubleLNode
{
    ElemType data;
    struct  DoubleLNode* prior;
    struct  DoubleLNode* next;
    int freq = 0;
} DoubleLNode, * DoubleLinkList;



//初始化
Status InitList(DoubleLinkList& L)
{
    L = (DoubleLNode*)malloc(sizeof(DoubleLNode));
    if (!L) exit(OVERFLOW);
    L->next = L->prior = NULL;
    return OK;
}

//创建
Status CreateList(DoubleLinkList& L, int n)
{
    if (!L) return ERROR;
    DoubleLinkList p = L;
    for (int i = n; i > 0; i--)
    {
        DoubleLinkList q = (DoubleLinkList)malloc(sizeof(DoubleLNode));
        if (!q) return ERROR;
        cin >> q->data;
        q->prior = p;
        q->next = p->next;
        if (p->next) p->next->prior = q;
        p->next = q;
        p = q;
    }
    return OK;
}

//遍历输出
Status TraverseList(DoubleLinkList L)
{
    if (!L) return ERROR;
    DoubleLinkList p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return OK;
}

//销毁
Status DestroyList(DoubleLinkList& L)
{
    if (!L) return ERROR;
    DoubleLinkList p = L->next;
    while (p)
    {
        DoubleLinkList q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    return OK;
}

//判断空
Status IsListEmpty(DoubleLinkList L)
{
    if (!L) return TRUE;
    if (L->next) return FALSE;
    return TRUE;
}

//求长度
int ListLength(DoubleLinkList L)
{
    if (!L) return ERROR;
    DoubleLinkList p = L->next;
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//求第i个元素的值
Status GetElem(DoubleLinkList L, int i, ElemType& e)
 {
    if (!L) return ERROR;
    DoubleLinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

//求第一个值为e的元素的位序
int LocateElem(DoubleLinkList L, ElemType e)
{
    if (!L) return ERROR;
    DoubleLinkList p = L->next;
    int i = 1;
    while (p && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (!p) return 0;
    return i;
}

//把元素e插入到第i个
Status ListInsert(DoubleLinkList& L, int i, ElemType e)
{
    if (!L) return ERROR;
    DoubleLinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return ERROR;
    DoubleLinkList q = (DoubleLinkList)malloc(sizeof(DoubleLNode));
    if (!q) return ERROR;
    q->data = e;
    q->prior = p;
    q->next = p->next;
    if (p->next) p->next->prior = q;
    p->next = q;
    return OK;
}

//删除第i个元素
Status ListDelete(DoubleLinkList& L, int i, ElemType& e)
{
    if (!L) return ERROR;
    DoubleLinkList p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) return ERROR;
    DoubleLinkList q = p->next;
    e = q->data;
    p->next = q->next;
    if (q->next) q->next->prior = p;
    free(q);
    return OK;
}