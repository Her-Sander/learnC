#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void menu() {

	printf("========================\n");

	printf("========================\n");

	printf("   1.��ʼ��Ϸ\n");

	printf("   0.�˳���Ϸ\n");

}

void game() {

	int input = 0;
	int ran = rand() % 100;

	while (1) {
		printf("\t\t��������µ����֣�");

		scanf("%d", &input);

		if (input > ran)

		{

			printf("\t\t�´��ˣ����ٲ�һ��\n\n");

		}

		else if (input < ran)

		{

			printf("��С�ˣ����ٲ�һ��\n\n");

		}

		else

		{

			printf("��ϲ��,�¶���!\n");

			break;

		}

	}

}



int main()

{

	int input = 0;

	srand((unsigned)time(NULL));//(unsigned)��ʾǿ������ת��;

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

			printf("\t\tѡ�������������������\n");

			break;

		}

	} while (input);



	system("pause");

	return 0;

}