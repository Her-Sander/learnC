#include <stdio.h>
#include <stdlib.h>
int searchArray(int arr[], int n, int f) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] < f) {
			left = mid + 1;
		}
		else if (arr[mid] > f) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n",searchArray(a, 10, 6));
	system("pause");
	return 0;
}
