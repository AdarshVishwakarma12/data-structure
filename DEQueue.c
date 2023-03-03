#include<stdio.h>
#include<stdlib.h>

void InsertR(int* arr, int* max, int* R) {
	if (*R == *max - 1) {printf("Queue is Full at this end\n");}
	else {
		*R = *R + 1;
		printf("Enter the element : ");
		scanf("%d", &arr[*R]);
	}
}
void InsertF(int* arr, int* F) {
	if (*F == -1) {printf("Queue is Full at this end\n");}
	else {
		printf("Enter the element : ");
		scanf("%d", &arr[*F]);
		*F = *F - 1;
	}
}

void DeleteR(int* arr, int* F, int* R) {
	if (*R == *F) {printf("Queue is Empty");}
	else {
		*R = *R - 1;
	}
}
void DeleteF(int* arr, int* F, int* R) {
	if (*F == *R) {printf("Queue is Empty\n");}
	else {
		*F = *F + 1;
	}
}

void display(int* arr, int F, int R) {
	if (R == F) {printf("Queue is Empty\n");}
	else {
		for (int i = F + 1; i <= R; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

void main() {
	int arr[5];
	int max = 5;
	int F = -1;
	int R = -1;

	int i;
	while (1) {
		printf("(1/2/3/4/5) (6) : ");
		scanf("%d", &i);

		if (i == 1) {InsertF(arr, &F);}
		else if (i == 2) {InsertR(arr, &max, &R);}
		else if (i == 3) {DeleteF(arr, &F, &R);}
		else if (i == 4) {DeleteR(arr, &F, &R);}
		else if (i == 5) {display(arr, F, R);}
		else if (i == 6) {exit(0);}
	}
}