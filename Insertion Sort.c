#include <stdio.h>

void main(){
	int arr[] = {7, 2, 91, 77, 3, 0, 100};
	int len = sizeof(arr)/sizeof(int);

	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	for(int i=1; i<len; i++){
		int j;
		for(j=i-1; j>=0; j--){if(arr[i] > arr[j]){break;}}
		j++;
		int swap = arr[i];
		for(int k = i; k>j; k--){arr[k] = arr[k-1];}
		arr[j] = swap;
	}

	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
}