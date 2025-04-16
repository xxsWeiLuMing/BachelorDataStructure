#pragma once
#include"..\LinkBiTree.h"

void test() {
    BiTree T;
    cout << "输入字符串，先序创建二叉树，输入空格表示空结点：";
    CreateBiTree(T);

    cout << "显示二叉树：";
    DisplayBiTree(T);
}