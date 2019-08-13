#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>    //1   令每一行的第一个和最后一个元素等于1
#include <stdlib.h>	  //1 1
//1 * 1  从第二行开始填充元素,每一行都是从第一列开始填充
void triangle(int n)  //1 * * 1  (注意行和列从0开始)找到中间数的公式代替*即可
{
	int i, j;
	int a[20][20];
	for (i = 0; i < n; i++) //填写开始和末尾的1
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (i = 2; i < n; i++) //注意从第几行开始填写中间元素
	{
		for (j = 1; j < i; j++)//注意每一行列的开始位置即j的初值
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}   //每个数等于它上方两数之和
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