#include<stdio.h>
#include"head.h"
int isEmpty(EventList* evList)
{
	EventList p = evList;
	if (p->next != NULL)
	{
		return 0;//²»Îª¿Õ
	}
	else
	{
		return 1;//Îª¿Õ
	}
}