#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void reverse(char * start, char * end)
{
	char tmp;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void reverseString(char * src)
{
	int i;
	char * start = src;
	char * end;
	for (i = 0; src[i]; i++)
	{
		if (src[i] == ' ')
		{
			end = src + i - 1;
			reverse(start, end);
			start = src + i + 1;
		}
	}
	end = src + i - 1;
	reverse(start, end);
	reverse(src, end);
}
//使用库函数
void reverseStringS(char * src)
{
	char * tmp;
	char dest[100] = { 0 };


	while (tmp = strrchr(src, ' '))
	{
		strcat(dest, tmp + 1);
		strcat(dest, " ");
		*tmp = 0;
	}
	strcat(dest, src);
	strcpy(src, dest);
}

int main()
{
	char str[] = "i am a gentleman";
	reverseStringS(str);
	puts(str);//打印字符串的方法
	system("pause");
	return 0;
}