#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Menu() {
	printf("=================\n");
	printf("   1.开始游戏\n");
	printf("   0.结束游戏\n");
	printf("=================\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	//1.对于show_map,需要设为*
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			show_map[row][col] = '*';
		}
	}
	//2.对于mine_map,需要随机生成若干个地雷,使用0不是地雷,使用1是地雷
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			mine_map[row][col] = '0';
		}
	}
	int n = MINE_COUNT;
	while (n > 0) {
		//生成一组坐标
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			//该位置已经是地雷,需要重新生成
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}

void PrintMap(char map[MAX_ROW][MAX_COL]) {
	//不光打印地图,还能带坐标
	//先打印第一行
	printf("    ");
	for (int col = 0; col < MAX_COL; ++col) {
		printf("%d ", col);
	}
	printf("\n");
	//打印一个分割线
	for (int col = 0; col < MAX_COL - 2; ++col) {
		printf("---");
	}
	printf("\n");
	//再打印其他行
	for (int row = 0; row < MAX_ROW; ++row) {
		printf(" %d| ",row);
	//打印本行的每一列
		for (int col = 0; col < MAX_COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void UpdateShowMap(int row, int col, char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	//根据当前位置来判定这个位置的周围8个格子有几个地雷,
	//并且将这个数字更新到shop_map中
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
	//得到了周围八个格子中地雷的个数
	//假设count为2,实际看到的是字符2,'2'也就是ASCII中的42
	show_map[row][col] = '0' + count;
}

void Game() {
	//1.先创建地图,并初始化
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//已经翻开的空格的个数(非地雷)
	int blank_count_already_show = 0;
	Init(show_map, mine_map);
	while (1) {
	    //2.打印地图;
		PrintMap(show_map);
		//TODO打印为了调试临时加的
		PrintMap(mine_map);
		//3.让用户输入坐标并检查合法性
		printf("请输入一组坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//在这里清屏,清掉之前打印的内容
		system("cls");
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("您的输入非法!请重新输入!\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("您输入的位置已经翻开了!\n");
			continue;
		}
		//4.判定是否是地雷
		if (mine_map[row][col] == '1') {
			printf("游戏结束!\n");
			PrintMap(mine_map);
			break;
		}
		//5.判定游戏是否胜利,判断所有非地雷位置都被翻开了
		++blank_count_already_show;
		if (blank_count_already_show == MAX_COL * MAX_COL - MINE_COUNT) {
			printf("游戏胜利!\n");
			PrintMap(mine_map);
			break;
		}
		//6.统计当前位置周围雷的个数
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
			printf("您的输入有误!\n");
		}
	}

	system("pause");
	return 0;
}
