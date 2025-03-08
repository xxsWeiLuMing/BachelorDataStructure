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

    int pos = 1;
    while (n > 0)
    {
        for (int i = 1; ;)
        {
            if (i == m && p->data != '*')break;

            if (p->data == '*')p = p->next;                         
            else
            {
                i++;
                p = p->next;
            }
            pos++;
            if (p == L->next)pos = 1;           
        }

        ElemType e = p->data;
        p->data = '*';

        cout << pos << " ";       
        
        m = e-'0';
        n--;
    }
}