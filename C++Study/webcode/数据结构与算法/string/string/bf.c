#define _CRT_SECURE_NO_WARNINGS

/*BF算法*/
//查找字符串

#include<stdio.h>
int main()
{
	//自定义一个字符串
	//接收一个字符串
	//比较
	char S[] = "acabaabcaabaabcac";
	char T[] = "abaabcac";
	int i = 0, j = 0;
	while (1)
	{
		if (T[j] == S[i])
		{
			j++;
			i++;
			if (T[j] == '\0')
			{
				printf("yes\n");
				printf("原字符串的下标%d的位置", i - j);
				break;
			}
			else if (S[i] == '\0')
			{
				printf("no string\n");
				break;
			}
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		
	}
	
	

	

	return 0;
}



