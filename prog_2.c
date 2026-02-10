#include <stdio.h>
#include <string.h>
#include<math.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push_char(char c) {
    stack[++top] = c;
}

char pop_char() {
    if (top == -1)
        return -1;
    return stack[top--];
}

char peek_char() {
    return stack[top];
}

int isEmptyChar() {
    return top == -1;
}


int stack_int[MAX];
int top_int = -1;

void push_int(int x) {
    stack_int[++top_int] = x;
}

int pop_int() {
    return stack_int[top_int--];
}


int BODMAS(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

   
        if (isdigit(ch)) {
            postfix[j++] = ch;
        }
      
        else if (ch == '(') {
            push_char(ch);
        }
        
        else if (ch == ')') {
            while (!isEmptyChar() && peek_char() != '(') {
                postfix[j++] = pop_char();
            }
            pop_char(); 
        }

        else {
            while (!isEmptyChar() && BODMAS(peek_char()) >= BODMAS(ch)) {
                postfix[j++] = pop_char();
            }
            push_char(ch);
        }
    }


    while (!isEmptyChar()) {
        postfix[j++] = pop_char();
    }

    postfix[j] = '\0';
}


int evaluatePostfix(char postfix[]) {
    int i, op1, op2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push_int(ch - '0'); 
        } else {
            op2 = pop_int();
            op1 = pop_int();

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = (int)pow(op1, op2); break;
            }
            push_int(result);
        }
    }
    return pop_int();
}


int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluated Result: %d\n", evaluatePostfix(postfix));

    return 0;
}