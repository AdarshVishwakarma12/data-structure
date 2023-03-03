#include <stdio.h>
#define max 30
char arr[max];
int TOP = -1;

int isEmpty(){
	if(TOP==-1){return 1;}
	return 0;
}

void Push(char ptr){
	if(TOP==max-1){;}
	else{
		arr[TOP] = ptr;
		TOP = TOP + 1;
	}
}

int Pop(char ptr){
	if(TOP==-1){return 0;}
	else{
		TOP=TOP-1;
		return 1;
	}
}

int traverse(char* ex){
	int i = 0;
	while(ex[i]!='\0'){
		if(ex[i]=='('){Push(ex[i]);}
		else if(ex[i]==')'){
			char chk = Pop(ex[i]);
			if (chk == 0){printf("unbalenced!"); return 0;}
		}
		i++;
	}
	if(isEmpty()==1){printf("balenced!"); return 1;}
	else{printf("unbalenced"); return 0;}
}

void main(){
	char* ex = "((p-q)-(r/a))";
	printf("%s", ex);
	traverse(ex);
}