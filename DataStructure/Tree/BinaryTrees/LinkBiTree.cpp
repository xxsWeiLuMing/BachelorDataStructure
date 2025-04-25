//
// Created by small on 2025/4/21.
//
#include "LinkBiTree.h"

void test() {
    BiTree T;
    cout << "输入字符串，先序创建二叉树，输入*表示空结点：";
    CreateBiTree(T);

    cout << "显示二叉树：";
    DisplayBiTree(T);
    cout <<endl;

    cout<<"递归先序遍历：";
    PreOrderTraverse(T);
    cout <<endl;

    cout<<"递归中序遍历：";
    InOrderTraverse(T);
    cout <<endl;

    cout<<"递归后序遍历：";
    PostOrderTraverse(T);
    cout <<endl;



    SLinkList S;
    cout<<"非递归先序遍历：";
    PreOrderTraverse(T,S);
    cout <<endl;

    cout<<"非递归中序遍历：";
    InOrderTraverse(T,S);
    cout <<endl;

    cout<<"非递归后序遍历：";
    InOrderTraverse(T,S);
    cout <<endl;



    cout<<"层序遍历：";
    LevelOrderTraverse(T);
    cout <<endl;
}