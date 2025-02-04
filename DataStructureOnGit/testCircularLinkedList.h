#pragma once
#include"CircularLinkedList.h"

void testCircularLinkedList()
{
    LinkList H;
    Init(H);
    cout << "IsEmpty:" << IsEmpty(H) << endl;

    Create(4, H);
    cout << "Init,Create,Traverse:";
    Traverse(H);

    Destroy(H);
    cout << "Destroy,IsEmpty:" << IsEmpty(H) << endl;

    /*cout << "Length:" << Length(H) << endl;*/
}