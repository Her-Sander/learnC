#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu() {
	printf("=====================\n");
	printf("    1. 开始游戏\n");
	printf("    0. 结束游戏\n");
	printf("=====================\n");
	printf(" 请输入您的选择: \n");
	int choice = 0;
	scanf("%d",&choice);
	return choice;
}
#define MAX_ROW 3
#define MAX_COL 3 

char chess_board[MAX_ROW][MAX_COL];

void Init() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			chess_board[row][col] = ' ';
		}
	}
	//设置随机种子
	srand((unsigned int)time(0));
}

void Print() {
	for (int row = 0; row < MAX_ROW; ++row) {
		printf("| %c | %c | %c |\n", chess_board[row][0],
			chess_board[row][1], chess_board[row][2]);
		if (row != MAX_ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
	//调试程序临时加的.最好加一个统一等个的注释
	//TODO
	//system("pause");
}
void PlayerMove() {
	printf("玩家落子!\n");

	while (1) {
		printf("请输入落子位置的坐标(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//检查用户输入坐标是否合法
		if (row < 0 || row >= MAX_ROW || col < 0 || col >=  MAX_COL) {
			printf("您输入的坐标非法!请重新输入!\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("您要落子的位置已经被占用了!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("玩家落子完毕!\n");
}
void ComputerMove() {
	printf("电脑落子!\n");
	while (1) {
		int row = rand() % 3;
	    int col = rand() % 3;
	if (chess_board[row][col] != ' ') {
		continue;
	}
	chess_board[row][col] = 'o';
	break;
}
	printf("电脑落子完毕!\n");
}
//如果棋盘满了返回1,否则返回0
int IsFull() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] == ' ') {
				return 0;
			}
		}
	}
}
//用返回值表示胜利者是谁
//x 玩家胜
//o 电脑胜
//q 和棋
//' '胜负未分
char CheckWinner() {
	//检查左右行列对角线是否连成一条线
	for (int row = 0; row < MAX_ROW; ++row) {
		if (chess_board[row][0] == chess_board[row][1]
			&& chess_board[row][1] == chess_board[row][2]) {
			return chess_board[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; ++col) {
		if (chess_board[0][col] == chess_board[1][col]
			&& chess_board[0][col] == chess_board[2][col]) {
			return chess_board[0][col];
		}
	}
	if (chess_board[0][0] == chess_board[1][1]
		&& chess_board[0][0] == chess_board[2][2]) {
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1]
		&& chess_board[0][2] == chess_board[2][0]) {
		return chess_board[0][2];
	}
	if (IsFull()) {
		return 'q';
	}
	return ' ';
}

void Game() {
	Init();
	char winner = ' ';
	while (1) {
		Print();
		PlayerMove();
		
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'x') {
		printf("您赢了!\n");
	}
	else if (winner == 'o') {
		printf("您真菜,连电脑都下不过!\n");
	}
	else if (winner == 'q') {
		printf("您和电脑五五开!\n");
	}
	else {
		printf("电脑好像bug了!\n");
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
