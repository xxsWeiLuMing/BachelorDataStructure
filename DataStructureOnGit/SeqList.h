#pragma once
//顺序表

typedef char ElemType;

#define  LIST_INIT_SIZE  100 //存储空间的初始分配量
#define  LISTINCREMENT  10 //存储空间的分配增量

class SeqList
{
public:
    ElemType* elem; //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
    


    Status Init()
    {
        this->elem = (ElemType*)malloc(
            LIST_INIT_SIZE * sizeof(ElemType));

        if (!this->elem) exit(OVERFLOW);

        this->length = 0;
        this->listsize = LIST_INIT_SIZE;

        return OK;
    }

    Status Create(ElemType a[], int n)
    {
        if (!this->elem) exit(ERROR);

        for (int i = 0; i <= n; i++)this->elem[i] = a[i];

        this->length = n;
        this->listsize = LIST_INIT_SIZE;

        return OK;
    }

    Status Traverse()
    {
        if (this->length == 0)return ERROR;

        for (int i = 0; i < this->length; i++)
            cout << this->elem[i] << " ";

        cout << endl;

        return OK;
    }

    void Destroy()
    {
        free(this->elem);
    }

    Status IsEmpty()
    {
        return (this->length == 0);
    }

    int Length()
    {
        return(this->length);
    }

    Status GetElem(int i, ElemType& e)
    {
        if (i<1 || i>this->length)return ERROR;

        e = this->elem[i - 1];//自然语言中没有“第0个”一说，故第i个的编号为i-1

        return OK;
    }

    Status LocateElem(ElemType e)
    {
        for (int i = 0; i < this->length; i++)
        {
            if (this->elem[i] == e)return i + 1;
        }

        return ERROR;
    }
};