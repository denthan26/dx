#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

//记录头指针和尾指针
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//队列的初始化
void QueueInit(Queue* pq);

//队列的销毁
void QueueDestroy(Queue* pq);

//入队
void QueuePush(Queue* pq, QDataType x);

//出队
void QueuePop(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//队列中数据的个数
size_t QueueSize(Queue* pq);

//队头的数据
QDataType QueueFront(Queue* pq);

//队尾的数据
QDataType QueueBack(Queue* pq);
