#include "head.h"
void enQueue(LinkQueue* queue, int min,Q client)
{
	Q* s = (Q*)malloc(sizeof(Q));
	s->data.ArrivalTime = client.data.ArrivalTime;
	s->data.Duration = client.data.Duration;
	s->next = client.next;
	queue[min].rear->next = s;
	queue[min].rear = s;
}