#include"GenList.h"
#define _CRT_SECURE_NO_WARNINGS
GenList initGenList()
{
	GenList gl = NULL;
	return gl;
}

void createGenList(GenList* gl, char* str)
{
	int n = strlen(str);
	char* sub = (char*)malloc(sizeof(char) * (n - 2));
	char* hsub = (char*)malloc(sizeof(char) * (n - 2));
	assert(sub != NULL && hsub != NULL);
	cx_strcpy(sub, str + 1, n - 2);// 将str分离括号
	sub[n - 2] = '\0';
	if (*gl == NULL)// 初始化头节点
	{
		*gl = (GenList)malloc(sizeof(GenNode));
		assert(*gl != NULL);
		(*gl)->tag = HEAD;
		(*gl)->hp = (*gl)->tp = NULL;
	}
	// 创建广义表
	GenList* p =  gl;
	while (strlen(sub) != 0)
	{
		// 初始化尾结点
		(*p)->tp = (GenList)malloc(sizeof(GenNode));
		p = &((*p)->tp);
		//assert((*p) != NULL);
		(*p)->hp = (*p)->tp = NULL;
		// 表头分离
		if (server(hsub, sub))
		{
			if (hsub[0] == '(')
			{
				(*p)->tag = CHILDLIST;
				createGenList(&((*p)->hp), hsub);
			}
			else
			{
				(*p)->tag = ATOM;
				//(*p)->atom = atoi(hsub);
				(*p)->atom = hsub[0];
			}
		}
	}

}

/*
GenList createGenList(GenList gl, char* str)
{
	int n = strlen(str);
	char* sub = (char*)malloc(sizeof(char) * (n - 2));
	char* hsub = (char*)malloc(sizeof(char) * (n - 2));
	assert(sub != NULL && hsub != NULL);
	cx_strcpy(sub, str+1, n-2);
	sub[n - 2] = '\0';
	if (gl == NULL)
	{
		gl = (GenList)malloc(sizeof(GenNode));
		assert(gl != NULL);
		gl->tag = HEAD;
		gl->hp = gl->tp = NULL;
	}
	GenList p = gl;
	while(strlen(sub) != 0)
	{
		p = p->tp = (GenList)malloc(sizeof(GenNode));
		assert(p != NULL);
		p->hp = p->tp = NULL;
		if (server(hsub, sub))//1,2
		{
			if (hsub[0] == '(')
			{
				p->tag = CHILDLIST;
				createGenList(p->hp, hsub);
			}
			else
			{
				p->tag = ATOM;
				p->atom = atoi(hsub);
			}
		}
	}
	return gl;
}
*/

//char* ga = "(1,2,3)";
//char* gb = "(1,(2,3),4)";
//char* gc = "((1,2),3)";
int server(char* hsub, char* sub)
{
	if (*sub == '\0' || strcmp(sub, "()") == 0)
	{
		hsub[0] = '\0';
		return 1;
	}
	int n = strlen(sub);
	int k = 0; //对括号的标识
	int i = 0;
	char ch = sub[0]; //(1,2)
	while (i < n && (ch != ',' || k != 0))//(1,(2),3),2
	{
		if (ch == '(')
			k++;
		else if (ch == ')')
			k--;
		i++;
		ch = sub[i];
	}
	if (i < n)
	{
		sub[i] = '\0';// 1 \0 2,3
		cx_strcpy_single(hsub, sub); //hsub=1
		cx_strcpy_single(sub, sub + i + 1); //sub=2,3
	}
	else if (k != 0)
		return 0;
	else
	{
		cx_strcpy_single(hsub, sub);
		sub[0] = '\0';
	}

	return 1;
}
//1,2,3)
void cx_strcpy(char* sub, char* str, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		sub[i] = str[i];
	}
}
void cx_strcpy_single(char* str2, char* str1)
{
	int i;
	int n = strlen(str1);
	for (i = 0; i < n; i++)
	{
		str2[i] = str1[i];
	}
	str2[i] = '\0';
}

void ShowGenList(GenList gl)
{
	GenList p = gl->tp;
	printf("(");
	while (p != NULL)
	{
		if (p->tag == ATOM)
		{
			printf("%c", p->atom);
			if (p->tp != NULL)
				printf(",");
			p = p->tp;
		}
		else if (p->tag == CHILDLIST)
		{
			ShowGenList(p->hp);
			p = p->tp;
		}
	}
	printf("),");
}