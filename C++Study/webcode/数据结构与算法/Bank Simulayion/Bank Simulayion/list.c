/*�¼�ģ��*/
#include<stdio.h>
typedef struct evNode
{
	int occurTime;//�¼���ʼʱ��
	int nType;//�¼�����
	struct evNode* next;
}evNode,*EventList;

//typedef struct {
//	evNode evItem;
//	evNode* next;
//}EventList;