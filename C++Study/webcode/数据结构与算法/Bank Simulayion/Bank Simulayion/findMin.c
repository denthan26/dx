#include "head.h"
int findMin(const LinkQueue* queue)
{
	int count[4] = { 0 };
	int i;
	int min;
	int index = 0;
	for (i = 0; i < 4; i++)
	{
		LinkQueue* p = queue[i].front;
		if (p == queue[i].rear)
		{
			continue;
		}
		else
		{
			do
			{
				count[i]++;
				p = p->data.next;
			} while (p!=queue[i].rear);
		}
	}
	if (count[0] == count[1] && count[1] == count[2] && count[2] == count[3])
		return 0;
	//找出最小值的下标
	min = count[0];
	for (i = 0; i < 4; i++)
	{
		if (min > count[i])
		{
			min = count[i];
			index = i;
		}

	}
	return i;
}