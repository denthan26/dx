#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void menu();

#define MAXSIZE 10

typedef struct Stack {
	int top;
	char* data;
	int size;
}*Stack, S;

void initStack(Stack s);//初始化
void distoryStack(Stack s);//销毁栈
void push(Stack s, char ch);//入栈
void pop(Stack s);//出栈
void getTop(Stack s);//获得栈顶元素
void isEmpty(Stack s);//判断栈空
void isFull(Stack s);//判断栈满
void setNull(Stack s);//设置栈空
void reverseDisplay(Stack s);//查看栈内容

void menu()
{
	printf("*******************************************************\n");
	printf("****   1.新建栈（已有，勿选） 2.向栈插入一个元素   ****\n");
	printf("****   3.栈弹出一个元素       4.获得栈顶元素       ****\n");
	printf("****   5.栈是否为空           6.栈是否满了        *****\n");
	printf("****   7.设置栈空             8.销毁栈            *****\n");
	printf("****   9.查看栈内元素         0.结束              *****\n");
	printf("*******************************************************\n");
}

void initStack(Stack s)
{
	
	s->data = (char*)malloc(MAXSIZE * sizeof(char));
	s->top = -1;
	s->size = MAXSIZE - 1;
	
}

void push(Stack s, char ch)
{
	//判断是否可入栈
	if (s->top == s->size)
	{
		printf("栈满了,不可入栈\n");
		return;
	}
	//可向栈插入
	s->top++;
	s->data[s->top] = ch;
	//printf("测试：当前top的值为%d\n", s->top);
}

void isFull(Stack s)
{
	if (s->top == s->size)
		printf("栈满了\n");
	else
		printf("栈未满\n");
}

void reverseDisplay(Stack s)//查看栈内容
{
	int i;
	if (s->top == -1)
	{
		printf("空栈\n");
		return;
	}
	for (i = 0; i <= s->top; i++)
		printf("%c ", s->data[i]);
}

void isEmpty(Stack s)//判断栈空
{
	if (s->top == -1)
		printf("栈空\n");
	else
		printf("栈不是空的，里面有元素，你可以通过9查看栈元素\n");
}

void pop(Stack s)//出栈
{
	//判断栈空，如果空，不可进行出栈
	if (s->top == -1)
	{
		printf("这是一个空栈，不能进行出栈操作，请先插入\n");
		return;
	}
	printf("%c已被弹出,你可以通过9查看剩余元素\n", s->data[s->top]);
	s->top--;
}

void getTop(Stack s)//获得栈顶元素
{
	printf("当前栈顶元素为%c\n", s->data[s->top]);
}

void setNull(Stack s)//设置栈空
{
	s->top = -1;
	printf("现在栈已被设置为空\n");
	printf("你可以通过查看栈内容或者判断是否为空来看操作是否正常\n");
}

void distoryStack(Stack s)//销毁栈
{
	free(s->data);
	s->data = NULL;
	s->size = 0;
	s->top = -2;
	if (!s->data)
	{
		printf("销毁成功\n");
		printf("这个栈已被销毁\n");
		printf("你可以通过重新运行来重新生成一个栈，并对他操作\n");
		printf("这是一次不错的旅行\n");
		printf("bye\n");
	}
	else
		printf("failure\n");
		
}