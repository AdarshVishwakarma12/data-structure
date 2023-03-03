#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

struct node {
	struct node *left;
	struct node *right;
	int data;
};
struct node *START = NULL;

struct node* create_node(int data) {
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->data = data;
	return ptr;
}

struct node* insert(struct node* ptr, int data) {
	// find the way and insert the data;
	if(ptr==NULL){ptr = create_node(data); return ptr;}
	else if(data > ptr->data || data == ptr->data){
		if(ptr->right == NULL){ptr->right = create_node(data); return ptr;}
		else{insert(ptr->right, data);}
	}
	else if(data < ptr->data){
		if(ptr->left == NULL){ptr->left = create_node(data); return ptr;}
		else{insert(ptr->left, data);}
	}
	return ptr;
}
void insert(struct node* ptr, std::vector<int> arr) {
	for(int i : arr){insert(ptr, i);}
}



void in_order_traversal(struct node *ROOT)
{if (ROOT == NULL) {return;} in_order_traversal(ROOT->left); printf("%d ", ROOT->data); in_order_traversal(ROOT->right);}


int main() {
	// struct node *START = create_node(15);

	START = insert(START, 16);
	insert(START, 20);
	insert(START, 23);
	insert(START, 15);
	insert(START, 0);
	insert(START, 29);
	std::vector <int> arr(3, 0);
	arr	 = {1, 2, 3, 56, 12};
	insert(START, arr);

	std::cout << "Traversal : " << std::endl;
	in_order_traversal(START);
	return 0;
}