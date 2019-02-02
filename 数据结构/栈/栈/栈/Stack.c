//��̬ջ
#include <stdio.h >
#include <stdlib.h>
#include <assert.h>

typedef struct Stack
{
	int* array;
	int top;    //ջ��
	int capacity;   //����
}Stack;

//��ʼ��
void Init(Stack*p, int capacity)
{
	assert(p);
	p->top = 0;
	p->capacity = capacity;
	p->array = (int*)malloc(capacity*sizeof(int));
	assert(p->array);
}

//����
void Destory(Stack*p)
{
	assert(p);
	free(p->array);
	p->array = NULL;
	p->capacity = p->top = 0;
}

//����
void CheckCapacity(Stack*p)
{
	if (p->top < p->capacity)
	{
		return;
	}
	int newCapacity = p->capacity * 2;
	int*newArray = (int*)malloc(sizeof(int)*newCapacity);
	assert(newArray);
	for (int i = 0; i < p->top; i++)
	{
		newArray[i] = p->array[i];
	}
	free(p->array);
	p->array = newArray;
	p->capacity = newCapacity;
}

//��������
void Push(Stack*p, int x)
{
	assert(p);
	CheckCapacity(p);
	p->array[p->top] = x;
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
	return p->array[p->top - 1];
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
		printf("%d ", p->array[i]);
	}
	printf("\n");
}

int main()
{
	Stack p;
	Init(&p,3);
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