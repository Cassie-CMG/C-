//静态栈
#define N 100
#include <stdio.h >
#include <stdlib.h>
#include <assert.h>


typedef struct Stack
{
	int a[N];
	int top;   //栈顶
}Stack;

//初始化
void Init(Stack*p)
{
	p->top = 0;
}

//销毁
void Destory(Stack*p)
{
	p->top = 0;
}

//插入数据
void Push(Stack*p, int x)
{
	assert(p);
	assert(p->top < N);
	p->a[p->top] = x;
	p->top++;
}

//删除数据
void Pop(Stack*p)
{
	assert(p);
	assert(p->top>0);
	p->top--;
}

//返回栈顶元素
int Top(Stack*p)
{
	assert(p);
	assert(p->top > 0);
	return p->a[p->top-1];
}

//判断是否为空栈
int Empty(Stack*p)
{
	return p->top == 0 ? 1 : 0;
}

//返回栈中元素个数
int Size(const Stack*p)
{
	return p->top;
}

//打印
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