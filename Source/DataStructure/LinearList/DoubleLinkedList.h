//
// Created by small on 2025/4/20.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "../general.h"

typedef char LElemType;
typedef  struct  DoubleLNode
{
    LElemType data;
    struct  DoubleLNode* prior;
    struct  DoubleLNode* next;
} DoubleLNode, * DoubleLinkList;



//初始化
inline Status InitList(DoubleLinkList& L)
{
    L = (DoubleLNode*)malloc(sizeof(DoubleLNode));
    if (!L) exit(OVERFLOW);

    L->next = L->prior = NULL;

    return OK;
}

//创建
inline Status CreateList(DoubleLinkList& L, int n)
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
        p->next = q;
        p = q;
    }

    return OK;
}

//遍历输出
inline Status DisplayList(DoubleLinkList L)
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;

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
inline Status DestroyList(DoubleLinkList& L)
{
    if (!L) return ERROR;

    DoubleLinkList p = L;
    while (p)
    {
        DoubleLinkList q = p->next;
        free(p);
        p = q;
    }
    L= NULL;

    return OK;
}

//判断空
inline Status IsListEmpty(DoubleLinkList L)
{
    if (!L) return TRUE;
    return L->next == NULL;
}

//求长度
inline int ListLength(DoubleLinkList L)
{
    if (!L) return ERROR;

    DoubleLinkList p = L;
    int i = 0;
    while (p->next)
    {
        i++;
        p = p->next;
    }

    return i;
}

//求第i个元素的值
inline Status GetElem(DoubleLinkList L, int i, LElemType& e)
{
    if (!L) return ERROR;
    if (i < 1) return ERROR;

    DoubleLinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p) return ERROR;//i>length(L)

    e = p->data;

    return OK;
}
/*Status GetElem(DoubleLinkList L, int i, ElemType& e)
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
    //当i<1,if(i<1)和if(j>i)耗时一样,但后者平白降低了代码可读性

    e = p->data;

    return OK;
}*/

//求第一个值为e的元素的位序
inline int LocateElem(DoubleLinkList L, LElemType e)
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
inline Status ListInsert(DoubleLinkList& L, int i, LElemType e)
{
    if (!L) return ERROR;
    if (i < 1) return ERROR;

    DoubleLinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p) return ERROR;

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
inline Status ListDelete(DoubleLinkList& L, int i, LElemType& e)
{
    if (!L) return ERROR;
    if (i < 1) return ERROR;

    DoubleLinkList p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p->next) return ERROR;

    DoubleLinkList q = p->next;
    e = q->data;
    p->next = q->next;
    if (q->next) q->next->prior = p;
    free(q);

    return OK;
}

#endif //DOUBLELINKEDLIST_H
