#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void printArray(int * arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int OddFront()
{
	int a[8] = { 1, 1, 3, 3, 5, 5, 7, 7 };
	int size = 8;
	int * front = a;
	int * end = a + size - 1;
	int tmp;

	while (*front % 2 && front - a < size)
	{
		front++;
	}

	while (!(*end % 2) && end >= a)
	{
		end--;
	}

	while (front < end)
	{
		tmp = *front;
		*front = *end;
		*end = tmp;
		while (*front % 2)
		{
			front++;
		}
		while (!(*end % 2))
		{
			end--;
		}
	}
	printArray(a, size);
	return 0;
}
int main()
{
	OddFront();
	system("pause");
	return 0;
}