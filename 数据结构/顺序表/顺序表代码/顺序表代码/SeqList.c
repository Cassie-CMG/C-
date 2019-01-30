//动态顺序表
#include <stdio.h >
#include <stdlib.h>
#include <assert.h>

typedef struct SeqList
{
	int *array;  //指向动态开辟的数组
	int size;      //有效数据个数
	int capacity;  //容量空间大小
}SeqList;

//初始化
void Init(SeqList *p, int capacity)
{
	assert(p);
	p->size = 0;
	p->capacity = capacity;
	p->array= (int*)malloc(capacity*sizeof(int));
	assert(p->array);
}

//摧毁
void Destory(SeqList*p)
{
	assert(p);
	free(p->array);
	p->array = NULL;
	p->capacity = p->size = 0;
}

//扩容
void CheckCapacity(SeqList*p)
{
	if (p->size < p->capacity)
	{
		return;
	}
	int newCapacity = p->capacity * 2;
	int*newArray = (int*)malloc(sizeof(int)*newCapacity);
	assert(newArray);
	for (int i = 0; i < p->size; i++)
	{
		newArray[i] = p->array[i];
	}
	free(p->array);
	p->array = newArray;
	p->capacity = newCapacity;
}

//查找
int Find(SeqList*p, int x)
{
	assert(p);
	for (int i = 0; i < p->size; i++)
	{
		if (p->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//头插
void PushFront(SeqList*p, int x)
{
	assert(p);
	CheckCapacity(p);
	for (int i =p->size-1; i >=0 ; i--)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[0] = x;
	p->size++;
}

//头删
void PopFront(SeqList*p)
{
	assert(p);
	assert(p->size > 0);
	for (int i = 1; i < p->size ; i++)
	{
		p->array[i - 1] = p->array[i];
	}
	p->size--;
}

//尾插
void PushBack(SeqList*p, int x)
{
	assert(p);
	CheckCapacity(p);
	p->array[p->size] = x;
	p->size++;
}

//尾删
void PopBack(SeqList*p)
{
	assert(p);
	assert(p->size > 0);
	p->size--;
}

//在pos位置插入
void Insert(SeqList*p, int pos, int x)
{
	assert(p);
	CheckCapacity(p);
	assert(pos >= 0 && pos < p->size);
	for (int i = p->size - 1; i >= pos; i--)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[pos] = x;
	p->size++;
}

//删除pos所在下标的数据
void Erase(SeqList*p, int pos)
{
	assert(p);
	assert(p->size > 0);
	assert(pos >= 0 && pos < p->size);
	for (int i = pos+1; i < p->size; i++)
	{
		p->array[i - 1] = p->array[i];
	}
	p->size--;
}

//删除数据x
void Remove(SeqList*p, int x)
{
	assert(p);
	int pos = Find(p, x);
	if (pos != -1) 
	{
		Erase(p, pos);
	}
}

//修改pos所在下标的数据
void Modify(SeqList*p, int pos, int x)
{
	assert(p);
	assert(pos >= 0 && pos < p->size);
	p->array[pos] = x;
}

//打印
void Print(SeqList*p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->array[i]);
	}
	printf("\n");
}


int main()
{
	SeqList p;
	Init(&p, 5);
	PushFront(&p, 1);
	PushFront(&p, 2);
	PushFront(&p, 3);
	PushFront(&p, 4);
	PushFront(&p, 5);
	Print(&p);
	PushBack(&p, 100);
	PushBack(&p, 200);
	PushBack(&p, 300);
	PushBack(&p, 400);
	PushBack(&p, 500);
	Print(&p);
	PopFront(&p);
	Print(&p);
	PopBack(&p);
	Print(&p);
	int i = Find(&p, 1);
	printf("%d\n", i);
	Insert(&p, 3, 999);
	Print(&p);
	Erase(&p, 3);
	Print(&p);
	Remove(&p, 4);
	Print(&p);
	Modify(&p, 1, 999);
	Print(&p);
	Destory(&p);
	Print(&p);
	system("pause");
}