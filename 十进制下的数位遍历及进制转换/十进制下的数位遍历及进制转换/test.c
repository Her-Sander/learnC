#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//��λ������������

void digit(int n)
{
	int i, j , m;
	for (i = n , j = 0; i ; i=i/10 ,j++) 
	{
		m = i % 10;
		printf("%d ", m);
	}
}

//�ݹ����λ����
void digit1(int n)
{
	if (n == 0)
	{
		 return;
	}
	//printf("%d ", n % 10);//���Ŵ�ӡλ��  �ȴ�ӡ �ٷ���
	digit1(n / 10);
	printf("%d ", n % 10);//˳�Ŵ�ӡλ��    �߷��رߴ�ӡ
	/*
	if(n>9)
	{
		digit1(n/10);
	}
	printf("%d ",n%10);
	*/
}

//�ݹ������ÿһλ��

int digitsum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n % 10 + digitsum(n / 10);
}

void digit2(int n,int m)//n��ʾ�������,m��ʾҪת���Ľ���
{
	if (n == 0)
	{
		return;
	}
	digit2(n / m , m);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);//36���µĽ�ֹ������ת��
}

int main()
{
	//int ret= digitsum(1234);
	digit2(1234,16);
	//printf("%d ", ret);
	system("pause");
	return 0;
}