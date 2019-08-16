#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//�ú���д��þ���һ������һ������,������ߴ���Ŀɶ��Ժ͸�Ч��,�����׳���
//ע�⴫ָ��
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
	//������һ������Ϊlen�Ĵ�0��ʼ���α�������
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
		//ע�⽻������������ַ,������Ԫ�صĵ�ַ������������Ԫ���±�
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
