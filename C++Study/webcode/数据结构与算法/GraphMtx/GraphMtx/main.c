#include "GraphMtx.h"

int main()
{
	GraphMtx gm;
	InitGraph(&gm);
	// ���붥��
	InsertVertix(&gm, 'A');
	InsertVertix(&gm, 'B');
	InsertVertix(&gm, 'C');
	InsertVertix(&gm, 'D');
	InsertVertix(&gm, 'E');
	showGraph(&gm);

	// �����
	InsertEdge(&gm, 'A', 'B');
	InsertEdge(&gm, 'A', 'D');
	InsertEdge(&gm, 'B', 'C');
	InsertEdge(&gm, 'B', 'E');
	InsertEdge(&gm, 'C', 'E');
	InsertEdge(&gm, 'C', 'D');
	showGraph(&gm);

	// ��ȡA�ĵ�һ���ڽӵ�
	int p = GetFirstNeighbor(&gm, 'A');
	printf("A�ĵ�һ���ڽӵ���±�Ϊ%d\n", p);

	// ɾ��BC��
	RemoveEdge(&gm, 'B', 'C');
	showGraph(&gm);

	// ɾ������C
	RemoveVertix(&gm, 'C');
	showGraph(&gm);

	return 0;

}