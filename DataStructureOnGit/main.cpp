#include<iostream>
#include<malloc.h>
using namespace std;

#include"general.h"
#include"SeqList.h"

int main()
{
	SeqList L;
	char a[10] = { '0','1','2','3','4','5','6','7','8','9' };

	Seq_InitList(L);
	Seq_CreateList(L, a, 10);

	Seq_ListTraverse(L);
	Seq_DestroyList(L);
	Seq_ListTraverse(L);
}