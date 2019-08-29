#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Menu() {
	printf("=================\n");
	printf("   1.��ʼ��Ϸ\n");
	printf("   0.������Ϸ\n");
	printf("=================\n");
	printf("����������ѡ��: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	//1.����show_map,��Ҫ��Ϊ*
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			show_map[row][col] = '*';
		}
	}
	//2.����mine_map,��Ҫ����������ɸ�����,ʹ��0���ǵ���,ʹ��1�ǵ���
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			mine_map[row][col] = '0';
		}
	}
	int n = MINE_COUNT;
	while (n > 0) {
		//����һ������
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			//��λ���Ѿ��ǵ���,��Ҫ��������
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}

void PrintMap(char map[MAX_ROW][MAX_COL]) {
	//�����ӡ��ͼ,���ܴ�����
	//�ȴ�ӡ��һ��
	printf("    ");
	for (int col = 0; col < MAX_COL; ++col) {
		printf("%d ", col);
	}
	printf("\n");
	//��ӡһ���ָ���
	for (int col = 0; col < MAX_COL - 2; ++col) {
		printf("---");
	}
	printf("\n");
	//�ٴ�ӡ������
	for (int row = 0; row < MAX_ROW; ++row) {
		printf(" %d| ",row);
	//��ӡ���е�ÿһ��
		for (int col = 0; col < MAX_COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void UpdateShowMap(int row, int col, char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	//���ݵ�ǰλ�����ж����λ�õ���Χ8�������м�������,
	//���ҽ�������ָ��µ�shop_map��
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 && mine_map[row - 1][col - 1] == '1'
		&& row - 1 < MAX_ROW && col - 1 < MAX_COL) {
		++count;
	}	
	if (row - 1 >= 0 && col >= 0 && mine_map[row - 1][col] == '1'
		&& row - 1 < MAX_ROW && col < MAX_COL) {
		++count;
	}
	if (row - 1 >= 0 && col + 1 >= 0 && mine_map[row - 1][col + 1] == '1'
		&& row - 1 < MAX_ROW && col + 1 < MAX_COL) {
		++count;
	}
	if (row >= 0 && col - 1 >= 0 && mine_map[row][col - 1] == '1'
		&& row < MAX_ROW && col - 1 < MAX_COL) {
		++count;
	}
	if (row >= 0 && col + 1 >= 0 && mine_map[row][col + 1] == '1'
		&& row < MAX_ROW && col + 1 < MAX_COL) {
		++count;
	}
	if (row + 1 >= 0 && col - 1 >= 0 && mine_map[row + 1][col - 1] == '1'
		&& row + 1 < MAX_ROW && col - 1 < MAX_COL) {
		++count;
	}
	if (row + 1 >= 0 && col >= 0 && mine_map[row + 1][col] == '1'
		&& row + 1 < MAX_ROW && col < MAX_COL) {
		++count;
	}
	if (row + 1 >= 0 && col + 1 >= 0 && mine_map[row + 1][col + 1] == '1'
		&& row + 1 < MAX_ROW && col +1 < MAX_COL) {
		++count;
	}
	//�õ�����Χ�˸������е��׵ĸ���
	//����countΪ2,ʵ�ʿ��������ַ�2,'2'Ҳ����ASCII�е�42
	show_map[row][col] = '0' + count;
}

void Game() {
	//1.�ȴ�����ͼ,����ʼ��
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//�Ѿ������Ŀո�ĸ���(�ǵ���)
	int blank_count_already_show = 0;
	Init(show_map, mine_map);
	while (1) {
	    //2.��ӡ��ͼ;
		PrintMap(show_map);
		//TODO��ӡΪ�˵�����ʱ�ӵ�
		PrintMap(mine_map);
		//3.���û��������겢���Ϸ���
		printf("������һ������(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//����������,���֮ǰ��ӡ������
		system("cls");
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("��������Ƿ�!����������!\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("�������λ���Ѿ�������!\n");
			continue;
		}
		//4.�ж��Ƿ��ǵ���
		if (mine_map[row][col] == '1') {
			printf("��Ϸ����!\n");
			PrintMap(mine_map);
			break;
		}
		//5.�ж���Ϸ�Ƿ�ʤ��,�ж����зǵ���λ�ö���������
		++blank_count_already_show;
		if (blank_count_already_show == MAX_COL * MAX_COL - MINE_COUNT) {
			printf("��Ϸʤ��!\n");
			PrintMap(mine_map);
			break;
		}
		//6.ͳ�Ƶ�ǰλ����Χ�׵ĸ���
		UpdateShowMap(row, col, show_map, mine_map);
	}
}
int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		else {
			printf("������������!\n");
		}
	}

	system("pause");
	return 0;
}