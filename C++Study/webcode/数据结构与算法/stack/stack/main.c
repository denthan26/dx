#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
/*
* ����˵����
* ���ֲ˵������˵���ʾ���в���
*/
int main()
{
	int i;//swicth��ѡ��
	char ch;//�����Ԫ��
	char tmp;//���м��
	S si;
	Stack s;
	initStack(&si);
	s = &si;
	
	if (s->top == -1)
		printf("�������ջʹ��ջ\n");
	else
		return 0;
	//menu
	while (1)
	{
		printf("��������һ��ջ��������ջ���в�����\n");
		menu();
		printf("��ѡ��:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("�벻Ҫ�½�ջ������ѡһ���ɡ�\n");
			break;
		case 2:
			while (tmp = getchar() != '\n');
			printf("������:");
			scanf("%c", &ch);
			push(s, ch);
			printf("����ɹ�\n");
			printf("\n");
			break;
		case 3:
			pop(s);
			break;
		case 4:
			getTop(s);
			break;
		case 5:
			isEmpty(s);
			break;
		case 6:
			isFull(s);
			break;
		case 7:
			setNull(s);
			break;
		case 8:
			distoryStack(s);
			return 0;
			break; 
		case 9:
			reverseDisplay(s);
			printf("\n");
			break;
		case 0:
			printf("bye");
			return 0;
			break;
		default:
			printf("��������ֲ��ڷ�Χ�ڣ�����������\n");
			break;
		}
	}
	return 0;
}

