#define _CRT_SECURE_NO_WARNINGS 

#include "ListNode.h"

//打印
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

SLTNode* BuyListNode(SLTDateType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
}

//尾插
void SListPushBuck(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newNode = BuyListNode(x);
	if ((*pphead) == NULL)
	{
		(*pphead) = newNode;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//头插
void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newNode = BuyListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//尾删
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* next = *pphead;
		SLTNode* tail = next->next;
		while (tail->next)
		{
			next = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		next->next = NULL;
	}
}
//头删
void SListPopFront(SLTNode** pphead)
{
	SLTNode* cur = (*pphead)->next;
	free(*pphead);
	(*pphead) = cur;
}

//查找一个值为x的地址
SLTNode* SListFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//修改
void SListRevise(SLTNode* pos, SLTDateType x)
{
	pos->data = x;
}
 
//或者;
//void SListRevise(SLTNode** pphead, int pos, SLTDateType x)

//在pos位置之前插入一个节点
void SListInsertFront(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	if (cur == pos)
	{
		SListPushFront(pphead, x);
		return;
	}
	SLTNode* newNode = BuyListNode(x);
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	newNode->next = pos;
	cur->next = newNode;
}
//或者
//void SListInsert(SLTNode** pphead, int pos, SLTDateType x)

//在pos位置之后插入一个节点（简单）
void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	SLTNode* newNode = BuyListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}


//在pos位置删除一个节点
void SListEase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead);
	SLTNode* cur = *pphead;
	if (cur == pos)
	{
		SListPopFront(pphead);
		return;
	}
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}

//在pos位置之后删除一个节点
void SListEaseAfter(SLTNode* pos)
{
	assert(pos->next);
	SLTNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}

//销毁链表
void SListDestory(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}