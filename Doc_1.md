# Checking if the parenthesis is balanced or Not.
This program checks whether a given expression has balanced parentheses using a stack. 
**DO NOTE THAT : Any other brackets haven't been included as question said only to balance parenthesises.**
## How it works
When an opening bracket ( is encountered, it is pushed onto the stack.

When a closing bracket ) is encountered:

The program pops the top element from the stack.

It checks whether the popped opening bracket matches the closing bracket.

If a closing bracket appears when the stack is empty, or if brackets do not match, the expression is not balanced.

After scanning the entire expression, if the stack is empty, the expression is balanced; otherwise, it is not balanced.

**MAJOR FUNCTIONS:**
```c
push(char c);
pop();
isOpen(char c);
isClosed(char c);
isMatch(char open, char close);
checkBalancedorNo(const char *expr);
```
## Features

Uses a character stack implemented with an array

Only Supports ()

Displays push and pop operations for better understanding


## Output

 BALANCED → all Parenthesis are properly matched

 NOT BALANCED → missing or mismatched parenthesis

