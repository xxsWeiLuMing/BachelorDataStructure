#pragma once

typedef char ElemType;

typedef  struct  LNode {
    ElemType data;
    struct  LNode* next;
} LNode, * LinkList;