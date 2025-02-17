#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

typedef char TElemType;

typedef  struct  BiTNode
{
    TElemType data;
    struct  BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

//建树
Status  CreateBiTree(BiTree& T)//先序输入，创建二叉树
{
    char ch;
    scanf_s("%c", &ch);
    if (ch == ' ')  T = NULL;
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        if (!T) exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}