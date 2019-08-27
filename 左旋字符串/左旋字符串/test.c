#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void leftTrun(char *str, int n, int m)
{
	m %= n;
	int end = strlen(str);
	reverse(str, str + m - 1);
	reverse(str + m, str + end - 1);
	reverse(str, str + end - 1);
}

int main()
{
	char str[] = "ABCDE";
	leftTrun(str, 5, 3);
	puts(str);
	system("pause");
	return 0;
}