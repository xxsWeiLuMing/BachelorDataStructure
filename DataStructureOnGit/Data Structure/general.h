#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;//Status是函数的类型，其值是函数结果状态代码