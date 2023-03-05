//#include<stdio.h>
//#include<string.h>
//void get_next(char* t, int* next);
//int kmp(char* s, char* t, char* next);
//int main()
//{
//	char* s = "abbbbabbcdefggf";
//	char* t = "bbabbc";
//	int next[6] = { 0 };
//	int m = kmp(s, t, next);
//	printf("%d\n", m);
//	// from t get next
//	/*get_next(t, next);
//	{
//		int i;
//		for (i = 0; i < 6; i++)
//			printf("%d ", next[i]);
//	}*/
//	return 0;
//}
//int kmp(char* s, char* t, char* next)
//{
//	int i = 0, j = 0;
//	int lens = strlen(s);
//	int lent = strlen(t);
//	while (i < lens && j < lent) {
//		if (j == -1 || s[i] == t[i]) {
//			i++;
//			j++;
//		}
//		else {
//			j = next[j];
//		}
//	}
//	if (j == lent)
//		return i - j;
//	else
//		return -1;
//}
//void get_next(char* t, int* next) {
//	int i = 0, j = -1;
//	next[i] = j;
//	while (i < 6) {
//		if (j == -1 || t[i] == t[j]) {
//			j++; 
//			i++;
//			next[i] = j;
//		}
//		else {
//			j = next[j];
//		}
//	}
//}

#include <stdio.h>
#include <string.h>

void Next(char* T, int* next) {
    int j = 0;
    int i = 1;
    next[1] = 0;
    while (i < strlen(T)) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}
int KMP(char* S, char* T) {
    int next[10];
    int i = 1;
    int j = 1;
    Next(T, next);//根据模式串T,初始化next数组
    while (i <= strlen(S) && j <= strlen(T)) {
        //j==0:代表模式串的第一个字符就和当前测试的字符不相等；S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
        if (j == 0 || S[i - 1] == T[j - 1]) {
            i++;
            j++;
        }
        else {
            j = next[j];//如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
        }
    }
    if (j > strlen(T)) {//如果条件为真，说明匹配成功
        return i - (int)strlen(T);
    }
    return -1;
}
int main() {
    int i = KMP("ababbabbcacbab", "bbabbc");
    printf("%d", i);
    return 0;
}