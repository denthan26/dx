#include"Queue.h"
#define _CRT_SECURE_NO_WARNINGS

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

//���е�����
void QueueDestroy(Queue* pq)
{
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//���
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	/*if (newnode == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}*/
	newnode->data = x;
	newnode->next = NULL;

	//β�� - ����βָ��Ͳ�����β��
	if (pq->tail == NULL)
	{
		assert(pq->head == NULL);
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);

	//ͷɾ - ֻ��һ�ָ��������ʱtail���Ұָ��
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

//���������ݵĸ���
size_t QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	size_t size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

//��ͷ������
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

//��β������
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}
