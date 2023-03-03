#include<stdio.h>
#define max 100
char arr[max];
int Top = -1;

void Push(char ptr){
	Top = Top + 1;
	arr[Top] = ptr;
}

int isEmpty(){
	if(Top==-1){return 1;}
	else{return 0;}
}

int Pop(){
	if(isEmpty() == 1){return 0;}//underflow
	else{
		Top = Top - 1;
		return 1;
	}
}

int Match(char var){
	if (var == ')' && arr[Top] == '('){return 1;}
	else if (var == '}' && arr[Top] == '{'){return 1;}
	else if (var == ']' && arr[Top] == '['){return 1;}
	else{return 0;}
}

int traverse(char* ptr){
	int i = 0;
	while(ptr[i]!='\0'){
		if(ptr[i] == '(' || ptr[i] == '{' || ptr[i] == '['){
			Push(ptr[i]);
		}
		else if(ptr[i] == ')' || ptr[i] == '}' || ptr[i] == ']'){
			if(isEmpty()==1){return 0;}
			else if(Match(ptr[i]) == 1){Pop();}
			else{return 0;}
		}

		i = i + 1;
	}
	if(isEmpty()==1){return 1;}
	else{return 0;}
}

void main(){
	char* ptr = "(10-(10-9{}10*9+[s{0}]))";
	printf("%s\n", ptr);
	if(traverse(ptr) == 1){printf("balanced  eq!\n");}
	else{printf("Unbalance eq!\n");}

}