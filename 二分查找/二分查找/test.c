#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//用二分查找在数组中查找一个数:数组必须有序
//找到了返回该数在数组中的下标,没有找到则返回-1
//二分查找效率非常之高
int binarysearch(int *arr, int size, int n)
{
	int  mid, left = 0, right = size - 1;
	while (left <= right)
	{
		int i = 0;
		mid = (left + right) / 2;
		if (n < arr[mid])
		{
			right = mid - 1;
		}
		else if (n > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int len;
	int arr[] = { 4, 6,33, 56, 78,89,99,100 };
	len = sizeof(arr) / sizeof(arr[0]);
	printf("%d ", binarysearch(arr, len, 100));
	system("pause");
	return 0;
}