#pragma once

#include"CircularLinkedList.h"

void Joseph() 
{
    int m, n;

    cout << "输入报数上限m，然后输入人数n（n<30）:";
    cin >> m >> n;
    cout << endl;

    CirLinkList L;
    InitList(L);
    cout << "输入" << n << "个人的密码:";
    CreateList(L, n);
    //TraverseList(L);

    CirLinkList p = L->next;
    int pos[30] = { 0 };
    for (int i = 1; i <= n; i++)
    {
        pos[p->data - '0'] = i;
        p = p->next;
    }

    p = L->next;
    while (L->next)
    {
        
        for (int i = m; i > 0; i--)
        {
            p = p->next;
        }
            
        cout << pos[p->data-'0'] << " ";

        ElemType e;
        p = p->next;
        ListDelete(L, m % n, e);
        m = e-'0';
        n--;
    }
}