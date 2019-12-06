#pragma once
#define LIST_INIT_SIZE 80    //��ʼ������
#define LISTINCREMENT 10    //��������
#define OK 1
#define ERROR 1
#define ElemType int
#define Status int

Status compare(ElemType, ElemType);
Status vist();

typedef struct
{
	ElemType* elem;    //�洢�ռ����ַ
	int length;
	int listsize;
}SqList;

/*
ADT List
   {
	D={}
	R={}
	P={
	//��ʼ��������
	Initlist
	DestroyList

	//�����Ͳ���
	ListEmpty
	ListLength
	PriorElem
	NextElem
	GetElem
	LocateElem
	ListTraverse

	//�ӹ��Ͳ���
	ClearList
	PutElem
	ListInsert
	ListDelete
	}
}
*/

Status initList(SqList& L);    //����˳���
// Status destroyList(SqList& L);    //����˳���

Status listEmpty(SqList L);    //�ж�˳���ǿ�
// Status listLength(SqList L);    //���˳�����
// ElemType priorElem(SqList L, ElemType cru_e, ElemType& pre_e);    //��õ�ǰԪ��ǰ��
// ElemType nextElem(SqList L, ElemType cru_e, ElemType& next_e);    //��õ�ǰԪ�غ��
// ElemType getElem(SqList L, int i, ElemType& e);    //���ָ��indexԪ��
int locateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));    //������������ĵ�һ��Ԫ��
// void listTraverse(SqList L,Status (*vist)());    //����˳���

// Status clearList(SqList& L);    //���˳���
// Status putElem(SqList& L, int i, ElemType& e);    //�ı�ָ��Ԫ��ֵ
Status listInsert(SqList& L, int i, ElemType e);    //ָ��λ�ò�����Ԫ��
Status listDelete(SqList& L, int i, ElemType& e);    //ɾ��ָ��λ��Ԫ��