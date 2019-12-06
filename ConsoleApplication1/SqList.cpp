#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

/**********
Function：compare()
Description:比较op1，op2大小，op1大返回1，否则为0
Input:ElemType op1,ElemType op2
Return:Status
**********/
Status compare(ElemType op1, ElemType op2)
{
	if (op1 <= op2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/**********
Function：initList()
Description:建立一个空表，分配空间LIST_INIT_SIZE
Input:SqList& L
Return:Status OK 建立空表成功/-1 建立空表失败
**********/
Status initList(SqList& L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)    //内存不足
	{
		exit(-1);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	
	return OK;
}

/**********
Function：listEmpty（）
Description:顺序表判空
Input:SqList L
Return:Status OK 非空/ERROR 空
**********/
Status listEmpty(SqList L)
{
	if (L.length > 0)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/**********
Function：locate（）
Description:返回L中与e满足comapare关系的第一个元素下标
Input:Sqlist L，ElemType e，Status （*compare）
Return:int i 元素下表/ERROR未找到
**********/
int locateElem(SqList L, ElemType e, Status (*compare)(ElemType,ElemType))
{
	ElemType* p = L.elem;    
    int i = 1;

	if (listEmpty(L))    //可以不判空
	{
		
		while (i <= L.length && !(*compare)(*p++, e))
		{
			++i;
		}

		if (i <= L.length)
		{
			return i;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

/**********
编写时遇到的问题：
1.插入前判断表非满
2.插入index合法
**********/
/**********
Function：listInsert（）
Description:向L中index为i元素之前插入元素e
Input:SqList& L，int i，ElemType e
Return:Status OK 插入成功/ERRPR 插入失败
**********/
Status listInsert(SqList& L, int i, ElemType e)
{
	if (i >= 1 && i <= L.length + 1 )    //从第一个元素之前到最后一个元素之后可以插入,且表非满
	{
		if (L.length >= L.listsize)
		{
			ElemType* newBase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));    //Warning: Arithmetic overflow
			if (!newBase)
			{
				printf("Overflow!\n");
				exit(-1);
			}
			L.elem = newBase;
			L.listsize += LISTINCREMENT;
			//realloc 会自动赋值内存中的内容
			
			ElemType* insertPos = &(L.elem[i - 1]);
			for (ElemType* p = &(L.elem[L.length - 1]);p >= insertPos;--p)
			{
				*(p + 1) = *p;
			}
			*insertPos = e;
			++L.length;

			return OK;
		}
		else
		{
			ElemType* insertPos = &(L.elem[i - 1]);
			for (ElemType* p = &(L.elem[L.length - 1]);p >= insertPos;--p)
			{
				*(p + 1) = *p;
			}
			*insertPos = e;
			++L.length;

			return OK;
		}
	}
	else
	{
		printf("insert index i is not available!");
		return ERROR;
	}
}

/**********
Function：Delete（）
Description:删除L中index为i的元素，并保存元素值至e
Input:SqList& L,int i，ElemType& e
Return:Status OK 删除成功/ERROR 删除失败
**********/
Status listDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length)    //可以不用判空
	{
		return ERROR;
	}
	else
	{
		ElemType* p = &(L.elem[i - 1]);
		ElemType* q = &(L.elem[L.length - 1]);
		e = *p;
		for (++p;p <= q;++p)
		{
			*(p - 1) = *p;
			
		}
		--L.length;
		return OK;
		
	}
}

/*
1.分配内存有可能失败
2.删除要判空
3.增加要判满
4.删除要释放
*/