// Postfix evaluation in C

#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 100
#define POSTFIXSIZE 100

int stack[MAXSTACK];
int top = -1;

void push(int item)
{
    if(top >= MAXSTACK - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = item;
}

int pop()
{
    if(top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

void EvalPostfix(char postfix[])
{
    int i;
    char ch;
    int A,B,val;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            A = pop();
            B = pop();

            switch(ch)
            {
                case '+':
                    val = B + A;
                    break;

                case '-':
                    val = B - A;
                    break;

                case '*':
                    val = B * A;
                    break;

                case '/':
                    val = B / A;
                    break;
            }

            push(val);
        }
    }

    printf("Result = %d\n", pop());
}

int main()
{
    char postfix[POSTFIXSIZE];

    printf("Enter postfix expression: "); // Example input: "23*54*+9-"
    scanf("%s", postfix);

    EvalPostfix(postfix); // Output for the example input: "Result = 17"

    return 0;
}