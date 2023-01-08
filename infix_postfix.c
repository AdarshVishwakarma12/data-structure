// sad - the following program only handle the "+, -, *, and / " operators!!!
#include <stdio.h>
#include <string.h>

#define max 5
char arr1[max];
int TOP1 = -1;

char arr2[max];
int TOP2 = -1;

int precidence(char ptr){
	if(ptr == '+' || ptr == '-'){return 0;}
	else if(ptr == '*' || ptr == '/'){return 1;}
}

int isEmpty(int TOP){
	if(TOP==-1){return 1;}
	return 0;
}

void Push(char *arr, int* TOP, char ptr){
	*TOP = *TOP + 1;
	arr[*TOP] = ptr;
}
char Pop(char *arr, int* TOP){
	char opr = arr[*TOP];
	*TOP = *TOP - 1;
	return opr;
}

void display(char* arr, int* TOP){
	int i = 0;
	while(i<=*TOP){
		printf("%c", arr[i]);
		i++;
	}
	if(*TOP==-1){printf("list isEmpty\n");}
}

void traverse(char* ptr){
	int i = 0;
	while(ptr[i]!='\0'){

		if(ptr[i] == '+' || ptr[i] == '-' || ptr[i] == '*' || ptr[i] == '/'){

			if(isEmpty(TOP1) == 1){Push(arr1, &TOP1, ptr[i]);}
			else{
				while(TOP1 != -1){
					if(precidence(ptr[i]) <= precidence(arr1[TOP1])){

						char ptr1 = Pop(arr1, &TOP1);
						Push(arr2, &TOP2, ptr1);

						if(TOP1==-1){Push(arr1, &TOP1, ptr[i]); break;}
					}
					else{
						Push(arr1, &TOP1, ptr[i]); 
						break;
					}
				}
			}
		}
		else{
			Push(arr2, &TOP2, ptr[i]);
		}
		i++;
	}

	while(TOP1!=-1){
		char ptr1 = Pop(arr1, &TOP1);
		Push(arr2, &TOP2, ptr1);
	}
}

void main(){
	//char* infix = "a-b*d+c";
	char infix[100];
	gets(infix);

	printf("Infix : %s\n", infix);

	traverse(infix);
	printf("Postfix : ");
	display(arr2, &TOP2);
}
