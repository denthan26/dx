#define _CRT_SECURE_NO_WARNINGS
#include"GenList.h"


int main()
{
	GenList gl = initGenList();
	char* ga = "(1,2,3)";
	char* gb = "(1,(2,3),4)";
	char* gc = "((1,2),3)";
	char* gd = "((),(a,(b,c,d)),(e))";
	//gl = createGenList(gl, gb);
	createGenList(&gl, gd);
	printf("create ok\n");

	ShowGenList(gl);
	printf("\n");
	//system("pause");
	getchar();
	return 0;
}

