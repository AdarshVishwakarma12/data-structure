#include<iostream>

int main(){
	int N;

	std::cin >> N;
	int arr[N];

	int checked[N];
	int keys[N];
	int values[N];
	
	// input the array;
	for(int i=0; i<N; i++){
		std::cin >> arr[i];
		checked[i] = 0;

	}

	int counter = 0;
	int counter_in_continuity=0;
	int k = 0;

	while(counter<N){
		if(checked[counter]==1){counter++; continue;}

		keys[counter_in_continuity] = arr[counter];
		values[counter_in_continuity] = 1;
		checked[counter] = 1;

		k = 0;
		while(k<N){
			if(checked[k]==1){k++; continue;}
			if(arr[k] == keys[counter_in_continuity]){checked[k] = 1; values[counter_in_continuity]++;}
			k++;
		}

		counter++;
		counter_in_continuity++;

	}

	for(int l=0; l<counter_in_continuity; l++){
		std::cout << keys[l] << " : " << values[l] << ", ";
	}
	return 0;
}