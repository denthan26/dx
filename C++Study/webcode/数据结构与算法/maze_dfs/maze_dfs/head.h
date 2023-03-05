//#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#define M 8
//#define N 8
//#include<stdio.h>
//
//typedef struct box {
//	int x;
//	int y;
//	int di;
//}Box;
//typedef struct stack {
//	Box list[50];
//	int rear;
//}*Stack, S;
//typedef struct direct {
//	int x;
//	int y;
//}Direct;
//
//void push(Stack s, Box temp);
//Box pop(Stack s);
//int fingPath(int maze[10][10], Stack s, const Direct direct[4]);
//int fingPath(int maze[10][10], Stack s, const Direct direct[4])
//{
//	Box temp;
//	int x, y, di;
//	int line, col;
//	maze[1][1] = -1;
//	temp.di = -1;
//	temp.x = 1;
//	temp.y = 1;
//	push(s, temp);
//	while (s->rear != -1)
//	{
//		temp = pop(s);
//		x = temp.x;
//		y = temp.y;
//		di = temp.di + 1;
//		while (di < 4)
//		{
//			line = x + direct[di].x;
//			col = y + direct[di].y;
//			if (maze[line][col] == 0)
//			{
//				temp.x = x;
//				temp.y = y;
//				temp.di = di;
//				push(s, temp);
//				x = line;
//				y = col;
//				if (x == M && y == N)
//					return 1;
//				di = 0;
//			}
//			else
//			{
//				di++;
//			}
//		}
//
//	}
//	return 0;
//}
//
//void push(Stack s, Box temp)
//{
//	s->rear++;
//	s->list[s->rear].x = temp.x;
//	s->list[s->rear].y = temp.y;
//	s->list[s->rear].di = temp.di;
//}
//
//Box pop(Stack s)
//{
//	Box now;
//	now.x = s->list[s->rear].x;
//	now.y = s->list[s->rear].y;
//	now.di = s->list[s->rear].di;
//	s->rear--;
//	return now;
//}