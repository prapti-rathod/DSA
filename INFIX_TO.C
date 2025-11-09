#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void main() {
    char infix[SIZE], postfix[SIZE];
    char stack[SIZE];
    int top = -1;
    int i = 0, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0')
    {
	if (isalnum(ch))
	{
	    postfix[j++] = ch;
	}
	else if (ch == '(')
	{
	    top++;
	    stack[top] = ch;
	}
	else if (ch == ')')
	{
	    while (top != -1 && stack[top] != '(')
	    {
		postfix[j++] = stack[top];
		top--;
	    }
	    if (top != -1 && stack[top] == '(')
	    {
		top--;
	    }
	}

	else
	{
	    int p1;
	    if (ch == '^')
		p1 = 3;
	    else if (ch == '*' || ch == '/')
		p1 = 2;
	    else
		p1 = 1;

	    while (top != -1)
	    {
		char topOp = stack[top];
		int p2;
		if (topOp == '^')
		    p2 = 3;
		else if (topOp == '*' || topOp == '/')
		    p2 = 2;
		else if (topOp == '+' || topOp == '-')
		    p2 = 1;
		else
		    break;

		if (p2 >= p1)
		{
		    postfix[j++] = topOp;
		    top--;
		}
		else
		{
		    break;
		}
	    }
	    stack[++top] = ch;
	}
    }

    while (top != -1)
    {
	postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    getch();
}
