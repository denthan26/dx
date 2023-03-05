#pragma once
#define CLOCK_TIME 40
#define MAX_DURATION 30
#define MAX_INTERTIME 10
/* const int CLOSE_TIME = 40;//银行关门时间
 const int MAX_DURATION = 30;//每位客户最大服务时间为30分钟
const int MAX_INTERTIME = 10;//下一位客户到来的最大时间间隔为10分钟

    因此生成的随机数durTime代表当前客户服务时间，应该在1-30的范围内随机
	生成；interTime代表下一个客户到来的间隔时间，
	应该在1-10的范围内随机生成。 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "client.c"
#include "queue.c"
#include "list.c"
#include "pop.c"
double simulation()
{
	evNode evTemp;
	int TotalTime = 0;//计算客户服务的总时间
	int customerNum = 0;//存放总客户人数
	//创建4个银行窗口
	LinkQueue queue[4];
	//设置事件链表
	EventList evList = (EventList)malloc(sizeof(evNode));
	//初始化链表为空
	evList->next = NULL;
	//初始化事件链表的第一个节点
	evNode evItem;
	evItem.occurTime = 0;
	evItem.nType = -1;
	evItem.next = NULL;
	//将evItem push进事件链表
	initpush(evItem, evList);
	//将每个窗口的next设为NULL；
	queue[0].data.next = NULL;
	queue[0].front = queue[0].rear = &queue[0];
	queue[1].data.next = NULL;
	queue[1].front = queue[1].rear = &queue[1];
	queue[2].data.next = NULL;
	queue[2].front = queue[2].rear = &queue[2];
	queue[3].data.next = NULL;
	queue[3].front = queue[3].rear = &queue[3];
	while (!isEmpty(evList))//事件链表有内容，需要进行工作
	{
		evNode temp = pop(evList);
		evItem.occurTime = temp.occurTime;
		evItem.nType = temp.nType;
		if (evItem.nType == -1)
		{
			/*有新客户来了*/
			//客户人数+1，并获取新客户的到达时间与需要服务的时间
			int duraTime = rand() % 30 + 1;//[1,30],客户服务时间
			int interTime = rand() % 10 + 1;//[1,10],下个客户到来时间
			int min;
			if (evItem.occurTime + interTime < CLOCK_TIME)
			{
				//在银行关门之前到来
				//将即将到来的客户插入事件链表
				//事件链表包括事件开始时间，事件类型
				//创建事件节点
				
				evTemp.occurTime = evItem.occurTime;
				evTemp.nType = -1;
				evTemp.next = NULL;
				//将事件结点插入事件链表
				push(evTemp, evList);
			}
			//以上是对即将到来的客户进行操作
			//下面是对当前的客户进行分配银行窗口
			//首先找到当前4个窗口人最少的窗口
			min = findMin(queue);
			Q client;
			client.data.ArrivalTime = evItem.occurTime;
			client.data.Duration = duraTime;
			client.next = NULL;
			enQueue(queue, min, client);
			//如果当前窗口只有一个客户则将这个客户事件放入事件链表
			if (queueLength(queue, min) == 1)
			{
				/*evNode evTemp;*/
				evTemp.occurTime = evItem.occurTime + duraTime;
				evTemp.nType = min;
				evTemp.next = NULL;
				push(evTemp, evList);
			}
		}
		else
		{
			/*有就客户要离开了*/
		}
	}
}