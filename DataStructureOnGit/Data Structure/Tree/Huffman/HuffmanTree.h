#pragma once

#include"..\..\general.h"

#define codebit 10
typedef  struct {
    unsigned int    weight;//权
    unsigned int    parent, lchild, rchild;//父母，左孩子，右孩子
    char c;//编码系统的字符
} HTNode, * HuffmanTree;  //动态分配数组存储哈夫曼树

typedef  char** HuffmanCode;  //动态分配数组存储哈夫曼编码表