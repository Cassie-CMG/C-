#pragma once

//无头单向非循环链表

typedef struct SListNode
{
	int data;
	struct SListNode*next;
}SListNode;

typedef struct SList
{
	SListNode*head;
}SList;

//初始化
void Init(SList*p);

//销毁
void Destory(SList*p);

//创建新结点
SListNode *Buy(int x);

//头插
void PushFront(SList*p, int x);

//尾插
void PushBack(SList*p, int x);

//头删
void PopFront(SList*p);

//尾删
void PopBack(SList*p);

//查找
SListNode*Find(SList*p, int x);

//在pos后面插入
void InsertAfter(SListNode*pos, int x);

//在pos后面删除
void EraseAfter(SListNode*pos);

//删除第一个遇到的x
void Remove(SList*p, int x);

//打印
void Print(SList*p);