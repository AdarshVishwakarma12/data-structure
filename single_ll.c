#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node *START = NULL;

void reverse(struct node **Start){//start address have to be given to make changes!
	if(*Start == NULL){return;}
	else{
		struct node* tmp = *Start;
		struct node* tmp_1 = (*Start)->link;
		tmp->link = NULL;
		while(tmp_1!=NULL)
		{
			tmp = tmp_1;
			tmp_1 = tmp_1->link;
			tmp->link = *Start;
			*Start = tmp;
		}
	}
}

void display(){
	if(START == NULL)
		printf("lst is empty\n");
	else{
		struct node* tmp = START;
		while(tmp != NULL){
			printf("%d ", tmp->data);
			tmp = tmp->link;
		}
		printf("\n");
	}
}
int size(){
	int i=0;
	struct node* tmp = START;
	while(tmp!=NULL){
		i++;
		tmp=tmp->link;
	}
	return i;
}

void insert_beg(){
	struct node* ptr = malloc(sizeof(struct node));
	
	printf("enter the element : ");
	scanf("%d", &ptr->data);

	ptr->link = START;
	START = ptr;
}
void insert_lst(){
	struct node* tmp = START;
	if(START == NULL){insert_beg();}
	while(tmp->link!=NULL){
		tmp = tmp->link;
	}
	struct node* ptr = malloc(sizeof(struct node));
	ptr->link = tmp->link;
	tmp->link = ptr;

	printf("enter the element : ");
	scanf("%d", &ptr->data);
}
void insert_spec(){
	int loc;
	printf("enter the location : ");
	scanf("%d", &loc);
	if(loc<0 || loc>size()){
		printf("invalid location entered!");
	}
	else if(loc == 0){insert_beg();}
	else if(loc == size()){insert_lst();}
	else{
		int i=0;
		struct node* tmp = START;
		while(i != loc-1){
			i++;
			tmp = tmp->link;
		}
		struct node* ptr = malloc(sizeof(struct node));
		ptr->link = tmp->link;
		tmp->link = ptr;
		printf("enter the element : ");
		scanf("%d", &ptr->data);
	}
}

void delete_beg(){
	if(START==NULL){
		printf("lst is empty!");
	}
	else{
		struct node* del = START;
		START = START->link;
		free(del);
	}

}
void delete_lst(){
	if(START==NULL){
		printf("lst is empty!");
	}
	else if(START->link == NULL){delete_beg();}
	else{
		struct node* tmp = START;
		while(tmp->link->link != NULL){
			tmp = tmp->link;
		}
		struct node* del;
		del = tmp->link;
		tmp->link = tmp->link->link;//NULL
		free(del);
	}
}
void delete_spec(){
	if(START==NULL){
		printf("lst is empty!");
	}
	else
	{
		int loc;
		printf("enter the location");
		scanf("%d", &loc);
		if(loc<0 || loc>size()){
			printf("invalid location entered!");
		}
		else if(loc == 0){delete_beg();}
		else if(loc == size()){delete_lst();}
		else{
			int i=0;
			struct node* tmp = START;
			while(i != loc-1){
				i++;
				tmp = tmp->link;
			}
			struct node* del = tmp->link;
			tmp->link = tmp->link->link;
			free(del);
		}
	}
}

void main(){
	int i;
	while(1){
		printf("Enter your choice (1/2/3) (4/5/6) (7/8) (10): ");
		scanf("%d", &i);
		if(i==1){insert_beg();}
		else if(i==2){insert_lst();}
		else if(i==3){insert_spec();}
		else if(i==4){delete_beg();}
		else if(i==5){delete_lst();}
		else if(i==6){delete_spec();}
		else if(i==7){display();}
		else if(i==8){printf("size : %d", size());}
		else if(i==9){exit(0);}
		else if(i==10){reverse(&START);}
	}
	printf("thanks for visiting");
}