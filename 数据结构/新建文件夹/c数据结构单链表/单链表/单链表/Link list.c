#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node*next;
}Node, *LinkList;

//初始化
void InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

//头插
void PushFront(LinkList L, int x)
{
	Node*node = (LinkList)malloc(sizeof(Node));
	node->data = x;
	node->next = L->next;
	L->next = node;
}

//尾插
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

//尾插建表
void GreateFromTail(LinkList L)
{
	while (1)
	{
		int c = 0;
		printf("请输入结点值（输入9999代表输入结束）：");
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

//遍历单链表
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

//逆置单链表
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


//建立非递减有序单链表
void Order(LinkList L)
{
	while (1)
	{
		int c = 0;
		printf("请输入结点值（输入9999代表输入结束）：");
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

//合并两个有序链表
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

//在有序单链表插入一个数仍然有序
void PushOrder(LinkList L)
{
	int c = 0;
	printf("请输入要插入的结点值：");
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

//在有序链表中删除值为x的结点
void Delete(LinkList L,int x)
{
	Node*cur = L;
	if (L->next == NULL)
	{
		printf("链表为空链表！");
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
	printf("                                1.建立一个带头结点的单链表L。\n");
	printf("                                2.建立单链表L，逆置L中的元素。\n");
	printf("                                3.建立一个非递减有序单链表L。\n");
	printf("                                4.建立两个非递减有序单链表a，b，然后合并成一个非递减链表c。\n");
	printf("                                5.建立非递减有序单链表L，在L中插入一个元素使L仍然有序。\n");
	printf("                                6.建立非递减有序单链表L，删除值为x的结点。\n");
	printf("                                0.退出。\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("请输入你要进行的操作：");
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
			printf("输入有误！\n");
			continue;
		}
		LinkList n=NULL;
		LinkList b = NULL;
		switch (choice)
		{
		case 1:
			InitList(&n);
			GreateFromTail(n);
			printf("链表建立成功！\n");
			BianLi(n);
			break;
		case 2:
			InitList(&n);
			GreateFromTail(n);
			LinkList m =Reverse(n);
			printf("链表逆置成功！\n");
			BianLi(m);
			break;
		case 3:
			InitList(&n);
			Order(n);
			printf("链表建立成功！\n");
			BianLi(n);
			break;
		case 4:
			InitList(&n);
			InitList(&b);
			printf("请输入链表a\n");
			Order(n);
			printf("请输入链表b\n");
			Order(b);
			LinkList q = ConBine(n, b);
			printf("合并成功！\n");
			BianLi(q);
			break;
		case 5:
			InitList(&n);
			Order(n);
			PushOrder(n);
			printf("操作成功！\n");
			BianLi(n);
			break;
		case 6:
			InitList(&n);
			Order(n);
			int x = 0;
			printf("请输入要删除的结点值：");
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