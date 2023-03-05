#include "head.h"
int queueLength(LinkQueue* queue, int min)
{
	int count = 0;
	Q* p;
	p = queue[min].front->next;
	while (p != queue[min].rear)
	{
		count++;
		p = p->next;
	}
	count++;
	return count;
}