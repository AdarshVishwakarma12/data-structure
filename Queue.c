#include<stdio.h>
#include<stdlib.h>
#define max 10
struct node{
	int R;
	int F;
	int size;
	int* arr;
};

int isEmpty(struct node arr){
	if(arr.F==arr.R){return 1;}
	return 0;
}
int isFull(struct node arr){
	if(arr.R==arr.size-1){return 1;}
	return 0;
}

void enqueue(struct node* arr){
	if(isFull(*arr) == 1){printf("Queue is Full!\n");}
	else{
		arr->R = arr->R + 1;
		printf("Enter the element : ");
		scanf("%d", &arr->arr[arr->R]);
	}
}
void dequeue(struct node* arr){
	if(isEmpty(*arr) == 1){printf("Queue is Empty!\n");}
	else{
		arr->F = arr->F + 1;
	}
}

void display(struct node* arr){
	if(isEmpty(*arr) == 1){printf("Queue is Empty!\n");}
	else{
		for(int i = arr->F; i<arr->R; i++){
			printf("%d ", arr->arr[i+1]);
		}
		printf("\n");
	}
}

void main(){
	struct node Q;
	Q.R = -1;
	Q.F = -1;
	Q.size = 10;
	Q.arr = (int *) malloc(Q.size*sizeof(int));

	int i;
	while(1){
		printf("(1/2/3) (4) : ");
		scanf("%d", &i);
		if(i==1){enqueue(&Q);}
		else if(i==2){dequeue(&Q);}
		else if(i==3){display(&Q);}
		else if(i==4){exit(0);}
	}
}