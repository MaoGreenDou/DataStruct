#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
/**********
本例中无特殊说明，均为带头结点链表，i均指逻辑位置
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

	if (!p || j > i)    //指定元素有可能不存在或i值非法
	{
		return ERROR;
	}

	e = p->data;
	return OK;

}

/**********
编写时遇到的问题：
1.Linklist&还是LinkList？
2.插入操作分三步（不包括建立结点）
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

	if (!p || j > i - 1)    //i大于表长+1或小于1
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
编写时遇到的问题：
1.LinkList不是Linklist&
2.判断!(p->next)之前是否需要先判断!p
3.删除一个节点分四步
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
编写时遇到的问题：
1.LinkList还是LinkList&
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
		printf("请输入插入结点data值,按回车结束:\n");
		scanf_s("%d",&(temp->data));
		getchar();    //清空回车
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
//		printf("请输入插入结点的data值，按回车结束\n");
//		scanf("%d", &(temp->data));
//	}
//}
/**********
1.访问值（输入值）要合法：e.g. getElem的i值不能小于1
**********/




//----------练手----------//

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
		temp  = NULL; //可以不用

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