/*事件模拟*/
#include<stdio.h>
typedef struct evNode
{
	int occurTime;//事件开始时间
	int nType;//事件类型
	struct evNode* next;
}evNode,*EventList;

//typedef struct {
//	evNode evItem;
//	evNode* next;
//}EventList;