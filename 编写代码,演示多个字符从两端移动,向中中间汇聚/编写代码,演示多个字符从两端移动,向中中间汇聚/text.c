#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
int main() {
	char str1[] = "my dear girl!";
	char str2[] = "               ";
	int left = 0;
	int right = strlen(str2) - 1;
	while (left <= right) {
		printf("%s\n", str2);
		str2[left] = str1[left];
		str2[right] = str1[right];
		++left;
		--right;
		Sleep(500);
		system("cls");
	}
	system("pause");
	return 0;
}