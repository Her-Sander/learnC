#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
//三位数总共六种情况,用if else缕清思路慢慢来基本就OK
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		if (c > a)
		{
			printf("%d %d %d", c, a, b);
		}
		else if (b > c) 
		{
			printf("%d %d %d", a, b, c);
		}
		else
		{
			printf("%d %d %d", a, c, b);
		}
	}
	else
	{
		if (c > b)
		{
			printf("%d %d %d", c, b, a);
		}
		else if (c > a)
		{
			printf("%d %d %d", b, c, a);
		}
		else
		{
			printf("%d %d %d", b, a, c);
		}
	}
	system("pause");
	return 0;
}
