#include<stdio.h>
#include<stdlib.h>

struct array
{
	int total_size;
	int used_size;
	int *ptr;
};

void create(struct array *a,int t,int u){
	a->total_size = t;
	a->used_size = u;
	a->ptr = (int *)malloc(t*sizeof(int));
}
void insert(struct array *a){
	int n;
	for (int i = 0; i < a->used_size; ++i)
	{
		printf("enter the number : ");
		scanf("%d", &n);
		a->ptr[i] = n;
	}
}
void show(struct array *a){
	printf("\nelemets are : ");
	for (int i = 0; i < a->used_size; ++i)
	{
		printf(" %d ", a->ptr[i]);
	}
}

void main()
{
	struct array marks;
	create(&marks, 100, 10);
	insert(&marks);
	show(&marks);
}