#include<stdio.h>
#include<stdlib.h>

struct Tree{int data; struct Tree* left; struct Tree* right;};

// STACK
#define max 32
struct Tree* arr[32];
int TOP = -1;
int isEmpty(){if(TOP==-1){return 1;}else{return 0;}}
int isFull(){if(TOP==max-1){return 1;}else{return 0;}}
int push(struct Tree* element){if(isFull()==1){return 0;}else{TOP = TOP + 1; arr[TOP] = element; return 1;}}
struct Tree* pop(){if(isEmpty()==1){return NULL;}else{TOP = TOP - 1; return arr[TOP+1];}}
void display(){for(int i=0; i<=TOP; i++){printf("%d ", arr[i]->data);} printf("\n");}
void reset_stack(){TOP = -1;}// for re-use

// BST
//    19
//   /  \
//  13  23
//  /\  / \
// 9 17 21 25
//   /\
//  15 18
struct Tree* createNodeTree()
{struct Tree*ptr = malloc(sizeof(struct Tree)); ptr->left=NULL; ptr->right=NULL; return ptr;}
struct Tree* createOne(struct Tree *B){
	struct Tree *p1, *p2, *p3, *p4, *p5, *p6, *p8, *p10;
	p1 = createNodeTree(); p2=createNodeTree(); p3=createNodeTree(); p4=createNodeTree(); p5 = createNodeTree(); p6=createNodeTree(); p8=createNodeTree(); p10=createNodeTree();
	B->data = 19; B->left = p1; B->right = p2; p1->left = p3; p1->right=p4; p2->left=p5; p2->right=p6; p4->left = p8; p4->right = p10; 
	p1->data = 13; p2->data = 23; p3->data = 9; p4->data = 17; p5->data = 21; p6->data = 25; p8->data = 15;p10->data = 18;
	return B;
}

//in-order Traversal
void in_order_traversal(struct Tree *ROOT)
{if(ROOT==NULL){return;} in_order_traversal(ROOT->left); printf("%d ", ROOT->data); in_order_traversal(ROOT->right);}

void in_order_traversal_pointer(struct Tree *ptr){
	if(ptr==NULL){return;}
	reset_stack();
	while(1){//temporary solution
		while(ptr!=NULL){push(ptr); ptr = ptr->left;}
		while(isEmpty()!=1){
			ptr = pop(); printf("%d ", ptr->data);
			if(ptr->right!=NULL){ptr = ptr->right; break;}
			ptr = NULL;
		}
		if(ptr==NULL && isEmpty()==1){break;}
	}
}

//Pre-order traversal
void pre_order_traversal(struct Tree* ROOT)
{if(ROOT==NULL){return;} printf("%d ", ROOT->data); pre_order_traversal(ROOT->left); pre_order_traversal(ROOT->right);}

void pre_order_traversal_pointer(struct Tree *ptr){
	if(ptr==NULL){return;}
	reset_stack();
	while(1){
		printf("%d ", ptr->data);
		if(ptr->right!=NULL){push(ptr->right);}
		if(ptr->left!=NULL){push(ptr->left);}
		ptr = pop(); 
		if(ptr==NULL){return;} //pop return NULL if isEmpty() is True
	}
}

//Post-order Traversal
void post_order_traversal(struct Tree* ROOT)
{if(ROOT==NULL){return;} post_order_traversal(ROOT->left); pre_order_traversal(ROOT->right); printf("%d ", ROOT->data);}

void post_order_traversal_pointer(struct Tree* ptr){
	if(ptr==NULL){return;}
	reset_stack();
	int in_ = 0;
	while(in_<11){
		in_++;
		push(ptr);
		if(ptr->right!=NULL){push(ptr->right);}
		if(ptr->left!=NULL){push(ptr->left);}
		
	}
}


// main
void main(){
	struct Tree *B = createNodeTree(); B = createOne(B);
	// traverse using recursion
	in_order_traversal(B);
	printf("\n");
	// traverse using pointer and stack
	in_order_traversal_pointer(B);
	printf("\n");
	pre_order_traversal(B);
	printf("\n");
	pre_order_traversal_pointer(B);

	printf("\n");
	post_order_traversal(B);
	printf("\n\n");
	post_order_traversal_pointer(B);

	printf("\nreturncode : %d", 0);
}