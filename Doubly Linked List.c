#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* PA;
	struct node* NA;
};
struct node* START = NULL;

void display() {
	if (START == NULL) {
		printf("List is empty");
	}
	else {
		struct node* tmp = START;
		while (tmp != NULL) {
			printf("%d ", tmp->data);
			tmp = tmp->NA;
		}
	}
}

int size() {
	int i = 0;
	struct node* tmp = START;
	while (tmp != NULL) {
		tmp = tmp->NA;
		i++;
	}
	return i;
}

void insert_beg() {
	struct node* ptr = malloc(sizeof(struct node));
	ptr->PA = NULL;
	ptr->NA = START;
	if (START != NULL) {START->PA = ptr;}
	printf("Enter the element : ");
	scanf("%d", &ptr->data);
}
void insert_lst() {
	if (START == NULL) {insert_beg();}
	else {
		struct node* tmp = START;
		while (tmp->NA != NULL) {
			tmp = tmp->NA;
		}
		struct node* ptr = malloc(sizeof(struct node));
		ptr->PA = tmp;
		ptr->NA = NULL;
		tmp->NA = ptr;

		printf("Enter the element : ");
		scanf("%d", &ptr->data);
	}
}
void insert_spec() {
	int loc;
	printf("Enter the location : ");
	scanf("%d", &loc);
	if (loc < 0 || loc > size()) {printf("Invalid location!");}
	else if (loc == 0) {insert_beg();}
	else {
		struct node* tmp = START;
		int i = 0;
		while (i != loc - 1) {
			i++;
			tmp->NA = tmp;
		}
		struct node* ptr = malloc(sizeof(struct node));
		ptr->PA = tmp;
		ptr->NA = tmp->NA;
		if (tmp->NA != NULL) {tmp->NA->PA = ptr;}
		tmp->NA = ptr;

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
		START = START->NA;
		if (START != NULL) {START->PA = NULL;}
		free(del);
	}
}
void delete_lst() {
	if (START == NULL) {
		printf("List is empty!");
	}
	else if (START->NA == NULL) {delete_beg();}
	else {
		struct node* tmp = START;
		while (tmp->NA != NULL) {
			tmp = tmp->NA;
		}
		struct node* del = tmp;
		tmp = tmp->PA;
		tmp->NA = NULL;
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
		if (loc < 0 || loc >= size()) {
			printf("Invalid location!");
		}
		else if (loc == 0) {delete_beg();}
		else {
			struct node* tmp = START;
			int i = 0;
			while (i != loc - 1) {
				i++;
				tmp = tmp->NA;
			}
			struct node* del = tmp->NA;
			if (del->NA != NULL) {del->NA->PA = tmp;}
			tmp->NA = del->NA;
			free(del);
		}
	}
}

void main() {
	int i;
	while (1) {
		printf("(1/2/3) (4/5/6) (7/8) : ");
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
}