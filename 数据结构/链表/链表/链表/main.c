#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	SList p;
	Init(&p);
	Print(&p);

	PushFront(&p, 1);
	PushFront(&p, 2); 
	PushFront(&p, 3); 
	PushFront(&p, 4); 
	Print(&p);
	
	PushBack(&p, 10);
	PushBack(&p, 20);
	PushBack(&p, 30);
	PushBack(&p, 40);
	PushBack(&p, 50);
	Print(&p);

	/*PopFront(&p);
	PopFront(&p);
	Print(&p);
	PopBack(&p);
	PopBack(&p);
	Print(&p);*/

	SListNode*m = Find(&p, 20);
	InsertAfter(m, 999);Print(&p);
	EraseAfter(m); Print(&p);
	Remove(&p, 30); Print(&p);
	
	system("pause");
	return 0;
}