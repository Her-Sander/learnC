#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int find(int a[][3], int n, int find)
{
	int i = 0, j = n - 1;
	while (j >= 0 && i < n)
	{
		if (a[i][j] > find)
		{
			j--;
		}
		else if (a[i][j] < find)
		{
			i++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
//找到返回1,没找到返回0
int main()
{
	int a[3][3] = {
	{1, 3, 5},
	{3, 5, 7},
	{5, 7, 9}
	};
	printf("%d\n", find(a, 3, 7));
	system("pause");
	return 0;
}