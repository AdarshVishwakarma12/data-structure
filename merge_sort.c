#include <stdio.h>

void display(int *arr, int len){
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void task(int *arr1, int mid, int low, int high){
	int i=low;
	int j=mid+1;
	int k=0;
	int arr3[40];

	while(i<=mid && j<=high){
		if(arr1[i] < arr1[j]){arr3[k] = arr1[i]; i++; k++;}
		else{arr3[k] = arr1[j]; j++; k++;}
	}

	while(i<=mid){arr3[k] = arr1[i]; i++; k++;}
	while(j<=high){arr3[k] = arr1[j]; j++; k++;}

	k=0;
	for(int i=low; i<=high; i++){arr1[i] = arr3[k++];}
}

void recursion(int *arr, int low, int high){
	if(high - low<1){return;}

	int mid = (high + low)/2;

	recursion(arr, low, mid);

	recursion(arr, mid+1, high);
	task(arr, mid, low, high);
}

void main(){
	int arr[] = {4, 2, 3, 9, 1, 4, 1, 8, 7, 5, 6, 0}; //{4, 2, 3, 9, 1, 4, 8, 7, 5, 6};// 
	int len = sizeof(arr) / sizeof(int);

	display(arr, len);
	recursion(arr, 0, len-1);
	display(arr, len);

	// int arr1[] = {4, 0};
	// display(arr1, 2);

	// task(arr1, (0+1)/2, 0, 1);

	// display(arr1, 2);

}