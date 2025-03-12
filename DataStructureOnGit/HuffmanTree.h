#pragma once

#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

//带权二叉树的定义：给定一组权w1 w2 …… wn , 且w1≤ w2 ≤ …… ≤wn ，设有一个二叉树，共有n片叶子，分别带权w1 w2 …… wn ，该二叉树称为带权二叉树。

//Huffman树定义：设有n个权值w1 w2 …… wn ，构造一棵有n个叶子结点的二叉树，每个叶子的权值为wi,则wpl最小的那棵二叉树叫最优二叉树或Huffman树。



#define codebit 10
typedef  struct {
    unsigned int    weight;//权
    unsigned int    parent, lchild, rchild;//父母，左孩子，右孩子
    char c;//编码系统的字符
} HTNode, * HuffmanTree;  //动态分配数组存储哈夫曼树

typedef  char** HuffmanCode;  //动态分配数组存储哈夫曼编码表