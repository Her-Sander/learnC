#include <stdio.h>
#include <stdlib.h>
//这个题类似于打星星
//最后用i*j的式子把星星一替换就好
void Mul(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d  ", j, i, i*j);
		}
		printf("\n");
	}
}

int main()
{
	int a;
	scanf("%d", &a);
	Mul(a);
	system("pause");
	return 0;
}
