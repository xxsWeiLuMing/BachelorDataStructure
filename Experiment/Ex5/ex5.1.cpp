//
// Created by small on 2025/4/21.
//
#include "../../DataStructure/LinearList/SinglyLinkedList.h"

void Delete(LinkList&L) {
    LinkList current=L->next;

    while (current!= nullptr) {
        LinkList mayDelete=current->next;
        LinkList priorMayDelete=current;

        while (mayDelete!=nullptr) {
            if (abs(mayDelete->data)==abs(current->data)) {
                priorMayDelete->next=mayDelete->next;
                free(mayDelete);
                mayDelete=priorMayDelete->next;
            }
            else {
                priorMayDelete=mayDelete;
                mayDelete=mayDelete->next;
            }
        }

        current=current->next;
    }
}

void Func() {
    LinkList L;
    InitList(L);
    int m=6;
    cout<<"输入"<<m<<"个数:";
    CreateList(L,m);
    cout<<endl;

    Delete(L);
    TraverseList(L);
}
