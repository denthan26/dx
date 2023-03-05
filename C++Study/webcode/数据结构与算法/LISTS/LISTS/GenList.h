#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>

#define AtomType char  //ԭ������
/*
�����Ľ����
HEAD����ʾ��ͷ���
ATOM����ʾԭ�ӽ��
CHILDLIST����ʾ�ӱ���
*/
typedef enum { HEAD, ATOM, CHILDLIST }ElemTag;

//�����Ľ��
typedef struct GLNode
{
	ElemTag tag; //�����
	union //������
	{
		AtomType atom; //ԭ������(����ý����ԭ�ӽ�㣬��ʹ�ø���)
		struct GLNode* hp; //����ı�ͷָ��(����ý�����ӱ��㣬��ʹ�ø���)��ָ���ӱ�ı�ͷ���
	};
	struct GLNode* tp; //��βָ��(��Ϊ�����Ľ��ֻ�б�ͷ�ͱ�β����������ı�βָ���൱�����������next,ָ����һ��Ԫ�ؽ��)
}GLNode;

typedef GLNode* GenList; //�����

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


 
