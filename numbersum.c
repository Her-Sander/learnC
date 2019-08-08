#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//求前N项和
//求a+aa+aaa+aaaa+aaaaa
//看到这类问题直接迭代法
//tmp=_____(直接写自己根据式子推导出的公式)
//sum += tmp
//用好了可以解决这一类的问题
int numbersum(int a, int n)
{
	int i, tmp = 0, sum = 0;
	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	return sum;
}


int main() 
{
	printf("%d", numbersum(2, 3));
	system("pause");
	return 0;
}
