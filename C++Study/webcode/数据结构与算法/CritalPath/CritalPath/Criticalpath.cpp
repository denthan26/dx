#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxVex 20

typedef int EdgeType;
typedef char VertexType;

// 边结点结构（链表）
typedef struct EdgeNode
{
    int adjvex;         // 该边邻接的结点下标
    EdgeType edgeData;  // 该边结点的数据（权值）
    struct EdgeNode* next;
}EdgeNode, * EdgeList;

// 顶点结点结构（顺序表）
typedef struct
{
    VertexType vextexData;  // 顶点数据
    EdgeList edgeList;      // 顶点的边链表 
    int indegree;           // 顶点的入度
    EdgeType earliest;      // 该顶点活动的最早发生时间
    EdgeType latest;        // 该顶点活动的最迟发生时间
}VertexNode, * VertexList;

// 邻接表结构
typedef struct
{
    VertexList vertexList; // 顶点顺序表
    int numVertexs, numEdges;     // 顶点数
}ALGraph;

// 初始化邻接表
void InitALGraph(ALGraph* G)
{

    G->numVertexs = 0;
    G->numEdges = 0;
    G->vertexList = (VertexNode*)malloc(MaxVex * sizeof(VertexNode));

    // 初始化边链表头结点，和顶点入度
    int i;
    for (i = 0; i < MaxVex; i++)
    {
        G->vertexList[i].edgeList = (EdgeNode*)malloc(sizeof(EdgeNode));
        G->vertexList[i].edgeList->next = NULL;
        G->vertexList[i].indegree = 0;
        G->vertexList[i].earliest = 0;
        G->vertexList[i].latest = 0;
    }
    printf("已初始化邻接表\n\n");
}

// 创建邻接表
void CreateALGraph(ALGraph* G)
{
    printf("请输入顶点数和边数:");
    scanf("%d %d", &G->numVertexs, &G->numEdges);

    int i, j, k;
    EdgeType w;
    // 输入顶点数据
    for (i = 0; i < G->numVertexs; i++)
    {
        fflush(stdin);
        printf("请输入第%d个顶点数据:", i + 1);
        getchar();
        scanf("%c", &G->vertexList[i].vextexData);
    }
    // 输入边的权值
    for (k = 0; k < G->numEdges; k++)
    {
        printf("请输入边(vi, vj)上的顶点序号及权值:");
        scanf("%d %d %d", &i, &j, &w);

        EdgeNode* p1;
        p1 = (EdgeNode*)malloc(sizeof(EdgeNode));

        // 链表头插法 插入 顶点（vi -> vj）的边
        p1->edgeData = w;
        p1->next = G->vertexList[i - 1].edgeList->next;
        G->vertexList[i - 1].edgeList->next = p1;
        p1->adjvex = j - 1;                 // 该边邻接着顶点j
        G->vertexList[j - 1].indegree++;    // 邻接顶点j的入度加一
    }
    printf("已创建邻接表!\n\n");
}

// 拓扑排序
void KeyPath(ALGraph G)
{
    // 用一个数组来代表一个栈结构，top1为栈顶指针
    int top1 = 0, Stack[MaxVex];

    // 用于存储逆序拓扑排序的逆序栈
    int top2 = 0, RStack[MaxVex];

    // 初始化
    int i, indegree[MaxVex];
    for (i = 0; i < G.numVertexs; i++)
    {
        // 获取每个顶点的入度
        indegree[i] = G.vertexList[i].indegree;
        // 初始化栈，将入度为0的顶点入栈
        if (indegree[i] == 0)
        {
            Stack[top1++] = i;
        }
    }

    // 通过拓扑排序计算顶点活动的最早发生时间
    int v;
    EdgeNode* p;
    printf("拓扑排序:");
    while (top1 > 0)
    {
        // 将入度为0的顶点出栈
        i = Stack[--top1];
        // 入栈到逆序栈中
        RStack[top2++] = i;
        printf("%c--->", G.vertexList[i].vextexData);
        // 遍历该顶点所有的后继顶点
        for (p = G.vertexList[i].edgeList->next; p; p = p->next)
        {
            v = p->adjvex;
            // 将后继顶点的入度减一
            indegree[v]--;
            // 如果后继顶点入度为零，则入栈
            if (!indegree[v])
            {
                Stack[top1++] = v;
            }
            // 更新所有后继顶点活动的最早发生时间
            if (G.vertexList[i].earliest + p->edgeData > G.vertexList[v].earliest)
            {
                G.vertexList[v].earliest = G.vertexList[i].earliest + p->edgeData;
            }
        }
    }
    printf("\n");

    if (top2 < G.numVertexs)
    {
        printf("排序失败!存在回路\n");
    }
    else
    {
        // 初始化顶点活动的最迟发生时间
        v = RStack[--top2];
        for (i = 0; i < G.numVertexs; i++)
        {
            G.vertexList[i].latest = G.vertexList[v].earliest;
        }

        // 根据逆序栈更新顶点活动的最迟发生时间
        while (top2 > 0)
        {
            // 逆序依次获取顶点
            i = RStack[--top2];
            for (p = G.vertexList[i].edgeList->next; p; p = p->next)
            {
                // 邻接的后继顶点
                v = p->adjvex;
                // 更新顶点活动的最迟发生时间
                if (G.vertexList[v].latest - p->edgeData < G.vertexList[i].latest)
                {
                    G.vertexList[i].latest = G.vertexList[v].latest - p->edgeData;
                }
            }
        }
    }
}

void Display(ALGraph G)
{
    int i;
    printf("顶点\t");
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("%c\t", G.vertexList[i].vextexData);
    }
    printf("\n最早\t");
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("%d\t", G.vertexList[i].earliest);
    }
    printf("\n最迟\t");
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("%d\t", G.vertexList[i].latest);
    }
    printf("\n关键路径:");
    for (i = 0; i < G.numVertexs; i++)
    {
        if (G.vertexList[i].latest - G.vertexList[i].earliest == 0)
        {
            printf("%C--->", G.vertexList[i].vextexData);
        }
    }
    printf("\n");
}

int main()
{
    ALGraph G;
    InitALGraph(&G);
    CreateALGraph(&G);
    KeyPath(G);
    Display(G);
    system("pause");
    return 0;
}
