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

//��ӡ
void SListPrint(SLTNode* phead);

//�����¿ռ�
SLTNode* BuyListNode(SLTDateType x);

//β��
void SListPushBuck(SLTNode** pphead, SLTDateType x);
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDateType x);

//βɾ
void SListPopBack(SLTNode** pphead);
//ͷɾ
void SListPopFront(SLTNode** pphead);

//����һ��ֵΪx�ĵ�ַ
SLTNode* SListFind(SLTNode* phead, SLTDateType x);

//�޸�
void SListRevise(SLTNode* pos, SLTDateType x);
//����
//void SListRevise(SLTNode** pphead, int pos, SLTDateType x);

//��posλ��֮ǰ����һ���ڵ�
void SListInsertFront(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//����
//void SListInsertFront(SLTNode** pphead, int pos, SLTDateType x);

//��posλ��֮�����һ���ڵ㣨�򵥣�
void SListInsertAfter(SLTNode* pos, SLTDateType x);


//��posλ��ɾ��һ���ڵ�
void SListEase(SLTNode** pphead, SLTNode* pos);

//��posλ��֮��ɾ��һ���ڵ�
void SListEaseAfter(SLTNode* pos);

//��������
void SListDestory(SLTNode** pphead);