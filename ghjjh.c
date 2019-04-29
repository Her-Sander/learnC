#include <stdio.h>
#include <stdlib.h>
int main() {
	int data[20][20] = { 0 };
	int n = 4;
	int i, j;
	printf("%d\n", data[0][0] = 1);
	for (i = 1; i < n; i++) {
		printf("%d ", data[i][0] = 1);
		for (j = 1; j < i; j++) {
			printf("%d ", data[i][j] = data[i - 1][j - 1]
				+ data[i - 1][j]);
		}
		printf("%d\n", data[i][j] = 1);
	}
	system("pause");
	return 0;
}
