# Documentation: Reverse Traversal of a Singly Linked List (C Program)

This document explains a **simple C program** that performs **reverse traversal of a singly linked list** using recursion and demonstrates its use in `main()`.

---

## (a) Definition of Data Structures

### Linked List Node

```c
struct Node {
    int data;
    struct Node* next;
};
```

* **data**: Stores an integer value in the node.
* **next**: Pointer that holds the address of the next node in the list.

---

## (b) Description of Functions Implemented

### 1. `struct Node* createNode(int data)`

**Purpose:** Creates a new node dynamically.

---

### 2. `void insertEnd(struct Node** head, int data)`

**Purpose:** Inserts a new node at the **end** of the linked list.


---

### 3. `void traverseForward(struct Node* head)`

**Purpose:** Displays the list in forward order.


---

### 4. `void traverseReverse(struct Node* head)`

**Purpose:** Prints the linked list in **reverse order** **without modifying the list**.

Explanation:

* The function first reaches the last node by recursion.
* While returning back, it prints the data of each node.
* This results in reverse order printing.

---

## (c) Organization of `main()` Function

The `main()` function performs the following steps:

1. Initialize an empty linked list:
2. Insert some elements:
3. Display the list in forward order.
4. Call `traverseReverse(head)` to print in reverse order.

---

## **Program Output:**

```c

Reverse Traversal:
40 -> 30 -> 20 -> 10 -> NULL
```




