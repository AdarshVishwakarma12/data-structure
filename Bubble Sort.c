#include<stdio.h>

void main() {
	int arr[] = {100, 0, 1, 20, 3, 4, 9, 6, 7, 8, 9, 100, 0};
	int len = sizeof(arr) / sizeof(int);

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 1; i < len; i++) {
		int adaptive = 1;
		for (int j = 0; j < len - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
				adaptive = 0;
			}
		}
		if (adaptive == 1) {break;}
	}

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}