//
// Created by small on 2025/4/26.
//
#include "HuffmanTree.h"
#include "HfmCode.h"
#include "HfmFIle.h"

void Func() {
    int letterNum=26;//26个字母
    int nodeNum=2*letterNum-1;//2*26-1个结点
    char english[28]="0abcdefghijklmnopqrstuvwxyz";
    unsigned int weight[28]={0,8,1,3,4,13,2,2,6,7,1,1,4,2,6,7,2,1,6,6,9,2,1,2,1,2,1};

    HuffmanCode HC=nullptr;//哈夫曼编码表
    HuffmanTree HT=nullptr;//哈夫曼树

    char *eng=&english[0];
    unsigned int *w=weight;

    InitHfmTree(HT,w,letterNum,eng);
    CreteHfmTree(letterNum,HT);
    CreteHfmCode(HT,HC,letterNum);
    WriteHfmTree(HT,letterNum);
}
