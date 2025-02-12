#pragma once
#include"general.h"
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
void DestroyStack(SLinkList& S) {
    SLNode* p;
    while (S) {
        p = S;
        S = S->next;
        free(p);
    }
}

//遍历输出
void TraverseStack(SLinkList S) {
    SLNode* p = S;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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
bool GetTop(SLinkList S, SElemType& e) {
    if (S == nullptr) return false;
    e = S->data;
    return true;
}

//入栈
void Push(SLinkList& S, SElemType e) {
    SLNode* p = (SLNode*)malloc(sizeof(SLNode));
    p->data = e;
    p->next = S;
    S = p;
}

//出栈
bool Pop(SLinkList& S, SElemType& e) {
    if (S == nullptr) return false;
    SLNode* p = S;
    e = p->data;
    S = S->next;
    free(p);
    return true;
}

//清空栈
void ClearStack(SLinkList& S) {
    DestroyStack(S);
    S = nullptr;
}
