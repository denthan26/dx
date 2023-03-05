#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
typedef struct BiNode {
	char data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode,*BiTree;
void creadteTree(BiTree T);
int main()
{
	BiNode T;
	creadteTree(&T);
	return 0;
}
void creadteTree(BiTree T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;


}