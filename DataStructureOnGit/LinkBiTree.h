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
    scanf_s("%c", &ch, sizeof(char)); // 修复C6064和C4473错误，添加缓冲区大小参数
    if (ch == '0')  T = NULL;
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

// 对于非空二叉树T,先输出其元素值,当存在左孩子结点或右孩子结点时,
// 输出一个“(”符号,然后递归处理左子树,输出一个“,”符号,
// 递归处理右子树,最后输出一个“)”符号。
void DisplayBiTree(BiTree T)
{
    if (T != NULL)
    {
        printf("%c", T->data);
        if (T->lchild != NULL || T->rchild != NULL)
        {
            printf("(");
            DisplayBiTree(T->lchild);
            /*递归处理左子树*/
            printf(",");
            DisplayBiTree(T->rchild);
            /*递归处理右子树*/
            printf(")");
        }
    }
}