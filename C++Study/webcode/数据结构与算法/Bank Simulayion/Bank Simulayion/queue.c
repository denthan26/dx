/*队列节点设置*/
//每个队列节点都有客户到达时间与指向下一个客户的指针
#include<stdio.h>
#include "client.c"
typedef struct queue
{
	Client data;
	struct queue* next;
}Q;

typedef struct
{
	Q data;
	Q* front, * rear;
	int length;
}LinkQueue;