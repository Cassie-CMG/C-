#pragma once

//��ͷ�����ѭ������

typedef struct SListNode
{
	int data;
	struct SListNode*next;
}SListNode;

typedef struct SList
{
	SListNode*head;
}SList;

//��ʼ��
void Init(SList*p);

//����
void Destory(SList*p);

//�����½��
SListNode *Buy(int x);

//ͷ��
void PushFront(SList*p, int x);

//β��
void PushBack(SList*p, int x);

//ͷɾ
void PopFront(SList*p);

//βɾ
void PopBack(SList*p);

//����
SListNode*Find(SList*p, int x);

//��pos�������
void InsertAfter(SListNode*pos, int x);

//��pos����ɾ��
void EraseAfter(SListNode*pos);

//ɾ����һ��������x
void Remove(SList*p, int x);

//��ӡ
void Print(SList*p);