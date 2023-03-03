#include <stdio.h>
#include <stdlib.h>

struct stack{
	int size;
	int TOP;
	int *arr;
};

int isEmpty(struct stack* ptr){
	if(ptr->TOP==-1){return 1;}
	return 0;
}
int isFull(struct stack* ptr){
	if(ptr->TOP == ptr->size-1){return 1;}
	return 0;
}

void display(struct stack* ptr){
	if(isEmpty(ptr) == 1){
		printf("stack is empty");
	}
	else{
		for (int i = 0; i <= ptr->TOP; i++){
			printf("%d ", ptr->arr[i]);
		}
	}
	printf("\n");
}

struct stack* Push(struct stack* ptr){
	if(isFull(ptr) == 1){printf("stack is full\n");}
	else{
		int element;
		printf("enter the element");
		scanf("%d", &element);
		ptr->TOP = ptr->TOP+1;
		ptr->arr[ptr->TOP] = element;
	}
	return ptr;
}

struct stack* Pop(struct stack* ptr){
	if(isEmpty(ptr) == 1){printf("stack is empty\n");}
	else{ptr->TOP = ptr->TOP-1;}
	return ptr;
}

void main(){
	struct stack* ptr;
	ptr->size = 3;
	ptr->TOP = -1;
	ptr->arr = (int *) malloc(sizeof(int) * ptr->size);

	int i;
	while(1){
		printf("enter your choice (1/2/3/4/5/6) : ");
		scanf("%d", &i);

		if     (i == 1){ptr = Push(ptr);}
		else if(i == 2){ptr = Pop(ptr);}
		else if(i == 3){display(ptr);}
		else if(i == 4){}
		else if(i == 5){}
		else if(i == 6){exit(0);}
	}
}