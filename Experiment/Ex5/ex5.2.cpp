//
// Created by small on 2025/4/21.
//
#include "../../DataStructure/LinearList/SinglyLinkedList.h"

void Divide(LinkList &B,LinkList &C) {
    LinkList pC=C->next;

    while (pC!= nullptr) {
        LinkList pA=pC;
        pC=pC->next;
        if (pC==nullptr)break;
        pA->next=pC->next;

        LinkList pB = pC;
        pC=pC->next;
        if (B->next==nullptr)pB->next=nullptr;
        else pB->next=B->next;
        B->next=pB;
    }
}

void Divide(LinkList &A,LinkList &B,LinkList C) {
    LinkList pC=C->next;
    LinkList pA=A;

    while (pC!= nullptr) {
        auto temp=static_cast<LinkList>(malloc(sizeof(LNode)));
        if (temp==nullptr)exit(OVERFLOW);
        temp->next=nullptr;

        pA->next=temp;
        pA=pA->next;
        pA->data=pC->data;

        pC=pC->next;
        if (pC==nullptr)break;

        temp=static_cast<LinkList>(malloc(sizeof(LNode)));
        if (temp==nullptr)exit(OVERFLOW);

        LinkList pB=temp;
        pB->data=pC->data;
        pC=pC->next;
        if (B->next==nullptr)pB->next=nullptr;
        else pB->next=B->next;
        B->next=pB;
    }
}

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

    //Divide(B,C);
    Divide(A,B,C);

    cout<<"A:";
    DisplayList(A);
    cout<<"B:";
    DisplayList(B);
    cout<<"C:";
    DisplayList(C);
}