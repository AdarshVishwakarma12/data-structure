#include<stdio.h>
#define MAX 5
int arr[MAX];
int pointer = -1;

//insert at last
void insert_(){
	if(pointer == MAX-1){
		printf("overflow condition");
	}
	else{
		int n;
		printf("enter the specified location : ");
		scanf("%d", &n);
		if(n<0 || n>pointer+1){
			printf("invalid location");
		}
		//inserting the element with maintaing order of array
		else{
			int a = pointer+1;//size of array
			while(a>n){
				arr[a] = arr[a-1];
				a--;
			}

			pointer = pointer + 1;
			int element;
			printf("enter the element : ");
			scanf("%d", &element);
			arr[n] = element;
		}
	}
}

//delete at specified location
void delete_(){
	if(pointer==-1){
		printf("underflow condition!");
	}
	else{
		int n;
		printf("enter the specified location for deletion : ");
		scanf("%d", &n);
		if(n<0 || n>pointer){
			printf("invalid index");
		}
		else{
			int element;
			element = arr[n];
			while(n<pointer){
				arr[n] = arr[n+1];
				n++;
			}
			printf("element %d is deleted", element);
			pointer = pointer - 1;
		}
	}
}

//display
void display_(){
	int i;
	for(i=0; i<=pointer; i++){
		printf("%d ", arr[i]);
	}
}

//main
int main(){
	int choice;
	do{
		printf("\nenter you choice : ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert_(); break;
			case 2: delete_(); break;
			case 3: display_(); break;
			case 4: break;
		}

	}while(choice<4);
	printf("done with exit code 0");
	return 0;
}
