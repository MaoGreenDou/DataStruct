#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
/**********
������������˵������Ϊ��ͷ�������i��ָ�߼�λ��
**********/

Status getElem(LinkList L, int i, ElemType& e)
{
	LinkList p = L->next;
	int j = 1;

	while (p && j < i)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i)    //ָ��Ԫ���п��ܲ����ڻ�iֵ�Ƿ�
	{
		return ERROR;
	}

	e = p->data;
	return OK;

}

/**********
��дʱ���������⣺
1.Linklist&����LinkList��
2.���������������������������㣩
**********/
Status listInsert(LinkList& L, int i, ElemType e)
{
	//linklist p = L->next;
    //int j = 1;

	LinkList p = L;
	LinkList temp = NULL;
	int j = 0;

	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}

	if (!p || j > i - 1)    //i���ڱ�+1��С��1
	{
		return ERROR;
	}

	temp = (LinkList)malloc(sizeof(LNode));
	if (!temp)
	{
		printf("OVERFLOW!");
		exit(-1);
	}
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
	
	return OK;
}

/**********
��дʱ���������⣺
1.LinkList����Linklist&
2.�ж�!(p->next)֮ǰ�Ƿ���Ҫ���ж�!p
3.ɾ��һ���ڵ���Ĳ�
**********/
Status listDelete(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	LinkList temp = NULL;
	int j = 0;

	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
	{
		if (!(p->next))
		{
			return ERROR;
		}
	}

	temp = p->next;
	p->next = temp->next;
	e = temp->data;
	free(temp);

	return OK;
}

/**********
��дʱ���������⣺
1.LinkList����LinkList&
**********/
void clearList(LinkList& L)
{
	LinkList temp = NULL;
	while (L->next)
	{
		temp = L->next;
		L->next = temp->next;
		freeNode(temp);
	}
}

void createList(LinkList& L, int length)
{
	LinkList temp = NULL;

	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
	{
		printf("OVERFLOW!");
		exit(-1);
	}
	L->next = NULL;

	for (int i = length;i > 0;--i)
	{
		temp = (LinkList)malloc(sizeof(LNode));
		if (!temp)
		{
			printf("OVERFLOW!");
			exit(-1);
		}
		printf("�����������dataֵ,���س�����:\n");
		scanf_s("%d",&(temp->data));
		getchar();    //��ջس�
		temp->next = L->next;
		L->next = temp;
	}
}

//void createListOrder(LinkList& L, int length)
//{
//	LinkList temp = NULL;
//	L = (LinkList)malloc(sizeof(LNode));
//	if (!L)
//	{
//		printf("OVERFLOW!");
//		exit(-1);
//	}
//	L->next = NULL;
//
//	for (int i = length;i > 0;--i)
//	{
//		temp = (LinkList)malloc(sizeof(LNode));
//		if (!temp)
//		{
//			printf("OVERFLOW!");
//			exit(-1);
//		}
//		printf("������������dataֵ�����س�����\n");
//		scanf("%d", &(temp->data));
//	}
//}
/**********
1.����ֵ������ֵ��Ҫ�Ϸ���e.g. getElem��iֵ����С��1
**********/




//----------����----------//

/*
createList(Linklist& L,int length)
{
    LinkList temp = NULL;
    L =  (LinkList)malloc(sizeof(LNode));
	if(!L)
	{
	    exit(-1);
	}
	L->next = null;

	for(int i=length;i>0;--i)
	{
	    temp = (LinkList)malloc(sizeof(LNode));
		if(!temp)
		{
		    exit(-1);
		}
		scanf("%d",&(temp->data));
		temp->next = L->next;
		L->next = temp;
	}
}

listInsert(LinkList L,int i,ElemType e)
{
      LinkList p  = L;
	  LinkList temp = NULL;
	  int j = 0;

	  while(p&&j<i-1)
	  {
	      p = p->next;
		  j++;
	  }

	  temp = malloc;
	  OVERFLOW;

	  tmep->data = e;
	  temp->next = p->next;
	  p->next = temp;
}

listDelete(LinkList L,int i, ElemType& e)
{
    LinkList temp = NULL;
    LinkList p = L;
	int j = 0;

	while(p&&j<i-1)
	{
	    p = p->next;
		++j;
	}

	if(!p||j>i-1)
	{
	    if(!(p->next))
		{
		    return ERROR;
		}
		temp = p->next;
		p->next = temp->next;
		e = temp->data;
		free(temp);
		temp  = NULL; //���Բ���

	}
}

clearList(LinkList& L)
{
    LinkList temp = NULL;
    while(L->next)
	{
	    temp = L->next;
		L->next = temp->next;
		free(temp);
	}
}

*/