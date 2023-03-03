#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};
struct node* START = NULL;

void display() {
	if (START == NULL) {
		printf("List is empty!");
	}
	else {
		struct node* tmp = START;
		do
		{
			printf("%d ", tmp->data);
			tmp = tmp->link;
		} while (tmp != START);
	}
}
int size() {
	int i = 0;
	if (START == NULL) {return 0;}
	else {
		struct node* tmp = START;
		do
		{
			i++;
			tmp = tmp->link;
		} while (tmp != START);
	}
	return i;
}

void insert_beg() {
	struct node* ptr = malloc(sizeof(struct node));
	if (START != NULL) {
		ptr->link = START;
		struct node* tmp = START;
		while (tmp->link != START) {
			tmp = tmp->link;
		}
		tmp->link = ptr;
	}
	else {ptr->link = ptr;}
	START = ptr;
	printf("Enter the element : ");
	scanf("%d", &ptr->data);
}

void insert_lst() {
	if (START == NULL) {insert_beg();}
	else {
		struct node* tmp = START;
		while (tmp->link != START) {
			tmp = tmp->link;
		}
		struct node* ptr = malloc(sizeof(struct node));
		ptr->link = tmp->link;//START
		tmp->link = ptr;

		printf("Enter the element : ");
		scanf("%d", &ptr->data);
	}
}
void insert_spec() {
	int loc;
	printf("Enter the location : ");
	scanf("%d", &loc);
	if (loc < 0 || loc > size()) {
		printf("Invalid Location entered!");
	}
	else if (loc == 0) {insert_beg();}
	else if (loc == size()) {insert_lst();}
	else {
		int i = 0;
		struct node* tmp = START;
		while (i != loc - 1) {
			i++;
			tmp = tmp->link;
		}
		struct node* ptr = malloc(sizeof(struct node));
		ptr->link = tmp->link;
		tmp->link = ptr;
		printf("Enter the element : ");
		scanf("%d", &ptr->data);
	}
}

void delete_beg() {
	if (START == NULL) {
		printf("List is empty!");
	}
	else {
		struct node* del = START;
		//only one element
		if (START->link == START) {START = NULL;}
		else {
			struct node* tmp = START;
			while (tmp->link != START) {
				tmp = tmp->link;
			}
			tmp->link = del->link;
			START = del->link;
		}
		free(del);
	}
}
void delete_lst() {
	if (START == NULL) {
		printf("List is empty!");
	}
	else if (START->link == START) {delete_beg();}
	else {
		struct node* tmp = START;
		while (tmp->link->link != START) {
			tmp = tmp->link;
		}
		struct node* del = tmp->link;
		tmp->link = START;
		free(del);
	}
}
void delete_spec() {
	if (START == NULL) {
		printf("List is empty!");
	}
	else {
		int loc;
		printf("Enter the location : ");
		scanf("%d", &loc);
		if (loc < 0 || loc >= size()) {printf("Invalid Location entered!");}
		else if (loc == 0) {delete_beg();}
		else if (loc == size() - 1) {delete_lst();}
		else {
			int i = 0;
			struct node* tmp = START;
			while (i != loc - 1) {
				i++;
				tmp = tmp->link;
			}
			struct node* del = tmp->link;
			tmp->link = tmp->link->link;
			free(del);
		}
	}
}

void main() {
	int i;
	while (1) {
		printf("\n(1/2/3) (4/5/6) (7/8) : ");
		scanf("%d", &i);
		if (i == 1) {insert_beg();}
		else if (i == 2) {insert_lst();}
		else if (i == 3) {insert_spec();}
		else if (i == 4) {delete_beg();}
		else if (i == 5) {delete_lst();}
		else if (i == 6) {delete_spec();}
		else if (i == 7) {display();}
		else if (i == 8) {exit(0);}
	}
	printf("Thanks for visting");
}