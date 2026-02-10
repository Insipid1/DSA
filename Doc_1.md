# Balanced Parentheses Checker (Using Stack)

## (a) Data Structure Definition

This program uses a **stack** data structure implemented using an array to store opening brackets.

- `char stack[MAX]`  
  Stores opening brackets `(`

- `int top`  
  Tracks the index of the top element in the stack.  
  A value of `-1` indicates that the stack is empty.

The stack follows the **Last In, First Out (LIFO)** principle, which is suitable for checking balanced parentheses.

---

## (b) Function Descriptions

- **`push(char c)`**  
  Pushes an opening bracket onto the stack.

- **`pop()`**  
  Removes and returns the top element from the stack.

- **`isEmpty()`**  
  Checks whether the stack is empty.

- **`isOpen(char c)`**  
  Determines whether a character is an opening bracket.

- **`isClose(char c)`**  
  Determines whether a character is a closing bracket.

- **`isMatch(char open, char close)`**  
  Checks whether the opening and closing brackets match correctly.

- **`checkBalanced(const char *expr)`**  
  Scans the expression character by character, uses the stack to match brackets, and returns whether the expression is balanced.

- **`test(const char *expr)`**  
  Displays the expression and prints the result of the balance check.

---

## (c) Organization of the `main()` Function

The `main()` function:
1. Prints the program title.
2. Calls the `test()` function with multiple test expressions.
3. Displays the result for each test case.

This structure keeps the program modular and easy to understand.

---

## (d) Sample Output

```c
Expression: a + (b - c) * (d + e)
  Push '('  → Stack: [(]
  Pop  '(' matched ')' → Stack: []
  Push '('  → Stack: [(]
  Pop  '(' matched ')' → Stack: []
Result:   BALANCED
```
