#pragma once
#define LIST_INIT_SIZE 80    //初始分配量
#define LISTINCREMENT 10    //分配增量
#define OK 1
#define ERROR 1
#define ElemType int
#define Status int

Status compare(ElemType, ElemType);
Status vist();

typedef struct
{
	ElemType* elem;    //存储空间基地址
	int length;
	int listsize;
}SqList;

/*
ADT List
   {
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

Status initList(SqList& L);    //建立顺序表
// Status destroyList(SqList& L);    //销毁顺序表

Status listEmpty(SqList L);    //判定顺序表非空
// Status listLength(SqList L);    //获得顺序表长度
// ElemType priorElem(SqList L, ElemType cru_e, ElemType& pre_e);    //获得当前元素前驱
// ElemType nextElem(SqList L, ElemType cru_e, ElemType& next_e);    //获得当前元素后继
// ElemType getElem(SqList L, int i, ElemType& e);    //获得指定index元素
int locateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));    //获得满足条件的第一个元素
// void listTraverse(SqList L,Status (*vist)());    //遍历顺序表

// Status clearList(SqList& L);    //清空顺序表
// Status putElem(SqList& L, int i, ElemType& e);    //改变指定元素值
Status listInsert(SqList& L, int i, ElemType e);    //指定位置插入新元素
Status listDelete(SqList& L, int i, ElemType& e);    //删除指定位置元素