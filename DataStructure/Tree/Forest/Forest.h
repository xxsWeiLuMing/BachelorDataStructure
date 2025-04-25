//
// Created by small on 2025/4/25.
//

#ifndef FOREST_H
#define FOREST_H

//树的双亲表示
#define MAX_TREE_SIZE 100
typedef char TElemType;
typedef struct PTNode {
    TElemType data;
    int parent;//双亲位置域
}PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int root,num;//根结点的位置和结点个数
}PTree;



//树的孩子链表存储表示
typedef struct CTNode {
    int child;
    struct CTNode *next;
}*ChildPtr;

typedef struct {
    TElemType data;
    ChildPtr firstChild;//孩子链表头指针
}CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int num,root;//结点数和根结点的位置
}CTree;



//孩子兄弟表示法
typedef struct CSNode {
    TElemType data;
    struct CSNode *firstChild,nextSibling;
}CSNode,*CSTree;

#endif //FOREST_H
