#include<stdio.h>
void fun1(int* m);
int main()
{
	int i = 5;
	int* p = &i;
	printf("%p\n", &i);
	printf("%p\n", &p);
	printf("%d\n", sizeof((p)));
	fun1(p);
	return 0;
}
void fun1(int* m)
{
	*m = *m + 1;
	printf("%p\n", &(*m));
	
}