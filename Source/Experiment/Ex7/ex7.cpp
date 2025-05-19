//
// Created by small on 2025/5/19.
//
#include"DataStructure/Tree/BinaryTrees/LinkBiTree.h"

Status InOrder(BiTree T, int &prior) {
    //相同值的结点只打印一次
    //二叉排序树中，相同值一定相邻
    if (T != nullptr) {
        if (T->lChild)InOrder(T->lChild, prior);
        if (T->data != prior) {
            cout << T->data << " ";
            prior = T->data;
        }
        if (T->rChild)InOrder(T->rChild, prior);
        return OK;
    }
    return OK;
}

int Count(BiTree T, int &prior, int &sum) {
    //相同值的结点只打印一次
    //二叉排序树中，相同值一定相邻
    if (T != nullptr) {
        if (T->lChild)Count(T->lChild, prior, sum);
        if (T->data != prior) {
            sum++;
            prior = T->data;
        }
        if (T->rChild)Count(T->rChild, prior, sum);
        return sum;
    }
    return sum;
}

void Func() {
    BiTree T;
    char ch[] = "38 31 20 0 0 31 0 0 45 40 0 0 50 0 0";

    cout << "先序输入二叉排序树,0表示空树：";
    CreateBiTree(T);

    cout << "显示：";
    DisplayBiTree(T);
    cout << endl;

    cout << "中序：";
    InOrderTraverse(T);
    cout << endl;

    cout << "相同值只打印一次：";
    int a = 0;
    InOrder(T, a);
    cout << endl;

    int sum = 0;
    cout << "不同结点有" << Count(T, a, sum) << "个" << endl;
}
