# Sorting with User Choice of Algorithm
## Data Structure Definition

### Array (arr[N])
Stores the randomly generated integers.

Size N is provided by the user at runtime.

Each element is an integer in the range [1, 1000].

### Counters (comparisons, swaps)

comparisons keeps track of the total number of element comparisons performed during sorting.

swaps keeps track of the total number of element swaps (or movements) performed during sorting.


2. Functions Implemented

```c
bubbleSort(int arr[], int n)
Purpose: Sorts the array using the Bubble Sort algorithm.

Details: Repeatedly compares adjacent elements and swaps them if out of order. Updates comparisons and swaps.
```



```c
selectionSort(int arr[], int n)
Purpose: Sorts the array using Selection Sort.

Details: Finds the minimum element from the unsorted part and swaps it with the first unsorted element. Updates counters.
```


```c
insertionSort(int arr[], int n)
Purpose: Sorts the array using Insertion Sort.

Details: Builds the sorted array one element at a time by moving larger elements to make space for the key element. Updates counters.
```


```c 
mergeSort(int arr[], int l, int r) and merge(int arr[], int l, int m, int r)
Purpose: Sorts the array using Merge Sort.

Details: Recursively divides the array and merges sorted subarrays.
```

**printArray(int arr[], int n)**

Purpose: Prints the elements of the array in order.

3. Overview of main()

Take the number of integers N as input.

Generates N random integers in the range [1,1000] and stores them in arr[].

Prints the original array.

Displays a menu to choose a sorting algorithm:

Calls the corresponding sorting function based on the user's choice.

Prints the sorted array.

Displays the total number of comparisons and swaps performed during sorting.

## Sample Output
```c
Enter the number of integers: 6

Original array:
834 27 561 392 108 75

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 3

Sorted array:
27 75 108 392 561 834

Total comparisons: 10
Total swaps: 7```