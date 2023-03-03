#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

int isEmpty(struct node* R){
	if(R == NULL){return 1;}
	return 0;
}

void display(struct node* F, struct node* R){
	if(F==NULL){printf("Queue is empty!");}
	else{
		struct node *tmp = F;
		while(tmp!=NULL){
			printf("%d ", tmp->data);
			tmp = tmp->link;
		}
	}
	printf("\n");
}

void enqueue(struct node **F, struct node **R){
	struct node* ptr = (struct node	*) malloc(sizeof(struct node));

	if(ptr == NULL){printf("memory allocatoion failed! Queue is full");}
	else{
		ptr->link = NULL;
		printf("Enter the value : ");
		scanf("%d", &ptr->data);
		if(*F == NULL){
			*F = ptr;
		}
		else{
			(*R)->link = ptr;
		}
		*R = ptr;
	}
}

void dequeue(struct node **F, struct node **R){
	if(*F==NULL){printf("Queue is empty!\n");}
	else{
		struct node* del = *F;
		*F = (*F)->link;
		if(*F==NULL){*R=NULL;}
		free(del);
	}	
}

void main(){
	struct node* F = NULL;
	struct node* R = NULL;
	int i;
	while(1){
		printf("(1/2/3) (4) : ");
		scanf("%d", &i);
		if(i==1){enqueue(&F, &R);}
		else if(i==2){dequeue(&F, &R);}
		else if(i==3){display(F, R);}
		else if(i==4){exit(0);}
	}
}
