#pragma once
//顺序表

typedef int ElemType;

#define  LIST_INIT_SIZE  100 //存储空间的初始分配量
#define  LISTINCREMENT  10 //存储空间的分配增量

typedef  struct SqList {
    ElemType* elem; //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
} SqList;