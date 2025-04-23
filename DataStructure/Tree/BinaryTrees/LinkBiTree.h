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
    struct  BiTNode* lChild, * rChild;
} BiTNode, * BiTree;

//建树
inline Status  CreateBiTree(BiTree& T)//先序输入，创建二叉树
{
    char ch;
    scanf("%c", &ch, static_cast<int>(sizeof(ch)));
    if (ch == '*')  T = nullptr;
    else
    {
        T = static_cast<BiTNode *>(malloc(sizeof(BiTNode)));
        if (!T) exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lChild);
        CreateBiTree(T->rChild);
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
        if (T->lChild != nullptr || T->rChild != nullptr)
        {
            printf("(");
            DisplayBiTree(T->lChild);
            /*递归处理左子树*/
            printf(",");
            DisplayBiTree(T->rChild);
            /*递归处理右子树*/
            printf(")");
        }
    }
}

//递归先序、中序、后序遍历
inline Status PreOrderTraverse(BiTree T) {
    if (T!=nullptr) {
        if(cout<<T->data<<" ")
            if(PreOrderTraverse(T->lChild))
                if(PreOrderTraverse(T->rChild))return OK;
        return ERROR;
    }
    return OK;
}

inline Status InOrderTraverse(BiTree T) {
    if (T!=nullptr) {
        if (InOrderTraverse(T->lChild))
            if (cout<<T->data<<" ")
                if (InOrderTraverse(T->rChild))return OK;
        return ERROR;
    }
    return OK;
}

inline Status PostOrderTraverse(BiTree T) {
    if (T!=nullptr) {
        if (PostOrderTraverse(T->lChild))
            if (PostOrderTraverse(T->rChild))
                if (cout<<T->data<<" ")return OK;
    }
    return OK;
}


//非递归先序、中序、后序遍历

//层序遍历

#endif //LINKBITREE_H
