//
// Created by small on 2025/4/21.
//

#ifndef LINKBITREE_H
#define LINKBITREE_H

#include"../../general.h"

typedef char TElemType;

typedef  struct  BiTNode
{
    TElemType data;
    struct  BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

//建树
inline Status  CreateBiTree(BiTree& T)//先序输入，创建二叉树
{
    char ch;
    scanf("%c", &ch, (int)sizeof(ch));
    if (ch == ' ')  T = nullptr;
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
inline void DisplayBiTree(BiTree T)
{
    if (T != nullptr)
    {
        printf("%c", T->data);
        if (T->lchild != nullptr || T->rchild != nullptr)
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

#endif //LINKBITREE_H
