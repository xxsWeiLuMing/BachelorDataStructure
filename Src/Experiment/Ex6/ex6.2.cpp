//
// Created by small on 2025/4/27.
//
#include "DataStructure/Tree/BinaryTrees/LinkBiTree.h"
int LeftNum(BiTree T) {
    int num=0;

    if (T->lChild==nullptr&&T->rChild==nullptr)return 1;

    if (T->lChild)num+=LeftNum(T->lChild);
    if (T->rChild)num+=LeftNum(T->rChild);

    return num;
}

void Func() {
    BiTree T;

    cout<<"先序输入创建二叉树，*表示空结点:";
    CreateBiTree(T);

    cout<<"显示二叉树:";
    DisplayBiTree(T);
    cout<<endl;

    cout<<"叶子结点有"<<LeftNum(T)<<"个"<<endl;
}