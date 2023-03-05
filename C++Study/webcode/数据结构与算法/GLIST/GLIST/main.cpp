#include"GenList.h"

void main()
{
	GenList gl;
	InitGenList(gl);

	const char* ga = "(1,2,3)";
	const char* gb = "(1,(2,3))";
	const char* gc = "(1,(2,3),4)";
	const char* gd = "((1,2),3)";
	const char* ge = "((1,2,3))";
	const char* gf = "()";
	const char* gg = "(1,(2,(3,(10,20),4),5),6)";
	const char* gh = "((((1,2),1),1),6,1)";

	CreateGenList(gl, gg);
	ShowGenList(gl);
	printf("\n");
	int length = GenListLength(gl);
	printf("length = %d\n", length);

	int depth = GenListDepth(gl);
	printf("depth = %d\n", depth);

	GenList T;
	InitGenList(T);
	printf("----------------------------\n");
	printf("复制：");
	CopyGenList(gl, T);
	ShowGenList(T);
	printf("\n");

	printf("----------------------------\n");
	printf("插入前：");
	ShowGenList(gl);
	printf("\n");
	InsertFirstGenList(gl, ga);
	printf("插入后：");
	ShowGenList(gl);
	printf("\n");
	printf("----------------------------\n");
	char* str;
	printf("删除前：");
	ShowGenList(gl);
	printf("\n");
	DeleteFirstGenList(gl, str);
	printf("删除后：");
	ShowGenList(gl);
	printf("\n");
	printf("删除的首元素为：%s\n", str);

	printf("----------------------------\n");
	ShowGenList(gl);
	printf("\n");
	printf("头元素为：%s\n", GetHead(gl));
	printf("尾元素为：%s\n", GetTail(gl));

	DestroyGenList(gl);

}
