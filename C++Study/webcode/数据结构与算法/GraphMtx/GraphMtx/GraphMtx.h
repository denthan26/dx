#pragma once
#define _CRT_SECURE_NO_WARNINGSRE
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define Default_Vertex_Size 10
#define T char

typedef struct GraphMtx
{
	int MaxVertices;
	int NumVertices;
	int NumEdges;

	T* VerticesList;
	int** Edge;
}GraphMtx;

void InitGraph(GraphMtx* g);
void showGraph(GraphMtx* g);
void InsertVertix(GraphMtx* g, T v);
void InsertEdge(GraphMtx* g, T v1, T v2);
int GetVertexPos(GraphMtx* g, T v);
void RemoveVertix(GraphMtx* g, T v);
void RemoveEdge(GraphMtx* g, T v1, T v2);
void DestoryGraph(GraphMtx* g);
int GetFirstNeighbor(GraphMtx* g, T v);
int GetNextNeighbor(GraphMtx* g, T v, T w);