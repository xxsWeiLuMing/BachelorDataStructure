//
// Created by small on 2025/5/3.
//

#ifndef TOOL_H
#define TOOL_H

#include "HuffmanTree.h"
#include "1_HfmCreateTree.h"

//当HT不在内存中，从HfmTree.txt创建HT
inline void FillHfmTree(HuffmanTree &HT, HuffmanCode &HC, int &letNum) {
    FILE *file = fopen("HfmTree.txt", "r");

    if (file == NULL) {
        cout << "FillHfmTree()：HfmTree.txt打开失败！" << endl;
        exit(0);
    }

    char c[30] = "0";
    unsigned int w[30] = {0};

    int i = 1;
    letNum = 0;
    int temp[3] = {};
    while (fscanf(file, "%c      %d      %d      %d      %d\n",
                  &c[i], &w[i], &temp[0], &temp[1], &temp[2]) != EOF) {
        i++;
        letNum++;
    }

    fclose(file);

    InitHfmTree(HT, w, letNum, c);
    CreteHfmTree(letNum, HT);
    CreteHfmCode(HT, HC, letNum);
    WriteHfmTree(HT, letNum);
}

inline char *read_tobetrans(int &textNum) {
    char letter;
    int count = 0;

    FILE *file = fopen("tobetrans.txt", "r");
    if (file == nullptr) {
        printf("无法打开tobetrans文件\n");
        return nullptr;
    }

    // 逐个读取文件中的字母并计数
    while (fgetc(file) != EOF) {
        count++;
    }
    fclose(file); // 关闭文件

    // 使用动态内存分配来创建一个足够大的数组来存储字母
    char *text = (char *) malloc(count * sizeof(char));
    if (text == NULL) {
        printf("内存分配失败\n");
        return nullptr;
    }

    // 重新打开文件以进行读取并将字母存储到数组中
    file = fopen("tobetrans.txt", "r");
    if (file == nullptr) {
        printf("无法打开tobetrans文件\n");
        return nullptr;
    }

    textNum = 0;
    while ((letter = fgetc(file)) != EOF)
        text[textNum++] = letter;
    fclose(file); // 关闭文件

    return text;
}

void write_codefile(char **code, int index) {
    FILE *file = fopen("codefile.txt", "w");

    if (file == NULL) {
        printf("无法打开codefile文件！");
        return;
    }

    for (int i = 0; i < index; i++) {
        fprintf(file, "%s", code[i]);
    }

    fclose(file);
}

#endif //TOOL_H
