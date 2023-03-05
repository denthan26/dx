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
	printf("使用DFS输出图:\n");

	DFS_Ready(&gl, 'A');
	printf("Nul.\n");
	printf("使用BFS输出图:\n");
	BFS(&gl, 'A');
	printf("Nul.\n");


	/*printf("A的第一个邻接点的下标是%d\n", GetFirstNeighbor(&gl, 'A'));
	printf("A的第二个邻接点的下标是%d\n", GetNextNeighbor(&gl,'A','B'));
	printf("删除边CD\n");
	RemoveEdge(&gl, 'C', 'D');
	ShowGraph(&gl);

	printf("删除顶点C\n");
	RemoveVertex(&gl, 'C');
	ShowGraph(&gl);

	printf("销毁图\n");
	DestoryGraph(&gl);
	ShowGraph(&gl);*/

	return 0;
}