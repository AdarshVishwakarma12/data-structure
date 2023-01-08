#include <stdio.h>

void fun(int* arr, int* top){
	arr[0] = 8;
	*top = *top  + 19;
	printf("%d\n", arr[0]);
	printf("%d\n", *top);
}

void main(){
	int arr[10] = {10};
	printf("%d\n", arr[0]);

	int top = -1;
	fun(arr, &top);
	printf("%d\n", arr[0]);
	printf("%d\n", top);
}