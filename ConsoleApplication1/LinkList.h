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
Description:����һ����Ϊlength�Ŀ�����(������)
Input:LinkList& L,int length
Return:void
***********/
void createList(LinkList& L, int length);

/***********
Function:createList()
Description:����һ����Ϊlength�Ŀ�����(˳����)
Input:LinkList& L,int length
Return:void
***********/
//void createListOrder(LinkList& L, int length);

// Status destoryList(LinkList& L);

// Status listEmpty(LinkList L);

/**********
Function:GetElem()
Description:��ȡ�����i��Ԫ�أ���ֵ��e
Input��LinkList L ,int i �� ElemType& e
Return��Status OK ��ȡ�ɹ�/ERROR ��ȡʧ��
**********/
Status getElem(LinkList L, int i, ElemType& e);

/**********
Function��listInsert����
Description:��L��indexΪiԪ��֮ǰ����Ԫ��e
Input:SqList& L��int i��ElemType e
Return:Status OK ����ɹ�/ERRPR ����ʧ��
**********/
Status listInsert(LinkList& L, int i, ElemType e);

/**********
Function��Delete����
Description:ɾ��L��indexΪi��Ԫ�أ�������Ԫ��ֵ��e
Input:SqList& L,int i��ElemType& e
Return:Status OK ɾ���ɹ�/ERROR ɾ��ʧ��
**********/
Status listDelete(LinkList& L, int i, ElemType& e);

/**********
Function:clearList()
Description:�������
Input:LinkList& L
Return:Status OK ����ɹ�/ERROR ���ʧ��
***********/
void clearList(LinkList& L);