# To Build Max and Min Heap.
## Data Structure Definition

### Min-Heap:
A complete binary tree where each parent node is smaller than its children. The smallest element is at the root.

### Max-Heap:
A complete binary tree where each parent node is larger than its children. The largest element is at the root.

## Functions Implemented

### 1.swap(int *a, int *b)

Purpose: Swap two integers in the array.

### 2.maxHeapify(int arr[], int n, int i)

Purpose: Ensures subtree rooted at i satisfies max-heap property.

### 3. minHeapify(int arr[], int n, int i)

Purpose: Ensures subtree rooted at i satisfies min-heap property.

## 4.buildMaxHeap(int arr[], int n)

Purpose: Converts an unsorted array into a max-heap.

## 5. buildMinHeap(int arr[], int n)

Purpose: Converts an unsorted array into a min-heap.


### 6. printArray(int arr[], int n)

Purpose: Prints array elements in order.

## Overview of main()

Initializes an unsorted array data[].

Prints the original array.

Creates copies of the array for min-heap and max-heap.

Calls buildMinHeap() and prints the min-heap.

Calls buildMaxHeap() and prints the max-heap.

## Sample Output
```c 
Original Array: 7 2 9 1 5 3 
Min-Heap: 1 2 3 7 5 9 
Max-Heap: 9 7 3 1 5 2 
```

