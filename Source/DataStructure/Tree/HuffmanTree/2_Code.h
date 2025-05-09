//
// Created by small on 2025/5/3.
//

#ifndef INC_2_CODE_H
#define INC_2_CODE_H

#include "HuffmanTree.h"
#include "tool.h"

/*inline void Code(HuffmanTree &HT, HuffmanCode &HC, int &letNum) {
    if (!HT || !HC)
        FillHfmTree(HT, HC, letNum);

    int textNum = 0; //tobetrans.txt中有index个字符
    char *text = read_tobetrans(textNum); //得到明文
    char **code = (char **) malloc((textNum + 1) * sizeof(char *));

    for (int i = 0; i < textNum; i++) {
        for (int j = 1; j <= letNum; j++) {
            if (text[i] == HT[j].letter) {
                code[i] = (char *) malloc(10 * sizeof(char));
                code[i] = HC[j];
                strcpy(code[i], "\\");
                break;
            }
        }
        if (code[i] == nullptr) {
            code[i] = (char *) malloc(2 * sizeof(char));
            code[i][0] = text[i];
            code[i][1] = '\0';
        }
    }

    write_codefile(code, textNum);
}*/

inline void Code(HuffmanTree &HT, HuffmanCode &HC, int &letNum) {
    if (!HT || !HC)
        FillHfmTree(HT, HC, letNum);

    FILE *tobetrans = fopen("tobetrans.txt", "r");
    if (!tobetrans) {
        cout << "Code()：tobetrans.txt打开失败!" << endl;
        exit(0);
    }
    FILE *codefile = fopen("codefile.txt", "w");
    if (!codefile) {
        cout << "Code()：codefile.txt打开失败!" << endl;
        exit(0);
    }


    for (char letter = fgetc(tobetrans); letter != EOF; letter = fgetc(tobetrans)) {
        bool letInHT = false;
        for (int i = 1; i <= letNum; i++) {
            if (letter == HT[i].letter || letter == HT[i].letter - 32) {
                fprintf(codefile, "%s\\", HC[i]);
                letInHT = true;
                break;
            }
        }
        /*for (int i = 1; i <= letNum &&
                        (letter != HT[i].letter || letter != HT[i].letter - 32); i++) {
            fprintf(codefile, "%s\\", HC[i]);
            letInHT = true;
        }*/
        if (!letInHT)fprintf(codefile, "%c", letter);
    }

    fclose(tobetrans);
    fclose(codefile);
}

#endif //INC_2_CODE_H
