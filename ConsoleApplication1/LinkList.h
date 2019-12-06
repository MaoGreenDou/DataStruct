#pragma once
#define ElemType int
#define Status int
#define OK 1
#define ERROR 0

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

/***********
Function:createList()
Description:建立一个长为length的空链表(逆序建立)
Input:LinkList& L,int length
Return:void
***********/
void createList(LinkList& L, int length);

/***********
Function:createList()
Description:建立一个长为length的空链表(顺序建立)
Input:LinkList& L,int length
Return:void
***********/
//void createListOrder(LinkList& L, int length);

// Status destoryList(LinkList& L);

// Status listEmpty(LinkList L);

/**********
Function:GetElem()
Description:获取链表第i个元素，赋值给e
Input：LinkList L ,int i ， ElemType& e
Return：Status OK 获取成功/ERROR 获取失败
**********/
Status getElem(LinkList L, int i, ElemType& e);

/**********
Function：listInsert（）
Description:向L中index为i元素之前插入元素e
Input:SqList& L，int i，ElemType e
Return:Status OK 插入成功/ERRPR 插入失败
**********/
Status listInsert(LinkList& L, int i, ElemType e);

/**********
Function：Delete（）
Description:删除L中index为i的元素，并保存元素值至e
Input:SqList& L,int i，ElemType& e
Return:Status OK 删除成功/ERROR 删除失败
**********/
Status listDelete(LinkList& L, int i, ElemType& e);

/**********
Function:clearList()
Description:请空链表
Input:LinkList& L
Return:Status OK 清除成功/ERROR 清除失败
***********/
void clearList(LinkList& L);