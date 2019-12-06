// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "SqList.h"

int main()
{
	SqList sq;
	int e = -1;

	//Demo01.SqList初始化
	initList(sq);
	for (int i = 0;i < sq.listsize;i++)
	{
		sq.elem[i] = i;
		sq.length++;
	}
	for (int i = 0;i < sq.length;i++)
	{
		printf("initial sq[%d]:%d\n", i + 1, sq.elem[i]);
	}

	//Demo02.Sqlist定位算法
	printf("first index %d\n",locateElem(sq, 30, &compare));

	//Demo03.SqList插入操作
	listInsert(sq, sq.length, 100);
	for (int i = 0;i < sq.length;i++)
	{
		printf("ListInsert sq[%d]:%d\n", i + 1, sq.elem[i]);
	}

	//Demo04.SqList删除操作
	listDelete(sq, 1, e);
	for (int i = 0;i < sq.length;i++)
	{
		printf("ListDelete sq[%d]:%d\n", i + 1, sq.elem[i]);
	}
	printf("%d has been delete", e);

}

/*
ADT List{
    D={}
	R={}
	P={
	//初始化和销毁
	Initlist
	DestroyList

	//引用型操作
	ListEmpty
	ListLength
	PriorElem
	NextElem
	GetElem
	LocateElem
	ListTraverse

	//加工型操作
	ClearList
	PutElem
	ListInsert
	ListDelete
	}

}
*/