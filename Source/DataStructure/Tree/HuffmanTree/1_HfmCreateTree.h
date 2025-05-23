//
// Created by small on 2025/5/3.
//

#ifndef HFMCREATETREE_H
#define HFMCREATETREE_H

#include <cstring>
#include <climits>

#include "HuffmanTree.h"

//选出最小权和次小权
inline void WeightSelect(HuffmanTree HT, int i, int &s1, int &s2) {
    unsigned int small1 = INT_MAX; //最小权
    unsigned int small2 = INT_MAX; //次小权

    for (int j = 1; j < i; j++) {
        if (HT[j].parent == 0) {
            //未创建完毕的结点parent为0
            if (HT[j].weight < small1) {
                small2 = small1;
                small1 = HT[j].weight;
                s2 = s1;
                s1 = j;
            } else if (HT[j].weight < small2) {
                small2 = HT[j].weight;
                s2 = j;
            }
        }
    }

    if (s1 > s2) {
        s1 += s2;
        s2 = s1 - s2;
        s1 -= s2;
    } //保持标号s1小于s2
}

inline void CreteHfmTree(int letNum, HuffmanTree &HT) {
    int nodeNum = 2 * letNum - 1;
    for (int i = letNum + 1; i <= nodeNum; i++) {
        int s1 = 0, s2 = 0;

        WeightSelect(HT, i, s1, s2);

        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lChild = s1; //左孩子是最小权
        HT[i].rChild = s2; //右孩子是次小权
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

inline Status InitHfmTree(HuffmanTree &HT, unsigned int *w, int letNum, char *let) {
    if (letNum <= 1 || letNum > 26)return ERROR;

    int nodeNum = 2 * letNum - 1;
    HT = static_cast<HuffmanTree>(malloc((nodeNum + 1) * sizeof(HTNode)));
    if (!HT)exit(OVERFLOW);

    HuffmanTree temp;
    int i;
    for (temp = HT, i = 0; i <= letNum; ++i, ++temp, ++w, ++let) //字母和其权值顺序填入HT
        *temp = {*w, 0, 0, 0, *let};
    for (; i <= nodeNum; ++i, ++temp) //从第n+1个结点开始，把结点的元素全部初始化为空值
        *temp = {0, 0, 0, 0, ' '};

    return OK;
}

inline void CreteHfmCode(HuffmanTree HT, HuffmanCode &HC, int letNum) {
    HC = static_cast<HuffmanCode>(malloc((letNum + 1) * sizeof(char *)));
    if (!HC)exit(OVERFLOW);

    char *code = static_cast<char *>(malloc(letNum * sizeof(char)));
    code[letNum - 1] = '\0';

    for (int i = 1; i <= letNum; ++i) {
        int start = letNum - 1;
        for (unsigned int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
            //根节点parent为0
            if (HT[f].lChild == c)code[--start] = '0';
            else code[--start] = '1';
        }

        HC[i] = (char *) malloc((letNum - start) * sizeof(char));
        strcpy(HC[i], &code[start]);
    }

    free(code);
}

//把哈夫曼树写入文件
inline void WriteHfmTree(HuffmanTree HT, int letNum) {
    FILE *file = fopen("./HfmTree.txt", "w");

    if (file == nullptr) {
        printf("WriteHfmTree()：HfmTree.txt打开失败！");
        exit(0);
    }

    for (int i = 1; i <= letNum; i++) {//i <= 2*letNum-1;
        fprintf(file, "%c      %d      %d      %d      %d\n",
                HT[i].letter, HT[i].weight, HT[i].parent, HT[i].lChild, HT[i].rChild);
    }
    //fprintf(file,"letter weight parent lChild rChild\n");

    fclose(file);
}

#endif //HFMCREATETREE_H
