#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//用函数写最好就是一个函数一个功能,这样提高代码的可读性和高效性,不容易出错
//注意传指针
void Swap(int *n, int *m)
{
	int tmp;
	tmp = *n;
	*n = *m;
	*m = tmp;
}

void InitArr(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		arr[i] = i;
	}
	//定义了一个长度为len的从0开始依次变大的数组
}

void EmptyArr(int arr[],int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}

void ReverseArr(int *arr, int len)
{
	int i = 0, j;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		//注意交换两个数传地址,数组内元素的地址等于数组名加元素下标
		Swap(arr+i, arr+j);
	}
}

void print(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	InitArr(arr, size);
	print(arr, size);
	ReverseArr(arr, size);
	print(arr, size);
	EmptyArr(arr, size);
	print(arr, size);
	system("pause");
	return 0;
}
