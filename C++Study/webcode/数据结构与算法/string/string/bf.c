#define _CRT_SECURE_NO_WARNINGS

/*BF�㷨*/
//�����ַ���

#include<stdio.h>
int main()
{
	//�Զ���һ���ַ���
	//����һ���ַ���
	//�Ƚ�
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
				printf("ԭ�ַ������±�%d��λ��", i - j);
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



