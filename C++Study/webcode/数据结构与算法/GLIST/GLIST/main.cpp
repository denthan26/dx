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
	printf("���ƣ�");
	CopyGenList(gl, T);
	ShowGenList(T);
	printf("\n");

	printf("----------------------------\n");
	printf("����ǰ��");
	ShowGenList(gl);
	printf("\n");
	InsertFirstGenList(gl, ga);
	printf("�����");
	ShowGenList(gl);
	printf("\n");
	printf("----------------------------\n");
	char* str;
	printf("ɾ��ǰ��");
	ShowGenList(gl);
	printf("\n");
	DeleteFirstGenList(gl, str);
	printf("ɾ����");
	ShowGenList(gl);
	printf("\n");
	printf("ɾ������Ԫ��Ϊ��%s\n", str);

	printf("----------------------------\n");
	ShowGenList(gl);
	printf("\n");
	printf("ͷԪ��Ϊ��%s\n", GetHead(gl));
	printf("βԪ��Ϊ��%s\n", GetTail(gl));

	DestroyGenList(gl);

}
