#include "GraphLnk.h"
#include"Queue.h"

void InitGraph(GraphLnk* g)
{
	g->MaxVertices = Default_Vertex_Size;
	g->NumEgdes = g->NumVertices = 0;
	// 为邻接表开辟空间
	g->NodeTable = (Vertex*)malloc(sizeof(Vertex) * g->MaxVertices);
	assert(g->NodeTable != NULL);
	// 为邻接表的link指针赋空
	for (int i = 0; i < g->MaxVertices; i++)
	{
		g->NodeTable[i].adj = NULL;
	}
}

void ShowGraph(GraphLnk* g)
{
	Edge* p = NULL;
	for (int i = 0; i < g->NumVertices; i++)
	{
		printf("%d %c:>", i, g->NodeTable[i].data);
		p = g->NodeTable[i].adj;
		while (p != NULL)
		{
			printf("%d-->", p->dest);
			p = p->link;
		}
		printf("Nul.\n");
	}
	printf("\n");
}

void InsertVertex(GraphLnk* g, T v)
{
	if (g->NumVertices >= g->MaxVertices)
		return;
	g->NodeTable[g->NumVertices++].data = v;
}

int GetVertexPos(GraphLnk* g, T v)
{
	for (int i = 0; i < g->NumVertices; i++)
	{
		if (g->NodeTable[i].data == v)
			return i;
	}
	return -1;
}

void InsertEdge(GraphLnk* g, T vertex1, T vertex2)
{
	int v1 = GetVertexPos(g, vertex1);
	int v2 = GetVertexPos(g, vertex2);

	Edge* s;
	//v1-->v2
	s = (Edge*)malloc(sizeof(Edge));
	assert(s != NULL);
	s->dest = v2;
	s->link = g->NodeTable[v1].adj;
	g->NodeTable[v1].adj = s;

	//v2-->v1
	s = (Edge*)malloc(sizeof(Edge));
	assert(s != NULL);
	s->dest = v1;
	s->link = g->NodeTable[v2].adj;
	g->NodeTable[v2].adj = s;

	g->NumEgdes++;
}

void RemoveEdge(GraphLnk* g, T vertex1, T vertex2)
{
	int v1 = GetVertexPos(g, vertex1);
	int v2 = GetVertexPos(g, vertex2);
	if (v1 == -1 || v2 == -1)
		return;

	Edge* q = NULL;
	Edge* p;
	//v1-->v2
	p = g->NodeTable[v1].adj;
	while (p != NULL && p->dest != v2)
	{
		q = p;
		p = p->link;
	}
	if (p == NULL)
		return;

	if (q == NULL)
	{
		g->NodeTable[v1].adj = p->link;
	}
	else
	{
		q->link = p->link;
	}
	free(p);

	//v2-->v1
	q = NULL;
	p = g->NodeTable[v2].adj;
	while (p->dest != v1)
	{
		q = p;
		p = p->link;
	}
	if (q == NULL)
	{
		g->NodeTable[v2].adj = p->link;
	}
	else
	{
		q->link = p->link;
	}
	free(p);
}

void RemoveVertex(GraphLnk* g, T vertex)
{
	int v = GetVertexPos(g, vertex);
	if (v == -1)
		return;

	Edge* p = g->NodeTable[v].adj;
	int k;
	Edge* t = NULL;
	Edge* s = NULL;
	while (p != NULL)
	{
		k = p->dest;
		s = g->NodeTable[k].adj;
		while (s != NULL && s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)
		{
			if (t == NULL)
				g->NodeTable[k].adj = s->link;
			else
				t->link = s->link;
			free(s);
		}

		g->NodeTable[v].adj = p->link;
		free(p);
		p = g->NodeTable[v].adj;
	}
	g->NumVertices--;
	g->NodeTable[v].data = g->NodeTable[g->NumVertices].data;
	g->NodeTable[v].adj = g->NodeTable[g->NumVertices].adj;

	s = g->NodeTable[v].adj;
	while (s != NULL)
	{
		k = s->dest;
		p = g->NodeTable[k].adj;
		while (p != NULL)
		{
			if (p->dest == g->NumVertices)
			{
				p->dest = v;
				break;
			}
			p = p->link;
		}
		s = s->link;
	}
}

void DestoryGraph(GraphLnk* g)
{
	Edge* p;
	for (int i = 0; i < g->NumVertices; i++)
	{
		p = g->NodeTable[i].adj;
		while (p != NULL)
		{
			g->NodeTable[i].adj = p->link;
			free(p);
			p = g->NodeTable[i].adj;
		}
	}
	free(g->NodeTable);
	g->NodeTable = NULL;
	g->MaxVertices = g->NumEgdes = g->NumVertices = 0;
}

int GetFirstNeighbor(GraphLnk* g, T vertex)
{
	int v = GetVertexPos(g, vertex);
	if (v == -1)
		return -1;
	Edge* p = g->NodeTable[v].adj;
	if (p != NULL)
		return p->dest;
	return -1;
}
int GetNextNeighbor(GraphLnk* g, T vertex1, T vertex2)
{
	int v1 = GetVertexPos(g, vertex1);
	int v2 = GetVertexPos(g, vertex2);
	if (v1 == -1 || v2 == -1)
		return -1;

	Edge* p = g->NodeTable[v1].adj;
	while (p != NULL && p->dest != v2)
		p = p->link;
	if (p != NULL && p->link != NULL)
		return p->link->dest;
	return -1;
}

T GetVertexValue(GraphLnk* g, int v)
{
	if (v == -1)
		return 0;
	return g->NodeTable[v].data;
}
/////////////////////////////////////////////////////
void DFS_Ready(GraphLnk* g, T vertex)
{
	int n = g->NumVertices;
	int* visited = (int*)malloc(sizeof(int) * n);
	assert(visited != NULL);
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	int v = GetVertexPos(g, vertex);
	DFS(g, v, visited);
	free(visited);
}
void DFS(GraphLnk* g, int v, int visited[])
{
	printf("%c-->", GetVertexValue(g, v));// 获取顶点值
	visited[v] = 1;// 顶点值已经访问
	int w = GetFirstNeighbor(g, GetVertexValue(g,v));// 获取顶点值的邻接点
	while (w != -1)
	{
		if (!visited[w])
		{
			DFS(g, w, visited);
		}
		w = GetNextNeighbor(g, GetVertexValue(g, v), GetVertexValue(g, w));
	}
}

void BFS(GraphLnk* g, T vertex)
{
	int n = g->NumVertices;
	bool* visited = (bool*)malloc(sizeof(bool) * n);
	assert(visited != NULL);
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	printf("%c-->", vertex);
	int v = GetVertexPos(g, vertex);
	visited[v] = true;
	Queue Q;
	QueueInit(&Q);

	int w;
	QueuePush(&Q, v);
	while (!QueueEmpty(&Q))
	{
		v = QueueFront(&Q);
		QueuePop(&Q);

		w = GetFirstNeighbor(g, GetVertexValue(g, v));
		while (w != -1)
		{
			if (!visited[w])
			{
				printf("%c-->", GetVertexValue(g, w));
				visited[w] = true;
				QueuePush(&Q, w);
			}
			w = GetNextNeighbor(g, GetVertexValue(g, v), GetVertexValue(g, w));
		}
	}
	free(visited);
}