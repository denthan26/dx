#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>

#define AtomType char  //原子类型
/*
广义表的结点标记
HEAD：表示表头结点
ATOM：表示原子结点
CHILDLIST：表示子表结点
*/
typedef enum { HEAD, ATOM, CHILDLIST }ElemTag;

//广义表的结点
typedef struct GLNode
{
	ElemTag tag; //结点标记
	union //联合体
	{
		AtomType atom; //原子数据(如果该结点是原子结点，则使用该项)
		struct GLNode* hp; //表结点的表头指针(如果该结点是子表结点，则使用该项)，指向子表的表头结点
	};
	struct GLNode* tp; //表尾指针(因为广义表的结点只有表头和表尾，所以这里的表尾指针相当于线性链表的next,指向下一个元素结点)
}GLNode;

typedef GLNode* GenList; //广义表

void InitGenList(GenList& gl);
void CreateGenList(GenList& gl, const char* str);
bool sever(char* sub, char* hsub);

///
char* GetGenListStr(GenList gl, int type);
char* GetHead(GenList gl);
char* GetTail(GenList gl);
char* GetLast(GenList gl);
void ShowGenList(GenList gl);
bool GenListEmpty(GenList gl);
int  GenListLength(GenList gl);
int  GenListDepth(GenList gl);
void CopyGenList(GenList gl, GenList& T);
void InsertFirstGenList(GenList& gl, const char* str);
void DeleteFirstGenList(GenList& gl, char*& str);
void ClearGenList(GenList& gl);
void DestroyGenList(GenList& gl);


 
