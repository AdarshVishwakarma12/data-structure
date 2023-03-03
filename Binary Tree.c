#include<stdio.h>
#include<stdlib.h>
#include"stack_arr.c"


struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* createNode(){
	struct node* ptr = malloc(sizeof(struct node));
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

// See notes* for visual representation for the following Binary tree
struct node* construct_random(struct node *B){
	struct node *p1 = createNode();
	struct node *p2 = createNode();
	struct node *p3 = createNode();
	struct node *p4 = createNode();
	struct node *p5 = createNode();
	struct node *p6 = createNode();
	struct node *p10 = createNode();

	B->left = p1;
	B->right = p2;

	p1->left = p3;
	p1->right = p4;

	p2->left = p5;
	p2->right = p6;

	p4->right = p10;

	B->data = 11;
	p1->data = 6;
	p2->data = 19;
	p3->data = 0;
	p4->data = 8;
	p5->data = 12;
	p6->data = 23;
	p10->data = 9;
	return B;
}

int validity(struct node *ROOT){
	
}

int search(struct node *ROOT){
}

void insert(struct node *ROOT){
}

void delete(struct node *ROOT){
}

void pre_order_ptr(){}
 
// these traversal based on recursion!
void pre_order_traversal(struct node* ROOT){
	if(ROOT==NULL){return;}
	printf("%d ", ROOT->data);
	pre_order_traversal(ROOT->left);
	pre_order_traversal(ROOT->right);
}

void post_order_traversal(struct node* ROOT){
	if(ROOT==NULL){return;}
	post_order_traversal(ROOT->left);
	pre_order_traversal(ROOT->right);
	printf("%d ", ROOT->data);
}

void in_order_traversal(struct node *ROOT){
	if(ROOT==NULL){return;}
	in_order_traversal(ROOT->left);
	printf("%d ", ROOT->data);
	in_order_traversal(ROOT->right);
}

int main(){
	struct node *B = createNode();
	B = construct_random(B);

	printf("Pre-Order Traversal : ");
	pre_order_traversal(B);

	printf("\nPost-order Traversal : ");
	post_order_traversal(B);

	printf("\nIn-order Traversal : ");
	in_order_traversal(B);
}