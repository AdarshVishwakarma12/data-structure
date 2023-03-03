#include <stdio.h>
#include<stdlib.h>

struct Queue{
	int F;
	int R;
	int size;
	int* arr;
};

int isEmpty(struct Queue Q){
	if(Q.R == Q.F){return 1;}
	return 0;
}
int isFull(struct Queue Q){
	if((Q.R+1)%Q.size == Q.F){return 1;}
	return 0;
}

void enqueue(struct Queue *Q){
	if(isFull(*Q)){printf("Queue is full!\n");}
	else{
		Q->R = (Q->R+1)%Q->size;// circular increment
		printf("Enter the value : ");
		scanf("%d", &Q->arr[Q->R]);
	}
}
void dequeue(struct Queue *Q){
	if(isEmpty(*Q)){printf("Queue is empty!\n");}
	else{
		Q->F = (Q->F+1)%Q->size;
	}
}

void display(struct Queue Q){
	if(isEmpty(Q)){printf("Queue is empty!");}
	else{
		int i = 0;
		int circular = Q.F;
		int j;
		if(Q.F>Q.R){j = (Q.size - Q.F - 1) + (Q.R+1);}
		else{j  = Q.R - Q.F;}

		while(i<j){
			printf("%d ", Q.arr[(circular+1)%Q.size]);
			circular = (circular+1)%Q.size;
			i = i + 1;
		}
	}
	printf("\n");
}

void main(){
	struct Queue Q;
	Q.F = 0;
	Q.R = 0;
	Q.size = 5;
	Q.arr = (int *) malloc(sizeof(int)*Q.size);

	int i;
	while(1){
		display(Q);
		printf("(1/2/3) (4) : ");
		scanf("%d", &i);

		if(i==1){enqueue(&Q);}
		else if(i==2){dequeue(&Q);}
		else if(i==3){display(Q);}
		else if(i==4){exit(0);}
	}
}