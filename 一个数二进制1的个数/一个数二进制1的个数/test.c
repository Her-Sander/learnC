#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int number(unsigned int n)
{
	int count=0,i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((n & 1) != 0)
		{
			count++;
			
		}
		n = n >> 1;
	}
	return count;
}


int number1(unsigned int n)
{
	int count = 0;
	while (n != 0)
	{
		if ((n & 1) != 0)
		{
			count++;
		}
		n = n >> 1;
	}
	return count;
}

int number2(unsigned int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	printf("%d ", number1(-1));
	system("pause");
	return 0;
}