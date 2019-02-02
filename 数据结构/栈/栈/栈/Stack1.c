//��̬ջ
#define N 100
#include <stdio.h >
#include <stdlib.h>
#include <assert.h>


typedef struct Stack
{
	int a[N];
	int top;   //ջ��
}Stack;

//��ʼ��
void Init(Stack*p)
{
	p->top = 0;
}

//����
void Destory(Stack*p)
{
	p->top = 0;
}

//��������
void Push(Stack*p, int x)
{
	assert(p);
	assert(p->top < N);
	p->a[p->top] = x;
	p->top++;
}

//ɾ������
void Pop(Stack*p)
{
	assert(p);
	assert(p->top>0);
	p->top--;
}

//����ջ��Ԫ��
int Top(Stack*p)
{
	assert(p);
	assert(p->top > 0);
	return p->a[p->top-1];
}

//�ж��Ƿ�Ϊ��ջ
int Empty(Stack*p)
{
	return p->top == 0 ? 1 : 0;
}

//����ջ��Ԫ�ظ���
int Size(const Stack*p)
{
	return p->top;
}

//��ӡ
void Print(Stack*p)
{
	for (int i = 0; i < p->top; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("\n");
}

int main()
{
	Stack p;
	Init(&p);
	Push(&p, 1);
	Push(&p, 2);
	Push(&p, 3);
	Push(&p, 4);
	Push(&p, 5);
	Print(&p);
	Pop(&p);
	Pop(&p);
	Print(&p);
	int top = Top(&p);
	printf("%d\n", top);
	int aj = Empty(&p);
	printf("%d\n", aj);
	int num = Size(&p);
	printf("%d\n", num);
	Destory(&p);
	Print(&p);
	system("pause");
	return 0;
}