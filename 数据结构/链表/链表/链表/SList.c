//无头单向非循环链表
#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//初始化
void Init(SList*p)
{
	assert(p);
	p->head = NULL;
}

//销毁
void Destory(SList*p)
{
	SListNode*p1;
	SListNode*cur;
	for (cur = p->head; cur != NULL; cur = p1)
	{
		p1 = cur->next;
		free(cur);
	}
	p->head = NULL;
}

//创建新结点
SListNode *Buy(int x)
{
	SListNode*node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}

//头插
void PushFront(SList*p, int x)
{
	assert(p);
	SListNode*node = Buy(x);
	node->data = x;
	node->next = p->head;
	p->head = node;
}

//头删
void PopFront(SList*p)
{
	assert(p);
	assert(p->head);
	SListNode*old_head = p->head;
	p->head = p->head->next;
	free(old_head);
}

//尾插
void PushBack(SList*p, int x)
{
	assert(p);
	if (p->head == NULL)
	{
		PushFront(p, x);
		return;
	}
	SListNode*last = p->head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	SListNode*node = Buy(x);
	node->data = x;
	node->next = NULL;
	last->next = node;
}

//尾删
void PopBack(SList*p)
{
	assert(p);
	assert(p->head);
	if (p->head->next == NULL)
	{
		PopFront(p);
		return;
	}
	SListNode*cur = p->head;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//查找
SListNode*Find(SList*p, int x)
{
	for (SListNode*cur = p->head; cur != NULL; cur = cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}

//在pos后面插入
void InsertAfter(SListNode*pos, int x)
{
	SListNode*node = Buy(x);
	node->next = pos->next;
	pos->next = node;	
}

//在pos后面删除
void EraseAfter(SListNode*pos)
{
	SListNode*next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

//删除第一个遇到的x
void Remove(SList*p, int x)
{
	SListNode *prev = NULL;
	SListNode *cur = p->head;
	while (cur != NULL && cur->data != x) 
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL) 
	{
		return;
	}
	if (prev == NULL) 
	{
		PopFront(p);
		return;
	}
	prev->next = cur->next;
	free(cur);
}

//打印
void Print(SList*p)
{
	SListNode*cur = p->head;
	for (; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}

