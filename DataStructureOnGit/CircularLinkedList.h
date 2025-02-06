#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

typedef char ElemType;

typedef struct LNode
{
    ElemType data;
    struct  LNode* next;
} LNode, * LinkList;

//初始化
Status Init(LinkList& L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)return ERROR;
    L->next = NULL;

    return OK;
}

//创建
Status Create(LinkList& L, int  n)
{
    if (!L)return ERROR;

    LinkList q = L;
    for (int i = n; i > 0; i--) 
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
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
Status Traverse(LinkList L)
{
    if (!L) return ERROR; //不能遍历未初始化的表
    if (!L->next) return ERROR; //不能遍历只有头结点的表

    LinkList p = L->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != L->next);//先执行一次，再判断
    cout << endl;

    return OK;
}

//销毁

//void Destroy(LinkList& L)
//{
//    LinkList p = L, q = L->next;
//    do
//    {
//        free(p);//free会把next值变为0xdddddddddddddddd，而不是null（0x00000000）
//        p = q;
//        q = q->next;
//    } while (q != (LinkList)0xdddddddddddddddd);
//    //最后一次循环中，q为0xdddddddddddddddd
//    //当p指向尾结点时，p->next指向首结点，
//    //而首结点被释放了，所以首结点的next值为0xdddddddddddddddd
//    L = NULL;
//}

void Destroy(LinkList& L)
{
    LinkList p = L, q = L->next;
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
bool IsEmpty(LinkList L)
{
    if (!L) return true;
    return(L->next == NULL);//L为空，返回true，否则返回false
}

//求长度
int Length(LinkList L)
{
    if (!L) return ERROR;
    if (!L->next) return 0;

    LinkList p = L;
    int i = 0;

    do
    {
        i++;
        p = p->next;
    } while (p->next != L->next);

    return i;
}

//用e返回L中第i个元素的值
Status GetElem(LinkList L, int i, ElemType& e)
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;

    if (i < 1) return ERROR;
    //“i小于1”的时间复杂度为O(1)，可以立刻做出判断
    //“i大于Length(L)”的时间复杂度为O(n)，应该在本函数中进行判断

    LinkList p = L;
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

//顺序查找第1个值域与e相等的元素的位序
int LocateElem(LinkList L, ElemType e)
{
    if (!L) return ERROR;
    if (!L->next) return ERROR;

    LinkList p = L->next;
    int i = 1;

    do
    {
        if (p->data == e) return i;
        p = p->next;
        i++;
    } while (p != L->next);

    return 0;
}

//在L的第i个位置上插入新的元素e

//删序L中的第i个元素



