#include<stdio.h>

void display(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int task(int *arr, int left, int right) {
	int pivot = left;
	int i = left + 1;
	int j = right;

	while (1) {
		while (arr[i] < arr[pivot] && i != right) {i++;}
		while (arr[j] > arr[pivot]) {j--;}

		if (i == right) {int swap = arr[i]; arr[i] = arr[pivot]; arr[pivot] = swap; return i;}
		else if (j == left) {return pivot;}
		else if (j > i) {int swap = arr[i]; arr[i] = arr[j]; arr[j] = swap;}
		else if (j < i) {int swap = arr[pivot]; arr[pivot] = arr[j]; arr[j] = swap; return j;}
		else {return j;}

	}
}

void recursion(int *arr, int left, int right) {
	if (right - left < 1) {return;}

	int index = task(arr, left, right);

	recursion(arr, left, index - 1);
	recursion(arr, index + 1, right);

}

void main() {
	int arr[] = {6, 4, 3, 9, 1, 4, 8, 7, 5, 6};
	int len = sizeof(arr) / sizeof(int);

	display(arr, len);
	recursion(arr, 0, len - 1);
	display(arr, len);
}