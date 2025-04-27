//
// Created by small on 2025/4/21.
//
#include "../../DataStructure/LinearList/SinglyLinkedList.h"

void Delete(LinkList&L) {
    LinkList cur=L->next;

    while (cur!= nullptr) {
        LinkList del=cur->next;
        LinkList priorDel=cur;

        while (del!=nullptr) {
            if (abs(del->data)==abs(cur->data)) {
                priorDel->next=del->next;
                free(del);
                del=priorDel->next;
            }
            else {
                priorDel=del;
                del=del->next;
            }
        }

        cur=cur->next;
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
    DisplayList(L);
}
