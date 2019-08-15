#include <stdio.h>
#include <stdlib.h>

void Show(int arr[],int len) 
{
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,0 };
	int temp;
	int size = sizeof(a) / sizeof(a[0]);
	int i;
	for (i = 0; i < 5; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	Show(a, size);
	Show(b, size);
	system("pause");
	return 0;
}
