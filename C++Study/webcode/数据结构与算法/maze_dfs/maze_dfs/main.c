
#define _CRT_SECURE_NO_WARNINGS
#define M 8
#define N 8
#include<stdio.h>

typedef struct box {
	int x;
	int y;
	int di;
}Box;

typedef struct stack {
	Box list[50];
	int rear;
}*Stack, S;

typedef struct direct {
	int x;
	int y;
}Direct;

void push(Stack s, Box temp);
Box pop(Stack s);

int main()
{
	Box temp;
	int x, y, di;
	int line, col;
	int i;
	int maze[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	Direct direct[4];
	Stack p;
	S stack;
	stack.rear = -1;
	p = &stack;
	direct[0].x = 0;
	direct[0].y = 1;
	direct[1].x = 1;
	direct[1].y = 0;
	direct[2].x = 0;
	direct[2].y = -1;
	direct[3].x = -1;
	direct[3].y = 0;

	
		
		maze[1][1] = -1;
		temp.di = -1;
		temp.x = 1;
		temp.y = 1;
		push(p, temp);
		while (p->rear != -1)
		{
			temp = pop(p);
			x = temp.x;
			y = temp.y;
			di = temp.di + 1;
			while (di < 4)
			{
				line = x + direct[di].x;
				col = y + direct[di].y;
				if (maze[line][col] == 0)
				{
					temp.x = x;
					temp.y = y;
					temp.di = di;
					push(p, temp);
					//printf("%d,%d,%d存入栈\n", x, y, di);
					maze[x][y] = -1;
					x = line;
					y = col;
					if (x == M && y == N)
					{
						printf("yes\n");
						for (i = 0; i <= p->rear; i++)
						{
							printf("在%d,%d处,走%d方向\n", p->list[i].x, p->list[i].y, p->list[i].di);
						}
						return 0;
						
					}
					di = 0;
				}
				else
				{
					di++;
				}
			}


		}


	printf("no");
	return 0;
}


void push(Stack s, Box temp)
{
	s->rear++;
	s->list[s->rear].x = temp.x;
	s->list[s->rear].y = temp.y;
	s->list[s->rear].di = temp.di;
}

Box pop(Stack s)
{
	Box now;
	now.x = s->list[s->rear].x;
	now.y = s->list[s->rear].y;
	now.di = s->list[s->rear].di;
	s->rear--;
	return now;
}