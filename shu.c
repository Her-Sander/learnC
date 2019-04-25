#include <stdio.h>
#include <stdlib.h>
int main() {
	int i;
	int a, b, c,sum;
	for(i=100;i<=999;i++){
	    a = i % 10;
	    b = i / 10 % 10;
	    c = i / 100;
	    sum = a * a * a + b * b * b + c * c * c;
	    if (sum == i) {
		printf("%d\n", i);
	    }
	}
	system("pause");
	return;
}
