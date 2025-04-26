//
// Created by small on 2025/4/26.
//

#ifndef HFMWRITEFILE_H
#define HFMWRITEFILE_H

#include "HuffmanTree.h"

inline void WriteHfmTree(HuffmanTree HT,int n)//把哈夫曼树写入文件
{
    FILE* file=fopen("HfmTree.txt", "w");

    if (file == NULL) {
        printf("无法打开HfmTree文件！");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        fprintf(file, "%c %d\n", HT[i].letter, HT[i].weight);
    }
    fclose(file);
}
#endif //HFMWRITEFILE_H
