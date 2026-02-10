# Doubly Linked List Implementation

This document explains how a **doubly linked list** is implemented in C, and describes the methods to **insert a node after a given node** and **delete a node**.

---

## (a) Definition of Data Structure

### Doubly Linked List Node

```c
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
```

**Explanation:**

* `data`  : Stores the integer value of the node.
* `prev`  : Pointer to the previous node in the list.
* `next`  : Pointer to the next node in the list.

Because each node has **two links (prev and next)**, traversal is possible in **both forward and backward directions**.

A pointer to the first node is maintained:

```c
struct Node* head = NULL;
```

* `head` points to the first node; it is `NULL` if the list is empty.

---

## (b) Description of Functions Implemented

### 1. `struct Node* createNode(int data)`

**Purpose:** Creates a new node in the doubly linked list.

Working:

* Allocates memory using `malloc`.
* Stores the given `data`.
* Initializes `prev` and `next` to `NULL`.
* Returns the address of the new node.

---

### 2. `void insertAfter(struct Node* prevNode, int data)`

**Purpose:** Inserts a new node **after a given node** in the list.

Working:

1. If `prevNode` is `NULL`, insertion is not possible.
2. Create a new node.
3. Set `newNode->next = prevNode->next`.
4. Set `newNode->prev = prevNode`.
5. If `prevNode->next` is not `NULL`, update its `prev` pointer.
6. Link `prevNode->next = newNode`.

This correctly maintains both forward and backward links.

---

### 3. `void deleteNode(struct Node** head, struct Node* delNode)`

**Purpose:** Deletes a specified node from the doubly linked list.

Working:

1. If list is empty or node is `NULL`, do nothing.
2. If deleting the head node, move `head` to the next node.
3. If `delNode->prev` exists, update its `next` pointer.
4. If `delNode->next` exists, update its `prev` pointer.
5. Free the memory of `delNode`.

This safely removes the node without breaking the list.

---

### 4. `void displayForward(struct Node* head)`

**Purpose:** Displays the list from head to tail.

Working:

* Start from `head` and follow `next` pointers until `NULL` is reached.

---

## (c) Organization of `main()` Function

The `main()` function performs the following steps:

1. Creates three initial nodes: 10, 20, 30.
2. Links them to form a doubly linked list.
3. Displays the original list.
4. Inserts 25 **after node 20**.
5. Displays the updated list.
6. Deletes node 25.
7. Displays the final list.

This clearly demonstrates both insertion and deletion operations.

---

## (d) Sample Output of a Complete Run

```
Original list:
10 <-> 20 <-> 30 <-> NULL

After inserting 25 after 20:
10 <-> 20 <-> 25 <-> 30 <-> NULL

After deleting 25:
10 <-> 20 <-> 30 <-> NULL
```

---



---

## Conclusion

This program shows a clear and simple implementation of a doubly linked list, demonstrating both insertion after a given node and deletion of a node while maintaining proper forward and backward links.
