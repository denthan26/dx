#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define Default_Vertex_Size 10
#define T char

typedef struct Edge
{
	int dest;// 下标
	struct Edge* link;
}Edge;

typedef struct Vertex 
{
	T data;// 顶点元素
	Edge* adj;// 链表
}Vertex;

typedef struct GraphLnk
{
	int MaxVertices;
	int NumVertices;
	int NumEgdes;

	Vertex* NodeTable;
}GraphLnk;

void InitGraph(GraphLnk* g);
void ShowGraph(GraphLnk* g);
void InsertVertex(GraphLnk* g, T v);
void InsertEdge(GraphLnk* g, T vertex1, T vertex2);
int GetVertexPos(GraphLnk* g, T v);
void RemoveEdge(GraphLnk* g, T vertex1, T vertex2);
void RemoveVertex(GraphLnk* g, T vertex);
void DestoryGraph(GraphLnk* g);
int GetFirstNeighbor(GraphLnk* g, T vertex);
int GetNextNeighbor(GraphLnk* g, T vertex1, T vertex2);
T GetVertexValue(GraphLnk* g, int v);
/////////////////////////////////////////////////////
void DFS_Ready(GraphLnk* g, T vertex);
void DFS(GraphLnk* g, int v, int visited[]);
void BFS(GraphLnk* g, T vertex);