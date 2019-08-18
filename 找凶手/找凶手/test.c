#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	for (n = 'A'; n <= 'D'; n++)
	{
		if ((n != 'A') + (n == 'C') + (n == 'D') + (n != 'D') == 3)
		{
			printf("%cÊÇÐ×ÊÖ\n", n);
		}
	}
	system("pause");
	return 0;
}