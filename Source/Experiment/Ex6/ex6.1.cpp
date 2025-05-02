//
// Created by small on 2025/4/27.
//
#include "DataStructure/Tree/BinaryTrees/LinkBiTree.h"

void PreOrderTraverse(BiTree T,int &k) {
    if (T!=nullptr)k--;
    if (T!=nullptr&&k>0) {
        PreOrderTraverse(T->lChild,k);
        PreOrderTraverse(T->rChild,k);
    }
    else if (T!=nullptr&&k==0) cout<<T->data<<endl;
}

void Func() {
    BiTree T;

    cout<<"先序输入创建二叉树，*表示空结点:";
    CreateBiTree(T);

    cout<<"显示二叉树:";
    DisplayBiTree(T);
    cout<<endl;

    cout<<"先序输出：";
    PreOrderTraverse(T);
    cout<<endl;

    int k=0;
    cout<<"输入k：";
    cin>>k;
    cout<<"先序第"<<k<<"个是：";
    PreOrderTraverse(T,k);
}