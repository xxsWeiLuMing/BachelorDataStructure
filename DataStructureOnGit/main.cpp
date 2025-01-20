#include<iostream>
#include<malloc.h>
using namespace std;

#include"general.h"
#include"SeqList.h"

int main()
{
	SeqList L;
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

	Seq_InitList(L);
	Seq_CreateList(L, a, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << L.elem[i];
	}
}