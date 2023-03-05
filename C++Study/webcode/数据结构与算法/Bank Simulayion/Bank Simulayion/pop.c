#include "head.h"
evNode pop(EventList evList)
{
	EventList p,  q;
	evNode temp;
	p = evList->next;
	q = evList;
	temp = *p;
	q->next = p->next;
	free(p);
	return temp;

}