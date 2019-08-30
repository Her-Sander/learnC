#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void menu() {

	printf("========================\n");

	printf("========================\n");

	printf("   1.开始游戏\n");

	printf("   0.退出游戏\n");

}

void game() {

	int input = 0;
	int ran = rand() % 100;

	while (1) {
		printf("\t\t请输入你猜的数字：");

		scanf("%d", &input);

		if (input > ran)

		{

			printf("\t\t猜大了，请再猜一次\n\n");

		}

		else if (input < ran)

		{

			printf("猜小了，请再猜一次\n\n");

		}

		else

		{

			printf("恭喜你,猜对了!\n");

			break;

		}

	}

}



int main()

{

	int input = 0;

	srand((unsigned)time(NULL));//(unsigned)表示强制类型转换;

	do

	{

		menu();

		scanf("%d", &input);

		switch (input)

		{

		case 1:

			game();

			break;

		case 0:

			break;

		default:

			printf("\t\t选择错误，请重新输入数字\n");

			break;

		}

	} while (input);



	system("pause");

	return 0;

}