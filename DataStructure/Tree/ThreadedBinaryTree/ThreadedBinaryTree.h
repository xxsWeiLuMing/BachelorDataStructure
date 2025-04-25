//
// Created by small on 2025/4/25.
//

#ifndef THREADEDBINARYTREE_H
#define THREADEDBINARYTREE_H

typedef enum {Link,Thread}PointerTag;
typedef char TElemType;
typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lChild, *rChild;
    PointerTag lTag, rTag;
}BiThrNode, *BiThrTree;

#endif //THREADEDBINARYTREE_H
