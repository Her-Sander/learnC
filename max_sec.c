#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[10] = { 1,3,5,6,10,8,9,3,2,13 };
	int max = 0x80000000;    //这里考虑到十个数的值是否为int类型的最小值
	int sec = 0x80000000;    //次大值
	int i = 0;               //敲代码就要细致精确
	//printf("%d\n", max);   测一哈无符号int类型的最小值
	for (i = 0; i < 10; i++) {
		if (max < a[i]) {    //从零号位置往右走遇到大于它自己的数令他们两个相等
			sec = max;       //说明max < a[i]非最大值,将最大值变为最大值
			max = a[i];      //直到大于数组中的所有数输出即可
		}                    //即遍历完整个数组
		else if(sec < a[i])
		{
			sec = a[i];
		}
	}
	printf("%d  %d\n", max,sec);
	system("pause");
	return 0;
}
