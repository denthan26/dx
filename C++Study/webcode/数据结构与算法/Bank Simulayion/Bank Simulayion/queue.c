/*���нڵ�����*/
//ÿ�����нڵ㶼�пͻ�����ʱ����ָ����һ���ͻ���ָ��
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