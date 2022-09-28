#define _CRT_SECURE_NO_WARNINGS 

#include "ListNode.h"

void test1()
{
	SLTNode* ln=NULL;
	SListPushBuck(&ln, 1);
	SListPushBuck(&ln, 2);
	SListPushBuck(&ln, 3);
	SListPushFront(&ln, 4);
	//SListPopFront(&ln);

	SListRevise(SListFind(ln, 2), 10);
	SListInsertFront(&ln, SListFind(ln, 3), 6);//4 1 10 6 3
	SListInsertAfter(SListFind(ln, 1), 9);//4 1 9 10 6 3
	SListEase(&ln, SListFind(ln, 4));//1 9 10 6 3
	SListEaseAfter(SListFind(ln, 1));

	SListPrint(ln);
	
	SListDestory(&ln);

}

int main()
{
	test1();
	return 0;
}