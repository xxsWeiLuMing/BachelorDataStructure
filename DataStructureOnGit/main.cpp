#include<iostream>
#include<malloc.h>
using namespace std;

#include"general.h"
#include"SeqList.h"

int main()
{
	SeqList L;
	char a[10] = { '0','1','2','3','4','5','6','7','8','9' };

	L.Init();
	L.Create(a, 10);
	L.Traverse();

	SeqList* pL = &L;

	/*ElemType e;
	L.GetElem(5, e);*/
	cout << pL->elem[5] << endl;
}