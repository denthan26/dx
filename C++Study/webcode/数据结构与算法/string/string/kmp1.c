#define _CRT_SECURE_NO_WARNINGS

/*KMP算法*/
//手动计算next数组
//利用kmp算法求解

#include<stdio.h>

int kmp(char* s, char* t, char* next)
{
	int i = 0, j = 0;
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
			if (j == -1)
			{
				j++;
				i++;
			}
		}
	}
	printf("%d\n", i - j);
	if (t[j] == '\0')
		return i - j;
	else
		return -1;



}
int main()
{

	char S[] = "ADCESDABCDABDWWWD";
	char T[] = "DABCDABD";
	int next[] = { -1,0,0,0,0,1,2,3 };
	int c = kmp(S, T, next);
	if (c != -1)
	{
		printf("yes\n");
		printf("index start from %d", c);
	}
	else
		printf("sorry, no string\n");
	return 0;
}

