#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//ธ๘20ิช
int main()
{
	int n = 20;
	int sum = 0;
	int ex = 0;
	int i;

	for (i = n; i > 0; i /= 2)
	{
		sum += i;
		i += ex;
		ex = i % 2;
	}

	printf("%d\n", sum);
	system("pause");
	return 0;
}