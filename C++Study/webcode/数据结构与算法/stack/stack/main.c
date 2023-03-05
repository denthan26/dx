#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
/*
* 程序说明：
* 出现菜单，按菜单提示进行操作
*/
int main()
{
	int i;//swicth的选择
	char ch;//插入的元素
	char tmp;//换行检查
	S si;
	Stack s;
	initStack(&si);
	s = &si;
	
	if (s->top == -1)
		printf("现在这个栈使空栈\n");
	else
		return 0;
	//menu
	while (1)
	{
		printf("现在已有一个栈，请对这个栈进行操作：\n");
		menu();
		printf("请选择:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("请不要新建栈，重新选一个吧。\n");
			break;
		case 2:
			while (tmp = getchar() != '\n');
			printf("请输入:");
			scanf("%c", &ch);
			push(s, ch);
			printf("插入成功\n");
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
			printf("输入的数字不在范围内，请重新输入\n");
			break;
		}
	}
	return 0;
}

