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

void initStack(Stack s);//��ʼ��
void distoryStack(Stack s);//����ջ
void push(Stack s, char ch);//��ջ
void pop(Stack s);//��ջ
void getTop(Stack s);//���ջ��Ԫ��
void isEmpty(Stack s);//�ж�ջ��
void isFull(Stack s);//�ж�ջ��
void setNull(Stack s);//����ջ��
void reverseDisplay(Stack s);//�鿴ջ����

void menu()
{
	printf("*******************************************************\n");
	printf("****   1.�½�ջ�����У���ѡ�� 2.��ջ����һ��Ԫ��   ****\n");
	printf("****   3.ջ����һ��Ԫ��       4.���ջ��Ԫ��       ****\n");
	printf("****   5.ջ�Ƿ�Ϊ��           6.ջ�Ƿ�����        *****\n");
	printf("****   7.����ջ��             8.����ջ            *****\n");
	printf("****   9.�鿴ջ��Ԫ��         0.����              *****\n");
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
	//�ж��Ƿ����ջ
	if (s->top == s->size)
	{
		printf("ջ����,������ջ\n");
		return;
	}
	//����ջ����
	s->top++;
	s->data[s->top] = ch;
	//printf("���ԣ���ǰtop��ֵΪ%d\n", s->top);
}

void isFull(Stack s)
{
	if (s->top == s->size)
		printf("ջ����\n");
	else
		printf("ջδ��\n");
}

void reverseDisplay(Stack s)//�鿴ջ����
{
	int i;
	if (s->top == -1)
	{
		printf("��ջ\n");
		return;
	}
	for (i = 0; i <= s->top; i++)
		printf("%c ", s->data[i]);
}

void isEmpty(Stack s)//�ж�ջ��
{
	if (s->top == -1)
		printf("ջ��\n");
	else
		printf("ջ���ǿյģ�������Ԫ�أ������ͨ��9�鿴ջԪ��\n");
}

void pop(Stack s)//��ջ
{
	//�ж�ջ�գ�����գ����ɽ��г�ջ
	if (s->top == -1)
	{
		printf("����һ����ջ�����ܽ��г�ջ���������Ȳ���\n");
		return;
	}
	printf("%c�ѱ�����,�����ͨ��9�鿴ʣ��Ԫ��\n", s->data[s->top]);
	s->top--;
}

void getTop(Stack s)//���ջ��Ԫ��
{
	printf("��ǰջ��Ԫ��Ϊ%c\n", s->data[s->top]);
}

void setNull(Stack s)//����ջ��
{
	s->top = -1;
	printf("����ջ�ѱ�����Ϊ��\n");
	printf("�����ͨ���鿴ջ���ݻ����ж��Ƿ�Ϊ�����������Ƿ�����\n");
}

void distoryStack(Stack s)//����ջ
{
	free(s->data);
	s->data = NULL;
	s->size = 0;
	s->top = -2;
	if (!s->data)
	{
		printf("���ٳɹ�\n");
		printf("���ջ�ѱ�����\n");
		printf("�����ͨ��������������������һ��ջ������������\n");
		printf("����һ�β��������\n");
		printf("bye\n");
	}
	else
		printf("failure\n");
		
}