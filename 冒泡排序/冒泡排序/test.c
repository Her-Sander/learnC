#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��һ�˴ӵ�һ������ʼ����Ƚ�,����������С��,������������λ��,��������Ƚ�
//ֱ�������һ�����Ƚ���Ϊֹ,�����������������һ��
//�����ڶ���,�Դ�����,�δ�����ڵ����ڶ���
//���꽻����,����Ͱ���˳���ź�
void bubblesort(int *arr, int len)
{
	int i , j, tmp;
	for (i = 0; i < len - 1; i++)//����
	{
		for (j = 0; j < len - 1 - i; j++)//����
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