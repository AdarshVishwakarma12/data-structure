#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;	
};

// See notes* for visual representation for the following Binary tree
struct node* construct_random(struct node *B){
	struct node *p1 = malloc(sizeof(struct node));
	struct node *p2 = malloc(sizeof(struct node));
	struct node *p3 = malloc(sizeof(struct node));
	struct node *p4 = malloc(sizeof(struct node));
	struct node *p5 = malloc(sizeof(struct node));
	struct node *p6 = malloc(sizeof(struct node));
	// struct node *p7 = malloc(sizeof(struct node));
	// struct node *p8 = malloc(sizeof(struct node));
	struct node *p10 = malloc(sizeof(struct node));

	B->left = p1;
	B->right = p2;

	p1->left = p3;
	p1->right = p4;

	p2->left = p5;
	p2->right = p6;

	p4->right = p10;

	p3->left = NULL;
	p3->right = NULL;
	p4->left = NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = NULL;
	p6->right = NULL;
	p10->left = NULL;
	p10->right = NULL;

	B->data = 5;
	p1->data = 6;
	p2->data = 11;
	p3->data = 10;
	p4->data = 0;
	p5->data = 9;
	p6->data = 6;
	p10->data = 1;
	return B;
}

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
	struct node *B;
	B = construct_random(B);

	printf("Pre-Order Traversal : ");
	pre_order_traversal(B);

	printf("\nPost-order Traversal : ");
	post_order_traversal(B);

	printf("\nIn-order Traversal : ");
	in_order_traversal(B);
}