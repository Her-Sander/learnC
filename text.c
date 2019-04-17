#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int mul(int n, int k) {
	if (k == 0) {
		return 1;
	}
	return n * mul(n,k-1);
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", mul(n, k));
	system("pause");
	return;
}