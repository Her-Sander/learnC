#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//0异或任何数都等于任何数
//两个相同的数异或等于0
//让0异或遍历数组,成对的数相互抵消,剩下单独出现的
int single(int *arr,int len)
{
	int i,tmp=0;
	for (i = 0; i < len; i++)
	{
		tmp ^= arr[i];
	}
	return tmp;
}

int main()
{
	int size;
	int arr[11] = { 1,2,3,4,5,6,5,4,3,2,6 };
	size = sizeof(arr) / sizeof(arr[0]);
	printf("%d ", single(arr, size));
	system("pause");
	return 0;
}