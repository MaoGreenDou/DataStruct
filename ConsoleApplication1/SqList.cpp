#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

/**********
Function��compare()
Description:�Ƚ�op1��op2��С��op1�󷵻�1������Ϊ0
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
Function��initList()
Description:����һ���ձ�����ռ�LIST_INIT_SIZE
Input:SqList& L
Return:Status OK �����ձ�ɹ�/-1 �����ձ�ʧ��
**********/
Status initList(SqList& L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)    //�ڴ治��
	{
		exit(-1);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

	return OK;
}

/**********
Function��listEmpty����
Description:˳����п�
Input:SqList L
Return:Status OK �ǿ�/ERROR ��
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
Function��locate����
Description:����L����e����comapare��ϵ�ĵ�һ��Ԫ���±�
Input:Sqlist L��ElemType e��Status ��*compare��
Return:int i Ԫ���±�/ERRORδ�ҵ�
**********/
int locateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	ElemType* p = L.elem;
	int i = 1;

	//���Բ��п�
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

/**********
��дʱ���������⣺
1.����ǰ�жϱ����
2.����index�Ϸ�
**********/
/**********
Function��listInsert����
Description:��L��indexΪiԪ��֮ǰ����Ԫ��e
Input:SqList& L��int i��ElemType e
Return:Status OK ����ɹ�/ERRPR ����ʧ��
**********/
Status listInsert(SqList& L, int i, ElemType e)
{
	if (i >= 1 && i <= L.length + 1)    //�ӵ�һ��Ԫ��֮ǰ�����һ��Ԫ��֮����Բ���,�ұ����
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
			//realloc ���Զ���ֵ�ڴ��е�����

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
Function��Delete����
Description:ɾ��L��indexΪi��Ԫ�أ�������Ԫ��ֵ��e
Input:SqList& L,int i��ElemType& e
Return:Status OK ɾ���ɹ�/ERROR ɾ��ʧ��
**********/
Status listDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length)   
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
1.�����ڴ��п���ʧ��
2.ɾ��Ҫ�С��ա�
3.ɾ��Ҫ�ͷ�    ��2 3��
4.����Ҫ�С�����
5.����Ҫ���Ƿ����    ��4 5 1��
6.˳��ṹ���ʣ�������ʣ���index�Ƿ�Ϸ�
*/



/**********
��ϰ
**********/

/*
Status initSqList(SqList& L )
{
    L.elem = (ElemType*)malloc(N*sizeof(ElemType));
	//�ж��Ƿ����ɹ�

	L.size = N;
	L.length = 0 ;
}

Status insertSqList(SqList& L,int i, Elemtype e)
{
    ElemType* temp = NULL;
	ElemType* end = NULL;

    if(i<1 || i>length+1)
	{
	    index is not avaluable!
	}
	else
	{
	    if(L.size == L.length)
		{
		    ������ڴ棬�ٲ���
		}
		else
		{
		    temp = &(L.elem[i-1]);
			end = &L.elem[L.length - 1];

			for(end;end>=temp;end--)
			{
			    *(end+1) = *end;
			}

			L.elem[i-1] = a;
			L.length ++;

		}
	}
}

Status delete(SqList& L,int i,ElemType& e)
{
    if(i<1 || i>L.length)
	{
	    i is not avaluable!
	}
	else
	{
	    if(L.length == 0 );//���Բ����п�
		ElemType* temp = NULL;
		ElemType* end = NULL;

		temp = L.elem[i-1];
		end = L.elem[L.length - 1];
		e = *temp;

		for(temp;temp<end;temp++)
		{
		    *temp = *(temp+1);
		}

		free(temp);
		temp = NULL; // ������Ӧ����


	}
}

*/