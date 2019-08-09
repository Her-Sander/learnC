#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//数位遍历正常函数

void digit(int n)
{
	int i, j , m;
	for (i = n , j = 0; i ; i=i/10 ,j++) 
	{
		m = i % 10;
		printf("%d ", m);
	}
}

//递归的数位遍历
void digit1(int n)
{
	if (n == 0)
	{
		 return;
	}
	//printf("%d ", n % 10);//倒着打印位数  先打印 再返回
	digit1(n / 10);
	printf("%d ", n % 10);//顺着打印位数    边返回边打印
	/*
	if(n>9)
	{
		digit1(n/10);
	}
	printf("%d ",n%10);
	*/
}

//递归的数的每一位和

int digitsum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n % 10 + digitsum(n / 10);
}

void digit2(int n,int m)//n表示输入的数,m表示要转换的进制
{
	if (n == 0)
	{
		return;
	}
	digit2(n / m , m);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);//36以下的进制都可以转换
}

int main()
{
	//int ret= digitsum(1234);
	digit2(1234,16);
	//printf("%d ", ret);
	system("pause");
	return 0;
}
