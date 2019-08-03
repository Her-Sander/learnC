#include <stdio.h>
#include <stdlib.h>
//判断素数条件,只能整除1和他本身
int main()
{
	int i, j;
	for (i = 100; i <= 200; i++) {
		for (j = 2; j <= i; j++) {
			if (i % j == 0) {//若i整除j(2到i之间的数)
				break;         //跳出当前所在for循环
			}
		}
		if (i == j){
			//在上一个条件下(若i整除j(2到i之间的数))且i=j,则输出i
			//说明i只能整除1和它本身
			printf("%d  ", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
