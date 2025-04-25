//
// Created by small on 2025/4/25.
//

#ifndef THREADEDBINARYTREE_H
#define THREADEDBINARYTREE_H
#include"../../general.h"

typedef enum {Link,Thread}PointerTag;
typedef char TElemType;
typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lChild, *rChild;
    PointerTag lTag, rTag;
}BiThrNode, *BiThrTree;

inline void InThreading(BiThrTree p) {
    if (p) {
        BiThrTree pre = nullptr;
        InThreading(p->lChild);
        if (!p->lChild) {
            p->lTag=Thread;
            p->lChild=pre;
        }
        if (!pre->rChild) {
            pre->rTag=Thread;
            pre->rChild=p;
        }
        pre=p;
        InThreading(p->rChild);
    }
}

//空线索化二叉树
inline Status InOrderThreading(BiThrTree &Thrt,BiThrTree T) {
    if (!((Thrt=static_cast<BiThrTree>(malloc(sizeof(BiThrNode))))))
        exit((OVERFLOW));
    Thrt->lTag = Link;
    Thrt->rTag = Thread;

    if (T==nullptr)Thrt->lChild=Thrt;
    else {
        Thrt->lChild=T;
        BiThrTree pre = Thrt;
        InThreading(T);
        pre->rChild=Thrt;
        pre->rTag=Thread;
        Thrt->rChild=pre;
    }

    return OK;
}

//中序遍历线索化二叉树
inline Status InOrderTraverse(BiThrTree T,Status(*Visit)(TElemType e)) {
    BiThrTree p = T->lChild;

    while (p!=T) {
        while (p->lTag==Link)p=p->lChild;
        if (!Visit(p->data))return ERROR;
        while (p->rTag==Thread&&p->rChild!=T) {
            p=p->rChild;
            Visit(p->data);
        }
        p=p->rChild;
    }

    return OK;
}

#endif //THREADEDBINARYTREE_H
