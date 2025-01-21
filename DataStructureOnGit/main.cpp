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

	L.Insert(5, '2');
	L.Traverse();

	//cout << L.elem[5] << endl;
}