
# Implementation of Undirected Graph with BFS and DFS

This document explains how an **undirected graph** is implemented using an **adjacency matrix** in C, and describes the functions for **Breadth First Search (BFS)** and **Depth First Search (DFS)** traversal, with a `main()` function to demonstrate their use.

---

##  Definition of Data Structures

### Adjacency Matrix

```c
#define MAX 10
int adj[MAX][MAX]; //A 2D array representing the adjacency matrix.
int visited[MAX];  //An array used to mark whether a vertex has been visited during traversal.
int n; // Number of vertices in the graph.

```

---

##  Description of Functions Implemented

###  `void createGraph()`

**Purpose:** Reads the adjacency matrix from the user.

---

###  `void BFS(int start)`

**Purpose:** Performs **Breadth First Search** traversal starting from a given vertex.

Data Structure Used: **Queue (array-based)**.

Working:

1. Mark all vertices as unvisited.
2. Mark the starting vertex as visited and insert it into the queue.
3. While the queue is not empty:

   * Remove the front vertex and print it.
   * Visit all its adjacent (connected) unvisited vertices, mark them visited, and add them to the queue.

BFS explores the graph **level by level**.

---

###  `void DFS(int v)`

**Purpose:** Performs **Depth First Search** traversal starting from a given vertex.

Data Structure Used: **Recursion (system stack)**.

Working:

1. Mark the current vertex as visited and print it.
2. Recursively visit all unvisited adjacent vertices.

DFS explores the graph **as deep as possible before backtracking**.

---

##  Organization of `main()` Function

The `main()` function performs the following steps:

1. Calls `createGraph()` to read the graph.
2. Asks for a starting vertex.
3. Calls `BFS(start)` to display BFS traversal.
4. Resets the `visited[]` array.
5. Calls `DFS(start)` to display DFS traversal.

This clearly demonstrates both traversal techniques on the same graph.

---

##  Sample Output of a Complete Run (Example Graph)

### Example Graph:

```
    0 --- 1 --- 2
    |     |
    3 --- 4
```

### Corresponding Adjacency Matrix:

```
0 1 0 1 0
1 0 1 0 1
0 1 0 0 0
1 0 0 0 1
0 1 0 1 0
```

### Sample Input:

```
Enter number of vertices: 5

Enter adjacency matrix:
0 1 0 1 0
1 0 1 0 1
0 1 0 0 0
1 0 0 0 1
0 1 0 1 0

Enter starting vertex: 0
```

### Sample Output:

```
BFS Traversal: 0 1 3 2 4
DFS Traversal: 0 1 2 4 3
```

