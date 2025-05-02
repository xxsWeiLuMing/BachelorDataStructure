//
// Created by small on 2025/4/27.
//
#include "DataStructure/Tree/BinaryTrees/LinkBiTree.h"
void Swap(BiTree &T) {
    if (T!=nullptr) {
        Swap(T->lChild);
        Swap(T->rChild);

        BiTree temp = T->lChild;
        T->lChild = T->rChild;
        T->rChild = temp;
    }
}

void Func() {
    BiTree T;

    cout<<"先序输入创建二叉树，*表示空结点:";
    CreateBiTree(T);

    cout<<"显示二叉树:";
    DisplayBiTree(T);
    cout<<endl;

    Swap(T);
    cout<<"显示交换后的二叉树：";
    DisplayBiTree(T);
    cout<<endl;
}