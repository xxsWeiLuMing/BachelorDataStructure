//
// Created by small on 2025/4/26.
//
#include "HuffmanTree.h"
#include "HfmCode.h"
#include "HfmFIle.h"

Status Func() {
    int letterNum=26;//26个字母
    int nodeNum=2*letterNum-1;//2*26-1个结点
    char english[28]="0abcdefghijklmnopqrstuvwxyz";
    unsigned int weight[28]={0,8,1,3,4,13,2,2,6,7,1,1,4,2,6,7,2,1,6,6,9,2,1,2,1,2,1};

    HuffmanCode HC=nullptr;//哈夫曼编码表
    HuffmanTree HT=nullptr;//哈夫曼树

    char *eng=&english[0];
    unsigned int *w=&weight[0];

    char runState='0';
    while (true) {
        cout<<"按E退出，按I建树，按D译码codefile.txt，"
              "按P打印codefi1e、并写入codeprint，"
              "按T打印哈夫曼树同时写入文件treeprint"<<endl;
        cout<<"请输入：";
        cin>>runState;

        if (runState == 'E'||runState == 'e')break;

        if (runState =='I'||runState == 'i') {
            InitHfmTree(HT,w,letterNum,eng);
            CreteHfmTree(letterNum,HT);
            CreteHfmCode(HT,HC,letterNum);
            WriteHfmTree(HT,letterNum);
        }
    }

    return OK;
}
