#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

struct node{
	struct node *left;
	int key;
	struct node *right;
	int height;
};

struct node *createNode(int key){
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr->left = NULL;
	ptr->key = key;
	ptr->right = NULL;
	ptr->height = 1;

	return ptr;
}

int getHeight(struct node *ptr1){
	if(ptr1 == NULL) return 0;
	return ptr1->height;
}

int max_(int a, int b){return a>b?a:b;}

struct node *lRotation(struct node *ptr){
	struct node* x= ptr->left;
	struct node* copyX = x->right;
	x->right = ptr;
	ptr->left = copyX;

	ptr->height = 1 + max_(getHeight(ptr->left), getHeight(ptr->right));
	x->height = 1 + max_(getHeight(x->left), getHeight(x->right));

	// printf("\t\t\t update- key%d height%d", ptr->key, ptr->height);
	// printf("\t\t\t update- key%d height%d", x->key, x->height);
	return x;
}
struct node *rRotation(struct node *ptr){
	struct node* y = ptr->right;
	struct node* copyY = y->left;
	y->left = ptr;
	ptr->right = copyY;

	ptr->height = 1 + max_(getHeight(ptr->left), getHeight(ptr->right));
	y->height = 1 + max_(getHeight(y->left), getHeight(y->right));

	// printf("\t\t\t update- key%d height%d", ptr->key, ptr->height);
	// printf("\t\t\t update- key%d height%d", y->key, y->height);
	return y;
}

struct node *insert(struct node *ptr, int key){
	if(ptr == NULL){
		return createNode(key);
	}

	else if(ptr->key > key){ptr->left = insert(ptr->left, key);}
	else if(ptr->key < key){ptr->right = insert(ptr->right, key);}
	else {printf("Yet invalid\n");}

	ptr->height = 1 + max_(getHeight(ptr->left), getHeight(ptr->right));
	// printf("\tnode : %d (updated-height) : %d", ptr->key, ptr->height);

	// check for balance factor
	int bf = getHeight(ptr->left) - getHeight(ptr->right);

	// printf("\t\tbalance factor : %d\n", bf);

	// if right skewed tree!
	if(bf < -1 && key>ptr->right->key){ptr = rRotation(ptr);}
	// RL
	else if(bf < -1 && key<ptr->right->key){
		ptr->right = lRotation(ptr->right); 
		ptr = rRotation(ptr);
	}
	// left skewed tree!
	else if(bf > +1 && key<ptr->left->key){ptr = lRotation(ptr);}
	//LR
	else if(bf > +1 && key>ptr->left->key){
		ptr->left = rRotation(ptr->left); 
		ptr = lRotation(ptr);
	}
	// okay
	else if(bf == -1 || bf == 0 || bf == 1){return ptr;}
	else{printf("yet invalid!"); return ptr;}

	return ptr;
}

struct node *insert(struct node* ptr, std::vector<int> &arr){
	void post_order_traversal(struct node*);
	void in_order_traversal(struct node*);
	printf("Elements : ");
	for(int i : arr){printf("%d; ", i);}
	for(int i : arr){ptr = insert(ptr, i);}
	return ptr;
}


int main(){
	void post_order_traversal(struct node*);
	void in_order_traversal(struct node*);

	struct node *root = NULL;

	// std::vector<int> arr = {50, 45, 80, 95, 26, 43, 105, 2};
	std::vector<int> arr = {64, 1, 14, 26, 13, 110, 98, 85};
	root = insert(root, arr);

	printf("\nPost order traversal : ");
	post_order_traversal(root);
	printf("\nIn order traversal : ");
	in_order_traversal(root);

	return 0;
}

void post_order_traversal(struct node *ROOT)
{if(ROOT==NULL){return;} post_order_traversal(ROOT->left); post_order_traversal(ROOT->right); printf("%d; ", ROOT->key);}
void in_order_traversal(struct node *ROOT)
{if (ROOT == NULL) {return;} in_order_traversal(ROOT->left); printf("%d; ", ROOT->key); in_order_traversal(ROOT->right);}