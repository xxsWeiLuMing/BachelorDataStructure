//
// Created by small on 2025/4/20.
//

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "../general.h"

typedef int ElemType;
//typedef char ElemType;
typedef  struct  LNode
{
    ElemType data;
    struct  LNode* next;
} LNode, * LinkList;



//初始化
inline Status InitList(LinkList& L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    if (!L)return ERROR;
    return OK;
}

//创建
inline Status  CreateList(LinkList& L, int  n)
{
    if (!L)return ERROR;

    LinkList q = L;
    for (int i = n; i > 0; i--)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        cin >> p->data;
        p->next = q->next;
        q->next = p;
        q = p;
    }

    return OK;
}

//遍历输出
inline Status DisplayList(LinkList L)
{
    if (!L)return ERROR;//不能遍历未初始化的表
    if (!L->next)return ERROR;//不能遍历只有头结点的表

    LinkList p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return OK;
}

//销毁
inline void DestroyList(LinkList& L)
{
    LinkList p = L, q = p->next;
    while (q)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
    L = NULL;
}

//判断空
inline bool IsListEmpty(LinkList L)
{
    if (!L) return true;//L为空，返回true
    return(L->next == NULL);
}

//求长度
inline int ListLength(LinkList L)
{
    LinkList p = L;
    int i = 0;
    while (p->next != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

//求第i个元素的值
inline Status GetElem(LinkList L, int i, ElemType& e)//用e返回L中第i个元素的值。
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;

    if (i < 1)return ERROR;

    LinkList p = L;
    int j = 0;

    for (; j < i && p; j++)p = p->next;

    if (!p) return ERROR; //不存在第i个数据结点

    //存在第i个数据结点
    e = p->data;
    return OK;
}

//求第一个值为e的元素的位序
inline int LocateElem(LinkList L, ElemType e)
{
    LinkList p = L->next;
    int n = 1;

    for (;p && p->data != e;n++)p = p->next;

    if (!p)return ERROR;

    return n;
}

//把元素e插入到第i个
inline Status ListInsert(LinkList& L, int  i, ElemType e)
{
    LinkList  p = L;
    int j = 0;

    for (; p && j < i - 1; j++)p = p->next;

    if (!p || j > i - 1)return ERROR;

    LinkList s = (LinkList)malloc(sizeof(LNode));

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

//删除第i个元素
inline Status ListDelete(LinkList& L, int i, ElemType& e)
{
    int j = 0;
    LinkList p = L, q;

    for (; p->next && j < i - 1; j++)p = p->next;

    if (!(p->next || j > i - 1)) return ERROR;

    q = p->next;
    p->next = q->next;
    e = q->data;

    free(q);

    return OK;
}

#endif //SINGLYLINKEDLIST_H
