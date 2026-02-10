# Documentation: Infix to Postfix Conversion and Evaluation (C Program)

This document explains the design and working of the C program that converts an **infix mathematical expression to postfix notation** and then **evaluates the postfix expression**.

---

## (a) Definition of Data Structures

The program uses two **stack data structures implemented using arrays**:

### 1. Character Stack
 Operators and parentheses during conversion.

### 2. Integer Stack (for Postfix Evaluation)
For Operands.

---

## Functions

### 1. Stack Operations for Character Stack

#### `void push_char(char c)`

* **Purpose:** Pushes a character (operator or parenthesis) onto the character stack.
* Used during infix to postfix conversion.

#### `char pop_char()`

* **Purpose:** Removes and returns the top character from the stack.
* Used when operators need to be moved to the postfix expression.

#### `char peek_char()`

* **Purpose:** Returns the top element of the stack **without removing it**.
* Used to compare operator precedence.

#### `int isEmptyChar()`

* **Purpose:** Checks whether the character stack is empty.
* Returns 1 if empty, 0 otherwise.

---

### 2. Stack Operations for Integer Stack

#### `void push_int(int x)`

* **Purpose:** Pushes an integer operand onto the stack during postfix evaluation.

#### `int pop_int()`

* **Purpose:** Pops and returns the top integer from the stack.
* Used when an operator is encountered in postfix expression.

---

### 3. `int Bodmas(char c)`

* **Purpose:** Returns the precedence level of an operator.
* Higher number means higher priority:

  * `^` → 3
  * `*`, `/` → 2
  * `+`, `-` → 1
  * Others → 0

This function helps maintain correct order of operations during conversion.

---

### 4. `void infixToPostfix(char infix[], char postfix[])`

**Purpose:** Converts an infix expression to postfix notation.

Working:

1. Scan the infix expression from left to right.
2. If the character is a digit → add it directly to postfix.
3. If it is `(` → push onto stack.
4. If it is `)` → pop from stack until `(` is found.
5. If it is an operator:

   * Pop operators from stack with **higher or equal precedence**.
   * Then push the current operator.
6. After scanning, pop any remaining operators from stack to postfix.



---

### 5. `int evaluatePostfix(char postfix[])`

**Purpose:** Evaluates the postfix expression and returns the result.

Working:

1. Scan postfix expression from left to right.
2. If the character is a digit → push onto integer stack.
3. If it is an operator:

   * Pop two operands (`op2` and `op1`).
   * Apply the operator: `op1 operator op2`.
   * Push the result back onto the stack.
4. After completion, the final result remains on the stack and is returned.

---

## (c) Organization of `main()` Function

The `main()` function is structured as follows:

1. **Declare two character arrays:**
2. **Read input from user:**
3. **Convert infix to postfix:**
4. **Display postfix expression.**
5. **Evaluate postfix expression and display result.**

---

##  Sample Output 

### **Output:**

```
Postfix Expression: 352*+
Evaluated Result: 13
```



