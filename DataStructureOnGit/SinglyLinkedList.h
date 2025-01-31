#pragma once

typedef char ElemType;

typedef  struct  LNode {
    ElemType data;
    struct  LNode* next;
} LNode, * LinkList;



//初始化
Status Init(LinkList& L)//初始化单链表
{
    L = (LinkList)malloc(sizeof(LNode)); 	 /*创建头结点*/
    L->next = NULL;

    if (!L)return ERROR;
    return OK;
}

//创建
Status  Create(LinkList& L, int  n)
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
Status Traverse(LinkList L)
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
void Destroy(LinkList& L)
{
    LinkList p = L, q = p->next;
    while (q)
    {
        free(p);
        p = q; q = p->next;
    }
    free(p);
}

//判断空
Status IsEmpty(LinkList L)
{
    return(L->next == NULL);
}

//求长度
int Length(LinkList L)
{
    LinkList p = L; int i = 0;
    while (p->next != NULL)
    {
        i++;
        p = p->next;
    }
    return(i);
}

//求第i个元素的值
Status GetElem(LinkList L, int i, ElemType& e)//用e返回L中第i个元素的值。
{
    LinkList p = L;

    for (int j = 0; j < i && p; j++)
    {
        p = p->next;
    }

    if (!p) return ERROR; /*不存在第i个数据结点*/
    /*存在第i个数据结点*/
    e = p->data;
    return OK;
}

//求第1个值为e的元素的位序


//插入元素e到第i个


//删序第i个元素

