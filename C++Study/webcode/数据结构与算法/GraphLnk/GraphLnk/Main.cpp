#include"GraphLnk.h"
int main()
{
	GraphLnk gl;
	InitGraph(&gl);
	InsertVertex(&gl, 'A');
	InsertVertex(&gl, 'B');
	InsertVertex(&gl, 'C');
	InsertVertex(&gl, 'D');
	InsertVertex(&gl, 'E');
	InsertVertex(&gl, 'F');
	InsertVertex(&gl, 'G');
	InsertVertex(&gl, 'H');

	InsertEdge(&gl, 'A', 'B');
	InsertEdge(&gl, 'A', 'C');
	InsertEdge(&gl, 'B', 'D');
	InsertEdge(&gl, 'B', 'E');
	InsertEdge(&gl, 'C', 'F');
	InsertEdge(&gl, 'C', 'G');
	InsertEdge(&gl, 'F', 'G');
	InsertEdge(&gl, 'D', 'H');
	InsertEdge(&gl, 'E', 'H');


	ShowGraph(&gl);
	printf("ʹ��DFS���ͼ:\n");

	DFS_Ready(&gl, 'A');
	printf("Nul.\n");
	printf("ʹ��BFS���ͼ:\n");
	BFS(&gl, 'A');
	printf("Nul.\n");


	/*printf("A�ĵ�һ���ڽӵ���±���%d\n", GetFirstNeighbor(&gl, 'A'));
	printf("A�ĵڶ����ڽӵ���±���%d\n", GetNextNeighbor(&gl,'A','B'));
	printf("ɾ����CD\n");
	RemoveEdge(&gl, 'C', 'D');
	ShowGraph(&gl);

	printf("ɾ������C\n");
	RemoveVertex(&gl, 'C');
	ShowGraph(&gl);

	printf("����ͼ\n");
	DestoryGraph(&gl);
	ShowGraph(&gl);*/

	return 0;
}