#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node*next;
}Node, *LinkList;

//��ʼ��
void InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

//ͷ��
void PushFront(LinkList L, int x)
{
	Node*node = (LinkList)malloc(sizeof(Node));
	node->data = x;
	node->next = L->next;
	L->next = node;
}

//β��
void PushBack(LinkList L, int x)
{
	if (L->next == NULL)
	{
		PushFront(L, x);
		return;
	}
	Node*last = L->next;
	while (last->next != NULL)
	{
		last = last->next;
	}
	Node*node = (LinkList)malloc(sizeof(Node));
	node->data = x;
	node->next = NULL;
	last->next = node;
}

//β�彨��
void GreateFromTail(LinkList L)
{
	while (1)
	{
		int c = 0;
		printf("��������ֵ������9999���������������");
		scanf("%d", &c);
		if (c == 9999)
		{
			return;
		}
		else
		{
			PushBack(L, c);
		}
	}
}

//����������
void BianLi(LinkList L)
{
	Node *cur = L;
	while (cur->next != NULL)
	{
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n");
}

//���õ�����
LinkList Reverse(LinkList L)
{
	LinkList q = NULL;
	InitList(&q);
	Node *cur = L;
	while (cur->next != NULL)
	{
		cur = cur->next;
		if (cur != NULL)
		{
			int c = cur->data;
			PushFront(q, c);
		}
	}
	return q;
}


//�����ǵݼ���������
void Order(LinkList L)
{
	while (1)
	{
		int c = 0;
		printf("��������ֵ������9999���������������");
		scanf("%d", &c);
		if (c == 9999)
		{
			return; 
		}
		if (L->next == NULL)
		{
			PushBack(L, c);
		}
		else
		{
			Node*cur = L;
			while (cur->next != NULL)
			{
				if (c <= cur->next->data)
				{
					Node*node = (LinkList)malloc(sizeof(Node));
					node->data = c;
					node->next = cur->next;
					cur->next = node;
					break;
				}
				cur = cur->next;
			}
			if (cur->next == NULL)
			{
				PushBack(L, c);
			}	
		}
	}
}

//�ϲ�������������
LinkList ConBine(LinkList L, LinkList Q)
{
	Node*p1 = L->next;
	Node*p2 = Q->next;
	LinkList m = L;
	m->next = NULL;
	Node*tail = m;
	while (p1 != NULL&&p2 != NULL)
	{
		if (p1->data <= p2->data)
		{
			tail->next = p1;
			tail = p1;
			p1 = p1->next;
		}
		else
		{
			tail->next = p2;
			tail = p2;
			p2 = p2->next;
		}
	}
	if (p1 != NULL)
	{
		tail->next = p1;
	}
	else
	{
		tail->next = p2;
	}
	return m;
}

//�������������һ������Ȼ����
void PushOrder(LinkList L)
{
	int c = 0;
	printf("������Ҫ����Ľ��ֵ��");
	scanf("%d", &c);
	if (L->next == NULL)
	{
		PushBack(L, c);
	}
	else
	{
		Node*cur = L;
		while (cur->next != NULL)
		{
			if (c <= cur->next->data)
			{
				Node*node = (LinkList)malloc(sizeof(Node));
				node->data = c;
				node->next = cur->next;
				cur->next = node;
				break;
			}
			cur = cur->next;
		}
		if (cur->next == NULL)
		{
			PushBack(L, c);
		}
	}
}

//������������ɾ��ֵΪx�Ľ��
void Delete(LinkList L,int x)
{
	Node*cur = L;
	if (L->next == NULL)
	{
		printf("����Ϊ������");
		return;
	}
	while (cur->next != NULL)
	{
		if (cur->next->data == x)
		{
			Node*temp = cur->next;
			cur->next = temp->next;
			free(temp);
			continue;
		}
		cur = cur->next;
	}
}

void Menu()
{
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("                                1.����һ����ͷ���ĵ�����L��\n");
	printf("                                2.����������L������L�е�Ԫ�ء�\n");
	printf("                                3.����һ���ǵݼ���������L��\n");
	printf("                                4.���������ǵݼ���������a��b��Ȼ��ϲ���һ���ǵݼ�����c��\n");
	printf("                                5.�����ǵݼ���������L����L�в���һ��Ԫ��ʹL��Ȼ����\n");
	printf("                                6.�����ǵݼ���������L��ɾ��ֵΪx�Ľ�㡣\n");
	printf("                                0.�˳���\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("��������Ҫ���еĲ�����");
}


int main()
{
	int choice = 0;
	while (1)
	{
		Menu();
		scanf("%d", &choice);
		if (!(choice >= 0 && choice <= 6))
		{
			printf("��������\n");
			continue;
		}
		LinkList n=NULL;
		LinkList b = NULL;
		switch (choice)
		{
		case 1:
			InitList(&n);
			GreateFromTail(n);
			printf("�������ɹ���\n");
			BianLi(n);
			break;
		case 2:
			InitList(&n);
			GreateFromTail(n);
			LinkList m =Reverse(n);
			printf("�������óɹ���\n");
			BianLi(m);
			break;
		case 3:
			InitList(&n);
			Order(n);
			printf("�������ɹ���\n");
			BianLi(n);
			break;
		case 4:
			InitList(&n);
			InitList(&b);
			printf("����������a\n");
			Order(n);
			printf("����������b\n");
			Order(b);
			LinkList q = ConBine(n, b);
			printf("�ϲ��ɹ���\n");
			BianLi(q);
			break;
		case 5:
			InitList(&n);
			Order(n);
			PushOrder(n);
			printf("�����ɹ���\n");
			BianLi(n);
			break;
		case 6:
			InitList(&n);
			Order(n);
			int x = 0;
			printf("������Ҫɾ���Ľ��ֵ��");
			scanf("%d", &x);
			Delete(n,x);
			BianLi(n);
			break;
		case 0:
			return 0;
		}
	}
	system("pause");
	return 0;
}