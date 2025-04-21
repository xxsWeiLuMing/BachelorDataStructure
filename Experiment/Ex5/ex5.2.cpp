//
// Created by small on 2025/4/21.
//
#include "../../DataStructure/LinearList/SinglyLinkedList.h"

void Func() {
    LinkList C;
    InitList(C);

    int lenC=7;
    cout<<"输入"<<lenC<<"个数：";
    CreateList(C,lenC);
    cout<<endl;

    LinkList A,B;
    InitList(A);
    InitList(B);
    LinkList pA=A,pB=A;
    LinkList pC=C->next;

    while (pC!= nullptr) {
        pA->next=pC;
        pA=pA->next;
        pC=pC->next;

        if (pC==nullptr)break;

        pB=pC;
        if (B->next==nullptr) {
            if (pC==nullptr)break;
            pC=pC->next;
            pB->next=nullptr;
            B->next=pB;
        }
        else {
            if (pC==nullptr)break;
            pC=pC->next;
            pB->next=B->next;
            B->next=pB;
        }
    }

    cout<<"A:";
    TraverseList(A);

    cout<<"B:";
    TraverseList(B);
    cout<<endl;
}