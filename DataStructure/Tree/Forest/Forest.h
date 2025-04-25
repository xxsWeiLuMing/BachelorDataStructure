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
    int parent;
}PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;



//树的孩子链表存储表示
typedef struct CTNode {
    int child;
    struct CTNode *next;
}*ChildPtr;

typedef struct {
    TElemType data;
    ChildPtr firstChild;
}CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;
}CTree;



//孩子兄弟表示法
typedef struct CSNode {
    TElemType data;
    struct CSNode *firstChild,nextSibling;
}CSNode,*CSTree;

#endif //FOREST_H
