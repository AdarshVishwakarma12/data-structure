#include <stdio.h>
#include <stdlib.h>

struct  node{
	int data;
	struct node* link;
	int max;			//storing the maximum size to be used
	int size;			//tracking the size of link list
	struct node* TOP;	//only point to the first node
};

int isEmpty(struct node* ptr){
	if(ptr->TOP == NULL){
		return 1;
	}
	return 0;
}

int isFull(struct node* ptr){
	if(ptr->size == ptr->max){
		return 1;
	}
	return 0;
}

struct node* Push(struct node* ptr){
	//if stack is full
	if(isFull(ptr) == 1){
		printf("stack is full\n");
	}
	//if stack is empty
	else if(ptr->TOP == NULL){
		struct node *tmp = (struct node *) malloc(sizeof(struct node));
		ptr->TOP = tmp;
		tmp->link = NULL;

		int element;
		printf("element the element : ");
		scanf("%d", &element);
		tmp->data = element;

		ptr->size = ptr->size+1;

	}
	//1 or more than 1 element
	else{
		struct node* tmp = (struct node *) malloc(sizeof(struct node));
		tmp->link = ptr->TOP;
		ptr->TOP = tmp;

		int element;
		printf("enter the element : ");
		scanf("%d", &element);
		tmp->data = element;

		ptr->size = ptr->size+1;
	}
	return ptr;
}

struct node* Pop(struct node *ptr){
	if(isEmpty(ptr) == 1){
		printf("stack is empty\n");
	}
	else{
		struct node* tmp;
		tmp = ptr->TOP;
		ptr->TOP = tmp->link;

		free(tmp);
	}
	return ptr;
}

void display(struct node* ptr){
	struct node* tmp = ptr->TOP;
	if(tmp==NULL){printf("stack is empty\n");}
	else{
		while(tmp!=NULL){
			printf("%d  ", tmp->data);
			tmp = tmp->link;
		}
		printf("\n");
	}
}

void main(){
	struct node *ptr;
	ptr->max = 10;
	ptr->TOP = NULL;
	ptr->size = 0;

	int i;
	while(1){
		printf("enter your choice (1/2 // 3 // 4) : ");
		scanf("%d", &i);

		if(i==1){ptr = Push(ptr);}
		else if(i==2){ptr = Pop(ptr);}
		else if(i==3){display(ptr);}
		else if(i==4){exit(0);}
	}
	printf("%d\n", isEmpty(ptr));
}