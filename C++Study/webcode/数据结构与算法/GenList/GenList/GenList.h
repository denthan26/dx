#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


typedef enum{HEAD,ATOM,CHILDLIST}EnumType;
typedef char AtomType;

typedef struct GenNode
{
	EnumType tag;
	union 
	{
		AtomType atom;
		struct GenNode* hp;
	};
	struct GenNode* tp;
}GenNode;

typedef GenNode* GenList;

GenList initGenList();
//GenList createGenList(GenList gl, char* str);
int server(char* hsub, char* sub);
void cx_strcpy(char* sub, char* str, int n);
void cx_strcpy_single(char* str2, char* str1);
void ShowGenList(GenList gl);

void createGenList(GenList* gl, char* str);
