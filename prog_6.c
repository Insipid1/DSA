#include <stdio.h>

// to reuse
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//  Max-Heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
//min
void minHeapify(int arr[], int n, int i) {
    int smallest = i;       // Initialize smallest as root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {7, 2, 9, 1, 5, 3};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original Array: ");
    printArray(data, n);

    int minHeap[n];
    for (int i = 0; i < n; i++) minHeap[i] = data[i];
    buildMinHeap(minHeap, n);
    printf("Min-Heap: ");
    printArray(minHeap, n);

    int maxHeap[n];
    for (int i = 0; i < n; i++) maxHeap[i] = data[i];
    buildMaxHeap(maxHeap, n);
    printf("Max-Heap: ");
    printArray(maxHeap, n);

    return 0;
}
