#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

unsigned int Reverse()
{
	unsigned int n = 25;
	unsigned int sum = 0;
	int i;
	for (i = 0; i < 32; i++, n /= 2)
	{
		sum = sum * 2 + n % 2;
	}
	printf("%u", sum);
	return 0;
}
int main()
{
	Reverse();
	system("pause");
	return 0;
}