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
    //ElemType pos[30] = { '0' };
    //for (int i = 1; i <= n; i++)
    //{
    //    pos[i] = p->data;
    //    p = p->next;
    //}

    //p = L->next;
    while (n > 1)
    {
        int pos = 1;
        for (int i = m; i > 0;)
        {
            if (p == L->next)pos = 1;
            if (p->data == '*')p = p->next;                         
            else
            {
                i--;
                p = p->next;
            }
            pos++;
        }

        ElemType e = p->data;
        p->data = '*';

        cout << pos << " ";

        
        
        CirLinkList q = p->next;
        
        m = e-'0';
        n--;
    }
}