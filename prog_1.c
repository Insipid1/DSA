#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top--];
}

int isEmpty() { return top == -1; }

int isOpen(char c) { return c == '('; }
int isClose(char c) { return c == ')'; }

int isMatch(char open, char close)
{
    return (open == '(' && close == ')');
}

int checkBalancedorNot(const char *expr)
{
    top = -1; /* reset stack */
    int len = strlen(expr);

    for (int i = 0; i < len; i++)
    {
        char c = expr[i];

        if (isOpen(c))
        {
            push(c);
            printf("  Push '%c'  → Stack: [", c); // shows what part of exp is being pushed
            for (int k = 0; k <= top; k++)
                printf("%c", stack[k]);
            printf("]\n");
        }
        else if (isClose(c))
        {
            if (isEmpty())
            {
                printf("  NOT BALANCED!\n");
                return 0;
            }
            char openChar = pop();
            if (!isMatch(openChar, c))
            {
                printf(" NOT BALANCED'!\n");
                return 0;
            }
            printf("  Pop  '%c' matched '%c' → Stack: [", openChar, c);// Pops if open bracket finds a closing bracket, also shows what currently is at Stacck
            for (int k = 0; k <= top; k++)
                printf("%c", stack[k]);
            printf("]\n");
        }
    }

    if (!isEmpty())
    {
        printf("  ERROR: Unmatched open brackets remain: [");
        while (!isEmpty())
            printf("%c", pop());
        printf("]\n");
        return 0;
    }
    return 1;
}

void test(const char *expr)
{
    printf("\nExpression: %s\n", expr);
    if (checkBalancedorNot(expr))
        printf("Result:   BALANCED\n");
    else
        printf("Result:   NOT BALANCED\n");
}

int main()
{
    test("a + (b - c) * (d + e)");
    test("m + [a - b * (c + d * {m)]");
    test("a + (b - c)");
    return 0;
}