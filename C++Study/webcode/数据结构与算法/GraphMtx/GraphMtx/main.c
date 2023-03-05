#include "GraphMtx.h"

int main()
{
	GraphMtx gm;
	InitGraph(&gm);
	// 插入顶点
	InsertVertix(&gm, 'A');
	InsertVertix(&gm, 'B');
	InsertVertix(&gm, 'C');
	InsertVertix(&gm, 'D');
	InsertVertix(&gm, 'E');
	showGraph(&gm);

	// 插入边
	InsertEdge(&gm, 'A', 'B');
	InsertEdge(&gm, 'A', 'D');
	InsertEdge(&gm, 'B', 'C');
	InsertEdge(&gm, 'B', 'E');
	InsertEdge(&gm, 'C', 'E');
	InsertEdge(&gm, 'C', 'D');
	showGraph(&gm);

	// 获取A的第一个邻接点
	int p = GetFirstNeighbor(&gm, 'A');
	printf("A的第一个邻接点的下标为%d\n", p);

	// 删除BC边
	RemoveEdge(&gm, 'B', 'C');
	showGraph(&gm);

	// 删除顶点C
	RemoveVertix(&gm, 'C');
	showGraph(&gm);

	return 0;

}