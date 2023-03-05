#include "head.h"
void push(evNode evItem, EventList evList)
{
	/*格式插入，将这个结点的内容按照发生时间，插入到事件链表中*/
	EventList p,  q;
	EventList s = (EventList)malloc(sizeof(EventList));
	s->occurTime = evItem.occurTime;
	s->nType = evItem.nType;
	s->next = evItem.next;
	q = evList;
	p = evList->next;
	while (p->occurTime <= s->occurTime && p != NULL)
	{
		q = p;
		p = p->next;
	}
	if (p != NULL)
	{
		q->next = s;
		s->next = p;
	}
	else
	{
		q->next = s;
	}
}