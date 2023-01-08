#include <stdio.h>

void main(){
	int arr[] = {1, 2, 3, 1, 0, 89, 0, 9, 56, -1};// 
	int len = sizeof(arr)/sizeof(int);

	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}

	for(int i=1; i<len; i++){

		int min = arr[i-1];
		int index=i-1;
		
		for(int j=i; j<len; j++){
			if(min>arr[j]){min=arr[j]; index = j;}
		}

		int swap = arr[i-1];
		arr[i-1] = arr[index];
		arr[index] = swap;
	}

	printf("\n");
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
}