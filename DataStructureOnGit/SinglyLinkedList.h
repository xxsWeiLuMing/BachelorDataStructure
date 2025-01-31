#pragma once

typedef char ElemType;

typedef  struct  LNode {
    ElemType data;
    struct  LNode* next;
} LNode, * LinkList;



//初始化

//创建
//遍历输出
//销毁
//判断空
//求长度
//求第i个元素的值
//求第1个值为e的元素的位序
//插入元素e到第i个
//删序第i个元素
