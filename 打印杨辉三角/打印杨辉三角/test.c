#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>    //1   ��ÿһ�еĵ�һ�������һ��Ԫ�ص���1
#include <stdlib.h>	  //1 1
//1 * 1  �ӵڶ��п�ʼ���Ԫ��,ÿһ�ж��Ǵӵ�һ�п�ʼ���
void triangle(int n)  //1 * * 1  (ע���к��д�0��ʼ)�ҵ��м����Ĺ�ʽ����*����
{
	int i, j;
	int a[20][20];
	for (i = 0; i < n; i++) //��д��ʼ��ĩβ��1
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (i = 2; i < n; i++) //ע��ӵڼ��п�ʼ��д�м�Ԫ��
	{
		for (j = 1; j < i; j++)//ע��ÿһ���еĿ�ʼλ�ü�j�ĳ�ֵ
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}   //ÿ�����������Ϸ�����֮��
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%-3d ", a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	triangle(10);
	system("pause");
	return 0;
}