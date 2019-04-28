#include <stdio.h>
#include <stdlib.h>
int main() {
	int n = 0;
	for (n = 'A'; n <= 'D'; n++) {
		/*A说：不是我。
			B说：是C。
			C说：是D。
			D说：C在胡说*/
		if ((n != 'A') + (n == 'C') + (n == 'D') + (n != 'D') == 3) {
			printf("凶手是%c\n", n);
		}
	}
	system("pause");
	return 0;
}
