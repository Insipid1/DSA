#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0, swaps = 0;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swaps++;
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                swaps++;
                arr[j+1] = arr[j];
                j--;
            } else break;
        }
        arr[j+1] = key;
    }
}

// Merge Sort helper functions
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        comparisons++;
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else { arr[k++]=R[j++]; swaps++; }
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// Print array
void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int N, choice;
    printf("Enter the number of integers: ");
    scanf("%d", &N);

    int arr[N];
    srand(time(0));

    for(int i=0;i<N;i++) arr[i] = rand()%1000 + 1;

    printf("\nOriginal array:\n");
    printArray(arr,N);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    comparisons = 0;
    swaps = 0;

    switch(choice) {
        case 1: bubbleSort(arr,N); break;
        case 2: selectionSort(arr,N); break;
        case 3: insertionSort(arr,N); break;
        case 4: mergeSort(arr,0,N-1); break;
        default: printf("Invalid choice\n"); return 0;
    }

    printf("\nSorted array:\n");
    printArray(arr,N);

    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);

    return 0;
}
