#include<stdio.h>
#include "head.h"
void initpush(evNode evItem, EventList evList)
{
	EventList p = evList;
	EventList s = (EventList)malloc(sizeof(evNode));
	s->nType = evItem.nType;
	s->occurTime = evItem.occurTime;
	s->next = NULL;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;

}