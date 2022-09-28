#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int SLTDateType;

typedef struct SeqListNode
{
	SLTDateType data;
	struct ListNode* next;
}SLTNode;

//打印
void SListPrint(SLTNode* phead);

//开辟新空间
SLTNode* BuyListNode(SLTDateType x);

//尾插
void SListPushBuck(SLTNode** pphead, SLTDateType x);
//头插
void SListPushFront(SLTNode** pphead, SLTDateType x);

//尾删
void SListPopBack(SLTNode** pphead);
//头删
void SListPopFront(SLTNode** pphead);

//查找一个值为x的地址
SLTNode* SListFind(SLTNode* phead, SLTDateType x);

//修改
void SListRevise(SLTNode* pos, SLTDateType x);
//或者
//void SListRevise(SLTNode** pphead, int pos, SLTDateType x);

//在pos位置之前插入一个节点
void SListInsertFront(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//或者
//void SListInsertFront(SLTNode** pphead, int pos, SLTDateType x);

//在pos位置之后插入一个节点（简单）
void SListInsertAfter(SLTNode* pos, SLTDateType x);


//在pos位置删除一个节点
void SListEase(SLTNode** pphead, SLTNode* pos);

//在pos位置之后删除一个节点
void SListEaseAfter(SLTNode* pos);

//销毁链表
void SListDestory(SLTNode** pphead);