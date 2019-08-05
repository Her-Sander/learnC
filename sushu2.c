#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//判断素数条件,只能整除1和他本身
//素数可以扩展难理解一点的,不是表面看起来那么就单的
//建议好好理解一波
#if 0
int main()
{
	int i, j;
	for (i = 100; i <= 200; i++) {
		for (j = 2; j <= i; j++) {
			if (i % j == 0) {//若i整除j(2到i之间的数)
				break;//跳出当前所在for循环
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
#endif
//这里要说的是如果你给的数的值再更大一点,六位数以后的
//你会发现计算机要计算很久,主要是要进行两个for循环,效率非常之低
//所以这里使用开根号来计算
//一个数如果不能整除它开根号前的所有数,那么开根号的数到它之间的数他也不能整除
int main()
{
	int i;
	int n;
	int tmp;
	for (n = 11; n <= 100000; n++)
	{
		tmp = sqrt(n);
		for (i = 2; i <= tmp; i++)
		{
			if (n % i == 0)//n整除tmp说明i=tmp
			{              //说明n(9)除以它的开方(3),则n不为质数
				break;
			}
		}//如果循环正常结束,就说明它不能整除tmp=sqrt(n),即他自己开根号的数
		 //举个简单的例子方便理解n=9,tmp=3(循环结束条件),当循环至i=3;
		 //该循环循环到i=3时,进入if满足条件if语句条件进入if语句
		 //跳出循环,在进入下一个if语句,此时i=tmp不满足if语句条件
		 //继续下一个数n;  例如n=11; tmp=3;当循环至i=3时;
		 //11%3!=0不满足if语句,i=i+1=4;不满足循环继续下面的if;
		 //此时满足if条件i=tmp+1,进入if语句打印素数n
		 //若还有什么问题,可以打断点,给n赋初值监视三个变量进行调试理解
		if (i == tmp + 1)
		{
			printf("%d  ", n);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
