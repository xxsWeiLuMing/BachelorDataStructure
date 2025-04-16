#pragma once
#include"..\general.h"

typedef char ElemType;

typedef struct CirLNode
{
    ElemType data;
    struct  CirLNode* next;
} CirLNode, * CirLinkList;

//初始化
Status InitList(CirLinkList& L)
{
    L = (CirLinkList)malloc(sizeof(CirLNode));
    if (!L)return ERROR;
    L->next = NULL;

    return OK;
}

//创建
Status CreateList(CirLinkList& L, int  n)
{
    if (!L)return ERROR;

    CirLinkList q = L;
    for (int i = n; i > 0; i--) 
    {
        CirLinkList p = (CirLinkList)malloc(sizeof(CirLNode));
        if(!p) return ERROR;
        cin >> p->data;
        p->next = q->next;
        q->next = p;
        q = p;
    }

    q->next = L->next;

    return OK;
}

//遍历输出
Status TraverseList(CirLinkList L)
{
    if (!L) return ERROR; //不能遍历未初始化的表
    if (!L->next) return ERROR; //不能遍历只有头结点的表

    CirLinkList p = L->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != L->next);//先执行一次，再判断
    cout << endl;

    return OK;
}

//销毁

//void DestroyList(CirLinkList& L)
//{
//    CirLinkList p = L, q = L->next;
//    do
//    {
//        free(p);//free会把next值变为0xdddddddddddddddd，而不是null（0x00000000）
//        p = q;
//        q = q->next;
//    } while (q != (CirLinkList)0xdddddddddddddddd);
//    //最后一次循环中，q为0xdddddddddddddddd
//    //当p指向尾结点时，p->next指向首结点，
//    //而首结点被释放了，所以首结点的next值为0xdddddddddddddddd
//    L = NULL;
//}

void DestroyList(CirLinkList& L)
{
    CirLinkList p = L, q = L->next;
    do
    {
        free(p);
        //free会把next值变为0xdddddddddddddddd（野指针），而不是null（0x00000000）（空指针）
        p->next = NULL;
        p = q;
        q = q->next;
    } while (q);

    L = NULL;
}

//判断空
bool IsListEmpty(CirLinkList L)
{
    if (!L) return true;
    return(L->next == NULL);//L为空，返回true，否则返回false
}

//求长度
int ListLength(CirLinkList L)
{
    if (!L) return ERROR;
    if (!L->next) return 0;

    CirLinkList p = L;
    int i = 0;

    do
    {
        i++;
        p = p->next;
    } while (p->next != L->next);

    return i;
}

//求第i个元素的值
Status GetElem(CirLinkList L, int i, ElemType& e)
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;

    if (i < 1) return ERROR;
    //“i小于1”的时间复杂度为O(1)，可以立刻做出判断
    //“i大于Length(L)”的时间复杂度为O(n)，应该在本函数中进行判断

    CirLinkList p = L;
    int j = 0;

    do
    {
        p = p->next;
        j++;
    } while (p->next != L->next && j < i);
    //对于while (p!= L->next && j < i)
    //当i=1，有p=L->next
    //当p=L->next时，可能i=1，也可能i大于Length(L)
    //所以应该用while (p->next != L->next && j < i)

    if (j != i) return ERROR;

    e = p->data;

    return OK;
}

//求第一个值为e的元素的位序
int LocateElem(CirLinkList L, ElemType e)
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;

    CirLinkList p = L->next;
    int i = 1;

    do
    {
        if (p->data == e) return i;
        p = p->next;
        i++;
    } while (p != L->next);

    return 0;
}

//把元素e插入到第i个
Status ListInsert(CirLinkList& L, int i, ElemType e)
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;
    if (i < 1) return ERROR;

    if (i == 1)
    {
        CirLinkList p = L->next;
        while (p->next != L->next) p = p->next;

        CirLinkList q = (CirLinkList)malloc(sizeof(CirLNode));
        if (!q) return ERROR;
        q->data = e;

        q->next = L->next;
        L->next = q;
        p->next = q;

        return OK;
    }

    CirLinkList p = L;
    int j = 1;
    //while ((p->next != L->next || p == L) && j < i)
    //{
    //    p = p->next;
    //    j++;
    //}//只有头结点L和尾结点的next值为L->next
    do
    {
        p = p->next;
        j++;
    } while (p->next != L->next && j < i);

    if (j != i) return ERROR;

    CirLinkList q = (CirLinkList)malloc(sizeof(CirLNode));
    if (!q) return ERROR;
    q->data = e;

    q->next = p->next;
    p->next = q;

    return OK;
}

//删除第i个元素
Status ListDelete(CirLinkList& L, int i, ElemType& e)
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;
    if (i < 1) return ERROR;

    if (i == 1)
    {
        CirLinkList p = L->next;
        while (p->next != L->next) p = p->next;

        CirLinkList q = L->next;
        e = q->data;
        L->next = q->next;
        p->next = L->next;

        free(q);

        return OK;
    }

    CirLinkList p = L;
    int j = 1;
    do
    {
        p = p->next;
        j++;
    } while (p->next != L->next && j < i);

    if (p->next == L->next) return ERROR;

    CirLinkList q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);

    return OK;
}


