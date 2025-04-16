#pragma once
#include"..\general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

#define  STACK_INIT_SIZE   100 
#define  STACKINCREMENT  10 

typedef char SElemType;

typedef  struct  SLNode {
    SElemType   data;
    struct SLNode* next;
} SLNode, * SLinkList;

//初始化
Status InitStack(SLinkList& S) {
    S = nullptr;
    return OK;
}

//销毁
Status DestroyStack(SLinkList& S) {
    //if (!S)return OK;
    SLNode* p;
    while (S) {
        p = S;
        S = S->next;
        free(p);
    }
    return OK;
}

//遍历输出
void visit(SLinkList p) {
    if (p->next)visit(p->next);
    cout << p->data << " ";
}

Status TraverseStack(SLinkList S) {
    //if (!S)return OK;
    SLNode* p = S;
    //while (p) {
    //    cout << p->data << " ";
    //    p = p->next;
    //}
    visit(p);
    cout << endl;
    return OK;
}

//判断空
bool StackEmpty(SLinkList S) {
    return S == nullptr;
}

//求长度
int StackLength(SLinkList S) {
    int length = 0;
    SLNode* p = S;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

//得到栈首元素
Status GetTop(SLinkList S, SElemType& e) {
    if (S == nullptr) return ERROR;
    e = S->data;
    return OK;
}

//入栈
Status Push(SLinkList& S, SElemType e) {
    SLNode* p = (SLNode*)malloc(sizeof(SLNode));
    if (!p)exit(OVERFLOW);
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

//出栈
Status Pop(SLinkList& S, SElemType& e) {
    if (S == nullptr) return ERROR;
    SLNode* p = S;
    e = p->data;
    S = S->next;
    free(p);
    return OK;
}

//清空栈
Status ClearStack(SLinkList& S) {
    DestroyStack(S);
    S = nullptr;
    return OK;
}
