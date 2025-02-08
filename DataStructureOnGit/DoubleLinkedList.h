#pragma once
#include"general.h"
#include<iostream>
#include<malloc.h>
using namespace std;

typedef char ElemType;
typedef  struct  DoubleLNode {
    ElemType data;
    struct  DoubleLNode* prior;
    struct  DoubleLNode* next;
    int freq = 0;
} DoubleLNode, * DoubleLinkList;