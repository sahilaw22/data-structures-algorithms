#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char c){
    if(top==SIZE-1){
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top]=c;
}

void pop(){
    if(top==-1){
        printf("Stack Underflow\nExpression is invalid");
        exit(1);
    }
    top--;
}

int main(){
    char exp[SIZE];
    int i;
    printf("Enter any expression: ");
    scanf("%s",exp);
    for (i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            pop();
        }
    }
    if (top == -1){
        printf("Expression is valid");
    }
    else{
        printf("Expression is invalid");
    }
    return 0;
    
}