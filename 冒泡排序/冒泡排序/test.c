#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//第一趟从第一个数开始往后比较,若遇到比他小的,他们两个交换位置,继续往后比较
//直到和最后一个数比较完为止,这样最大的数就在最后一个
//继续第二趟,以此类推,次大的数在倒数第二个
//比完交换后,数组就按照顺序排好
void bubblesort(int *arr, int len)
{
	int i , j, tmp;
	for (i = 0; i < len - 1; i++)//趟数
	{
		for (j = 0; j < len - 1 - i; j++)//次数
		{
			if (arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
			
		}
	}
}

void show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int len;
	int arr[] = { 5,3,9,7,0,6,8,4,1,2 };
	len = sizeof(arr) / sizeof(arr[0]);
	show(arr, len);
	bubblesort(arr, len);
	show(arr, len);
	system("pause");
	return 0;
}