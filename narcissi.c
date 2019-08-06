#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//求0-999999之间的所有水仙花数
//水仙花数,一个数等于每一位的总位数的次方和
//   153=1^3+5^3+3^3
//   370=3^3+7^3+0^3   
int main()
{
	int  n,k,i,m,count=0,j=0,sum=0;
	int arr[10] = {0};
	for(n=0;n<=999999;n++){
		for (i = n,j=0; i; i = i / 10,j++)//数位遍历
		{
			m = i % 10;
			arr[j] = m;  //将数的每一位存在数组中
			count++;     //计算出总共有几位                 
		}
		for (k = 1; k <= count; k++)
		{
			j = k - 1;
			sum += pow(arr[j], count);//一个数的总位数的次方和,
		}    //一个数求数的几次方用到函数pow(int n,int m)即n^m,注意头文件<math.h>
		if (n == sum)//判断是否为水仙花数
		{
			printf("%d  ", n);
		}
		count = 0;
		sum = 0;
	}
	printf("\n");
	return 0;
}
